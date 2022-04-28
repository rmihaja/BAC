#include "formation.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct s_edt{
    Creneau creneau;
    Creneau* suivant;
}*Edt;

struct s_formation {
    char * nom;
    Edt edt;
    int nbr;
};


Formation formation(char* n){
    Formation f=(Formation)malloc(sizeof(struct s_formation));
    Edt edt=malloc(sizeof(sizeof(struct s_edt)));
    f->edt->suivant=edt;
    f->nom=n;
    f->nbr=0;
    return f;
}

Edt edt(Formation f, Creneau c){
    Edt e=(Edt)malloc(sizeof(struct s_edt));
    e->creneau=c;
    e->suivant=f->edt;
    edt->suivant=e;
}

bool estComplet(Formation f){
    if(nbr==4){
        return true;
    }else{
        return false;
    }
}

Formation ajouterC(Formation f, Creneau c){
    assert(!estComplet(f));
    Edt e=edt(c);
    if(f->nbr==0){
        f->edt=e;
        f->nbr=1;
    }else{
        e->suivant=f->edt;
        f->edt=e;
        f->nbr++;
    }
    return f;
}

Formation supprimerH (Formation f, Horaire h){
    assert(f->nbr!=0);
    Edt precedent=f->edt;
    Edt courant=f->edt->suivant;
    int i=0;
    while(i<f->nbr && getH(courant->creneau)!=h){
        precedent=courant;
        courant=courant->suivant;
        i++;
    }
    if(i!=f->nbr){
        precedent->suivant=courant->suivant;
    }
    free(courant);
    return f;
}


void afficheFormation(Formation f){
    printf("    %s     \n", f->nom);
    for(int i=0;i<4;i++){
        printf("\n");
        if(s->creneaux[i]==NULL){
            printf("\n VIDE \n");
        }else{
            printf("%d", getS(s->creneaux[i]));
            afficheHoraire(getH(s->creneaux[i]));
            afficheEnseignant(getE(s->creneaux[i]));
        }
        printf("___");
    }
}


