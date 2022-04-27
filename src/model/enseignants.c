#include "enseignants.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef DEBUG
#include "tests.h"
#endif

struct s_enseig{
    Enseignant e;
    Enseignant * suivant;
};

struct s_enseignants{
    Enseig enseignants;
    int taille;
};

Enseignants enseignants(){
    Enseignants es= (Enseignants) malloc(sizeof(struct s_enseignants));
    es->enseignants="NULL";
    es->taille=0;
    return es;
}

Enseig enseig(Enseignant e){
    Enseig g=(Enseig) malloc(sizeof(struct s_enseig));
    g->e=e;
    g->suivant="NULL";
    return g;
}

Enseignants ajouterEs(Enseignant g, Enseignants es){
    Enseig e=enseig(g);
    if(es->taille==0){
        es->enseignants=e;
        es->taille=1;
    }else{
        if(!appartient(e,es)){
            e->suivant=es->enseignants;
            es->enseignants=e;
            es->taille++;
        }
    }
    return es;
}

bool appartient(Enseignant g, Enseignants es){
    Enseig e=enseig(g)
    char* b= "false";
    Enseig courant= es->enseignants;
    for(int i=0; i<es->taille-1; i++){
        if((getNom(courant->e) != getNom(e->e)) && (getMatiere(courant->e) != getMatiere(e->e)) && !b){
            b= "true";
        }
        courant=courant->suivant;
    }
    free(courant);
    return b;
}

Enseignants supprimerEs(Enseignant g, Enseignants es){
    assert(!es->taille==0);
    Enseig e =enseig(g);
    if((getNom(g)==getNom(es->enseignants->e)) && (getMatiere(g)==getMatiere(es->enseignants->e))){
        e->suivant=es->enseignants->suivant;
        es->enseignants=e;
    }else{
        Enseig precedent = es->enseignants;
        Enseig courant = es->enseignants->suivant;
        int i=0;
        while((getNom(courant->e) != getNom(g)) && (getMatiere(courant->e) != getMatiere(g)) && (i<es->taille-1)){
            precedent=courant;
            courant=courant->suivant;
            i++;        
        }
        e->suivant=courant->suivant;
        precedent->suivant=e;
        free(courant);
        free(precedent);
    }
    es->taille--;
    return es;
}

void AfficherEnseignants (Enseignants es){
    printf("******* Enseignants *******");
    Enseig courant = es->enseignants;
    for(int i=0; i<es->taille;i++){
        printf("%s\n", toStringEnseignant(courant->e));
        courant=courant->suivant;
    }
    printf("***************************");
}

Enseignant getEnseignantN(Enseignants es, char *n){
    bool b=false;
    Enseignant e;
    Enseig courant = es->enseignants;
    for(int i=0; i<es->taille; i++){
        if(n==getNom(courant->e) && !b){
            b= true;
            e=courant->e;
        }
        courant=courant->suivant;
    }
    return e;
}

Enseignant getEnseignantM(Enseignants es, char *m){
    bool b=false;
    Enseignant e;
    Enseig courant = es->enseignants;
    for(int i=0; i<es->taille; i++){
        if(m==getMatiere(courant->e) && !b){
            b= true;
            e=courant->e;
        }
        courant=courant->suivant;
    }
    return e;
}
