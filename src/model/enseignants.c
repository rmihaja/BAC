#include "enseignants.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifdef DEBUG
#include "tests.h"
#endif

typedef struct s_enseig{
    Enseignant e;
    struct s_enseig* suivant;
}*Enseig;

struct s_enseignants{
    Enseig sentinelle;
    int taille;
};

Enseignants enseignants(){
    Enseignants es= (Enseignants) malloc(sizeof(struct s_enseignants));
    es->sentinelle=(Enseig)malloc(sizeof(struct s_enseig));
    es->sentinelle->suivant=es->sentinelle;
    es->taille=0;
    return es;
}

Enseig enseig(Enseignant e, Enseignants es){
    Enseig g=(Enseig) malloc(sizeof(struct s_enseig));
    g->e=e;
    g->suivant=es->sentinelle;
    return g;
}

Enseignants ajouterEs(Enseignant g, Enseignants es){
    Enseig e=enseig(g,es);
    if(!appartient(g,es)){
        e->suivant = es->sentinelle->suivant;
        es->sentinelle->suivant=e;
        es->taille++;
    }
    return es;
}

bool appartient(Enseignant g, Enseignants es){
    Enseig e=enseig(g,es);
    bool b= false;
    Enseig courant= es->sentinelle->suivant;
    // TODO Mihaja check infinite loop
    for(int i=0; i<es->taille-1; i++){
        if((getNom(courant->e) != getNom(e->e)) && (getMatiere(courant->e) != getMatiere(e->e)) && !b){
            b= true;
        }
        courant=courant->suivant;
    }
    free(courant);
    return b;
}

Enseignants supprimerEs(Enseignant g, Enseignants es){
    assert(!es->taille==0);
    Enseig e =enseig(g,es);
    Enseig precedent = es->sentinelle;
    Enseig courant = es->sentinelle->suivant;
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
    es->taille--;
    return es;
}

void afficherEnseignants (Enseignants es){
    printf("******* Enseignants *******");
    Enseig courant = es->sentinelle->suivant;
    for(int i=0; i<es->taille;i++){
        afficheEnseignant(courant->e);
        courant=courant->suivant;
    }
    printf("***************************");
}

Enseignant getEnseignantN(Enseignants es, char *n){
    bool b=false;
    Enseignant e;
    Enseig courant = es->sentinelle->suivant;
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
    Enseig courant = es->sentinelle->suivant;
    for(int i=0; i<es->taille; i++){
        if(m==getMatiere(courant->e) && !b){
            b= true;
            e=courant->e;
        }
        courant=courant->suivant;
    }
    return e;
}


#ifdef TEST

int main() {

    char* e1_nom = "TRUILLET";
    char* e2_nom = "GAILDRAT";
    char* e1_matiere = "Structure de données";
    char* e2_matiere = "Programmation orientée objet";
    Enseignant e1 = enseignant(e1_nom, e1_matiere);
    Enseignant e2 = enseignant(e2_nom, e2_matiere);

    Enseignants es = enseignants();

    test(ajouterEs(e1,es));
    test(ajouterEs(e2,es));

    test(supprimerEs(e1,es));
    test(getEnseignantN(es,"GAILDRAT") == e2);
    test(getEnseignantM(es,"Programmation orientée objet") == e2);

    afficherEnseignants (es);


    return 0;
}

#endif 