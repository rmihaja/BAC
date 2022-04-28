#include "collections/creneau.h"
#include "types/formation.h"
#include <stdbool.h>

struct s_formation {
    char * nom;
    Creneau creneau[4];
};

Formation formation(char* n){
    Formation f=(Formation)malloc(sizeof(struct s_formation));
    f->nom=n;
    for (int i=0; i<4 ;i++){
        f->creneau[i]="NULL";
    }
    return f;
}

bool estComplet(Formation f){
    bool b=true;
    for(int i=0;i<4;i++){
        if(f->creneau[i]=="NULL" && b){
            b=false;
        }
    }
    return b;
}

Formation ajouterC(Formation f, Creneau c){
    assert(!estComplet(f));
    for(int i=0; i<4; i++){

    }
}

Formation supprimerH (Formation f, Horaire h){
    for(int i=0; i<4; i++){
        if(f->creneau[i]->horaire==h){
            f->creneau[i]="NULL";
        }
    }
    return f;
}

#ifdef JSON
// TODO à tester
json_t* getJsonFormation(Formation f) {

    json_t *root = json_object();
    json_t *json_arr = json_array();

    json_object_set_new(root, "nom", json_string(f->nom));
    json_object_set_new(root, "creneaux", json_arr);

    for(int i = 0; i < 4; i++) {
        json_array_append(json_arr, getJsonCreneau(f->creneau[i]));
    }

    return root;
}

char* toStringFormation(Formation f) {

    json_t *json_formation = getJsonFormation(f);
    char *str = json_dumps(json_formation, 0);

    #ifdef DEBUG
    puts(str);
    #endif

    // deallocation json object memory
    json_decref(json_formation);

    return str;
}
#endif