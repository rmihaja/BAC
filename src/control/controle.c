// ? structure modèle de toutes les modules du projet
#include <stdbool.h>
#include <assert.h>
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
    //if(no json)
    c->isAdmin=false;
    c->enseignants=enseignants();
    c->salles=salles();
    ajouterSs(c->salles,salle(1));
    ajouterSs(c->salles,salle(2));
    ajouterSs(c->salles,salle(3));
    c->formations[0]=formation(CUPGE chimie);
    c->formations[1]=formation(CUPGE physique);
    c->formations[2]=formation(CUPGE informatique);
    return c;
}

Controle reserver(Controle Ct, Creneau c){
    assert(Ct->isAdmin);
    assert(c!=NULL);
    Salle s=getSalle(Ct->salles,getS(c));
    ajouterS(s,c);

}

Controle annuler(Controle Ct, Creneau c){

}

Controle modifier(Controle Ct, Creneau c){

}

void afficherEDTEnseignants(Controle Ct, Enseignant e){
    printf("-------\n");
    printf("Enseignant : %s\n", getNom(e));
    printf("- %s -\n", getMatiere(e));
    printf("-------\n\n");
    for(int i=0; i<getnbr(Ct->salles);i++){
        Salle courant=getSalle(getNomSParIndice(Ct->salles,i));
        for(int j=8; j<20; j++){
            if(getE(getCreneauS(courant))==e){
                printf("%s %s \n", getS(c), getF(c));
                printf("De ")
                afficheHoraire(getH(c));
            }
        }
    }
}




#ifdef TEST

int main() {

    // init

    // testing

    return 0;
}

#endif