#include "salles.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef DEBUG
#include "tests.h"
#endif

typedef struct s_sal{
    Salle s;
    struct s_sal *suivante;
}* Sal;

struct s_salles{
    int nbr;
    Sal salles;
};

Salles salles (){
    Salles Ss=(Salles) malloc(sizeof(struct s_salles));
    Ss->salles=(Sal) malloc(sizeof(struct s_sal));
    Ss->salles->suivante = Ss->salles;
    Ss->nbr=0;
    return Ss;
}

#ifdef JSON
Salles sallesParser(json_t* json_salles) {
    json_t *json_arr_s = json_object_get(json_salles, "salles");

    assert(json_is_array(json_arr_s));

    Salles Ss = salles();

    size_t index;
    json_t *value;
    // ? https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_foreach
    json_array_foreach(json_arr_s, index, value) {
        ajouterSs(Ss, salleParser(value));
    }

    return Ss;
}
#endif

Sal sal(Salle s){
    Sal l=(Sal) malloc(sizeof(struct s_sal));
    l->s=s;
    l->suivante=NULL;
    return l;
}

Salles ajouterSs(Salles Ss, Salle a){
    Sal s=sal(a);
    s->suivante=Ss->salles->suivante;
    Ss->salles->suivante=s;
    Ss->nbr++;
    return Ss;
}

Salle getSalle(Salles Ss, char* nom){
    Salle r=NULL;
    Sal courant=Ss->salles->suivante;
    for(int i=0;i<Ss->nbr;i++){
        if(getNomS(courant->s)==nom){
            r=courant->s;
        }
        courant=courant->suivante;
    }
    return r;
}

char * getNomSParIndice(Salles Ss, int n){
    assert(n<Ss->nbr);
    Salle r=NULL;
    Sal courant=Ss->salles->suivante;
    for(int i=0;i<n;i++){
        courant=courant->suivante;
    }
    return getNomS(courant->s);
}

int getnbr(Salles Ss){
    return Ss->nbr;
}

void afficheSalles(Salles Ss){
    Sal courant=Ss->salles->suivante;
    for(int i=0;i<Ss->nbr;i++){
        afficherSalle(courant->s);
        courant=courant->suivante;
    }
}

#ifdef JSON
json_t* getJsonSalles(Salles Ss) {

    json_t *root = json_object();
    json_t *json_arr = json_array();

    json_object_set_new(root, "salles", json_arr);

    Sal courant = Ss->salles->suivante;
    for(int i = 0; i < Ss->nbr; i++) {
        json_array_append(json_arr, getJsonSalle(courant->s));
        courant = courant->suivante;
    }

    return root;
}

char* toStringSalles(Salles Ss) {

    json_t *json_salles = getJsonSalles(Ss);
    char *str = json_dumps(json_salles, 0);

    #ifdef DEBUG
    puts(str);
    #endif

    // deallocation json object memory
    json_decref(json_salles);

    return str;
}
#endif

#ifdef TEST
#include <string.h>

int main() {

    // init

    char* s1_nom = "118";
    char* s2_nom = "103";

    Salle s1 = salle(s1_nom);
    Salle s2 = salle(s2_nom);

    // testing

    debug("dfs");
    Salles S = salles();

    // info(getSalle(S, s1_nom)); // devrait produire une erreur

    info(ajouterSs(S, s1));
    test(getSalle(S, s1_nom) == s1);
    // info(ajouterSs(S, s1)); // devrait produire une erreur

    info(ajouterSs(S, s2));
    test(getSalle(S, s2_nom) == s2);
    test(getSalle(S, s1_nom) == s1);

    info(afficheSalles(S));

    #ifdef JSON
    test(strcmp(toStringSalles(S), toStringSalles(sallesParser(getJsonSalles(S)))) == 0);
    #endif

    return 0;
}

#endif