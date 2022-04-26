#include "../../include/collections/creneau.h"
#include "formation.h"

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

Formation supprimerH (Formation f, Horaire h){
    
}