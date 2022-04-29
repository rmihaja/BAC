#include "salle.h"
#include <assert.h>
#include <stdlib.h>

#ifdef DEBUG
#include "tests.h"
#endif

struct s_salle{
    char * nom;
    Creneau creneaux[24];
};

Salle salle(char * n){
    Salle s= (Salle)malloc(sizeof(struct s_salle));
    s->nom=n;
    for(int i=0; i<24; i++){
        s->creneaux[i]=NULL;
    }
    return s;
}

#ifdef JSON
Salle salleParser(json_t *json_salle) {
    json_t *nom = json_object_get(json_salle, "nom");
    json_t *json_arr_c = json_object_get(json_salle, "creneaux");

    assert(json_is_string(nom) && json_is_array(json_arr_c));

    Salle s = salle((char*) json_string_value(nom));

    size_t index;
    json_t *value;
    // ? https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_foreach
    json_array_foreach(json_arr_c, index, value) {
        if(!json_is_null(value)) {
            ajouterS(s, creneauParser(value));
        }
    }

    return s;
}
#endif

bool isFreeSalle(Salle s, Horaire h){
    bool b = true;
    for (int i=getDebut(h); i<getFin(h) && b; i++){
        b = s->creneaux[i] == NULL;
    }
    return b;
}

Salle ajouterS(Salle s, Creneau c){
    if(isFreeSalle(s,getH(c))){
        for(int i=getDebut(getH(c)); i<getFin(getH(c));i++){
            s->creneaux[i] = c;
        }
    }
    return s;
}

bool estVideSalle(Salle s){
    return isFreeSalle(s, horaire(8, 20));
}

Salle supprimerS(Salle s, Horaire h){
    assert(!estVideSalle(s));
    for(int i=getDebut(h); i<=getFin(h); i++){
        s->creneaux[i]=NULL;
    }
    return s;
}

Salle modifierS(Salle s,Horaire hmodif, Creneau cnew){
    supprimerS(s,hmodif);
    ajouterS(s,cnew);
    return s;
}

char* getNomS(Salle s){
    return s->nom;
}

Creneau* getCreneauS(Salle s){
    return s->creneaux;
}


void afficherSalle(Salle s){
    printf("-------\n");
    printf("Salle : %s\n", s->nom);
    printf("-------\n\n");
    for(int i=8;i<20;i++){
        printf("de ");
        afficheHoraire(horaire(i, i+1));
        if(s->creneaux[i]==NULL){
            printf("VIDE");
        }else{
            afficheEnseignant(getE(s->creneaux[i]));
            printf("%s", getF(s->creneaux[i]));
        }
        printf("\n\n");
    }
}

#ifdef JSON
json_t* getJsonSalle(Salle s) {

    json_t *root = json_object();
    json_t *json_arr = json_array();

    json_object_set_new(root, "nom", json_string(s->nom));
    json_object_set_new(root, "creneaux", json_arr);

    for(int i = 0; i < 24; i++) {
        json_array_append(json_arr, getJsonCreneau(s->creneaux[i]));
        if(s->creneaux[i] == NULL) {
            json_array_append(json_arr, json_null());
        } else {
            json_array_append(json_arr, getJsonCreneau(s->creneaux[i]));
        }
    }

    return root;
}

char* toStringSalle(Salle f) {

    json_t *json_salle = getJsonSalle(f);
    char *str = json_dumps(json_salle, 0);

    #ifdef DEBUG
    puts(str);
    #endif

    // deallocation json object memory
    json_decref(json_salle);

    return str;
}
#endif

#ifdef TEST
#include <string.h>

int main() {

    // init

    char* s1_nom = "103";
    char* s2_nom = "118";

    Horaire h1 = horaire(8, 9);
    Horaire h2 = horaire(15, 17);

    Creneau c1 = creneau(enseignant("TRUILLET", "Structure de données"), h1, "CUPGE", s1_nom);
    Creneau c2 = creneau(enseignant("GAILDRAT", "Programmation orientée objet"), h2, "CUPGE", s2_nom);

    // testing

    Salle s = salle(s1_nom);

    info(ajouterS(s,c2));
    test(isFreeSalle(s,h1) == true);

    info(ajouterS(s,c1));
    test(isFreeSalle(s,h1) == false);

    info(afficherSalle(s));

    info(modifierS(s, h1, c2));

    test(isFreeSalle(s, h1) == true);
    test(isFreeSalle(s, h2) == false);

    test(estVideSalle(s) == false);

    info(supprimerS(s, h2));

    test(isFreeSalle(s, h2) == true);

    test(estVideSalle(s) == true);

    info(afficherSalle(s));

    #ifdef JSON
    info(ajouterS(s,c2));
    test(strcmp(toStringSalle(s), toStringSalle(salleParser(getJsonSalle(s)))) == 0);
    #endif

    return 0;
}

#endif