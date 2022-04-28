#include "salles.h"

#ifdef DEBUG
#include "tests.h"
#endif

struct s_salles{
    int nbr;
    Sal salles;
};

struct s_sal{
    Salle s;
    Salle suivante;
};

Salles salles (){
    Salles s=(Salles) malloc(sizeof(struct s_salles));
    s->salle="NULL";
    s->nbr=0;
    return s;
}

Sal sal(Salle s){
    Sal l=(Sal) malloc(sizeof(struct s_sal));
    l->s=s;
    l->suivante="NULL";
    return l;
}

Salles ajouterSs(Salles Ss, Salle a){
    Sal s=sal(a);
    if(Ss->nbr==0){
        Ss->salles=s;
        Ss->nbr=1;
    }else{
        s->suivante=Ss->salles;
        Ss->salles=s;
        Ss->nbr++;
    }
    return Ss;
}

Salle getSalle(Salles Ss, char* salle){
    Salle r=salle(0);
    for(int i=0;i<Ss->nbr;i++){
        if(Ss->salles[i]->s->nom==salle){
            r=Ss->salles[i]->s;
        }
    }
    return r;
}

void afficheSalles(Salles Ss){
    for(int i=0;i<Ss->nbr;i++){
        afficherSalle(Ss->salles[i]);
        printf("*********************");
    }
}

#ifdef JSON
json_t* getJsonSalles(Salles Ss) {

    json_t *root = json_object();
    json_t *json_arr = json_array();

    json_object_set_new(root, "salles", json_arr);

    // TODO à finir
    // json_array_append(json_arr, getJsonSalle());

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

int main() {

    // init

    char* s1_nom = "118";
    char* s2_nom = "103";

    Salle s1 = salle(s1_nom);
    Salle s2 = salle(s2_nom);

    // testing

    Salles S = salles();

    test(toStringSalles(S) == "");

    info(getSalle(S, s1_nom)); // devrait produire une erreur

    info(ajouterSalle(S, s1));
    test(getSalle(S, s1_nom) == s1);
    info(ajouterSalle(S, s1)); // devrait produire une erreur

    test(toStringSalles(S) == toStringSalle(s1));

    info(ajouterSalle(S, s2));
    test(getSalle(S, s2_nom) == s2);
    test(getSalle(S, s1_nom) == s1);

    info(afficheSalles(S));

    #ifdef JSON
    info(toStringSalles(S));
    #endif

    return 0;
}

#endif