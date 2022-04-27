#include "salle.h"
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>


#ifdef DEBUG
#include "tests.h"
#endif

struct s_salle{
    char * nom;
    Creneau creneaux[24];
};

Salle salle(char * n){
    Salle s= (Salle)malloc(sizeof(struct s_salle));
    s->nom=n;
    for(int i=0; i<24; i++){
        s->creneaux[i]=NULL;
    }
    return s;
}

bool isFreeSalle(Salle s, Horaire h){
    bool b;
    for (int i=getDebut(h); i<getFin(h); i++){
        if(s->creneaux[i]==NULL){
            b=true;
        }else{
            b=false;
        }
    }
    return b;
}

Salle ajouterS(Salle s, Creneau c){
    if(isFreeSalle(s,getH(c))){
        for(int i=getDebut(getH(s->creneaux[i])); i<getFin(getH(s->creneaux[i]));i++){
            s->creneaux[i]=c;
        }
    }
    return s;
}

bool estVideSalle(Salle s){
    bool b=true;
    int i=8;
    while(i<21 && s->creneaux[i]==NULL){
        i++;
    }
    if(s->creneaux[i]!=NULL){
        b=false;
    }
    return b;
}

Salle supprimerS(Salle s, Horaire h){
    assert(estVideSalle(s));
    for(int i=getDebut(h); i<=getFin(h); i++){
        s->creneaux[i]=NULL;
    }
    return s;
}

Salle modifierS(Salle s,Horaire hmodif, Creneau cnew){
    supprimerS(s,hmodif);
    ajouterS(s,cnew);
    return s;
}


void afficherSalle(Salle s){
    printf("    Salle%c     \n", s->nom);
    for(int i=8;i<21;i++){
        printf("\n");
        if(s->creneaux[i]==NULL){
            printf("\n VIDE \n");
        }else{
            afficheHoraire(getH(s->creneaux[i]));
            afficheEnseignant(getE(s->creneaux[i]));
            printf("%d", getF(s->creneaux[i]));
        }
        printf("___");
    }
}


#ifdef TEST

int main() {

    // init

    char* s1_nom = "103";
    char* s2_nom = "118";

    Horaire h1 = horaire(8, 9);
    Horaire h2 = horaire(15, 17);

    Creneau c1 = creneau(enseignant("TRUILLET", "Structure de données"), h1, "CUPGE", s1_nom);
    Creneau c2 = creneau(enseignant("GAILDRAT", "Programmation orientée objet"), h2, "CUPGE", s2_nom);

    // testing

    Salle s = salle(s1_nom);

    assert(ajouterS(s,c2));
    test(isFreeSalle(s,h1) == true);

    assert(ajouterS(s,c1));
    test(isFreeSalle(s,h1) == false);

    modifierS(s, h1, c2);

    test(isFreeSalle(s, h1) == true);
    test(isFreeSalle(s, h2) == false);

    test(estVideSalle(s) == false);

    supprimerS(s, h2);

    test(isFreeSalle(s, h2) == true);

    test(estVideSalle(s) == true);

    return 0;
}

#endif