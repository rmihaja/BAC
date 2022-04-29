// ? structure modèle de toutes les modules du projet
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "controle.h"


#ifdef DEBUG
#include "tests.h"
#endif

//afficheEnseignants existe déjà dans enseignants
//pareil pour salles, salle, formation

struct s_controle{
    bool isAdmin;
    Enseignants enseignants;
    Salles salles;
    Formation formations[3];
};

Controle controle(){
    Controle c=(Controle)malloc(sizeof(struct s_controle));
    c->isAdmin=false;
    c->enseignants=enseignants();
    c->salles=salles();
    c->formations[0]=formation(CUPGE chimie);
    c->formations[1]=formation(CUPGE physique);
    c->formations[2]=formation(CUPGE informatique);
    return c;
}

Controle reserver(Controle Ct, Creneau c){

}

Controle annuler(Controle Ct, Creneau c){

}

Controle modifier(Controle Ct, Creneau c){

}

void afficherEDTEnseignants(Controle Ct, Enseignant e){

}




#ifdef TEST

int main() {

    // init

    // testing

    return 0;
}

#endif