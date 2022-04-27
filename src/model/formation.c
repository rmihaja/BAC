#include "collections/creneau.h"
#include "formation.h"
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


