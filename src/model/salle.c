#include "salle.h"
#include "creneau.h"
#include "horaire.h"
#include <stdbool.h>


#ifdef DEBUG
#include "tests.h"
#endif

struct s_salle{
    char * nom;
    Creneau creneaux[24];
};

Salle salle(int n){
    Salle s= (Salle)malloc(sizeof(struct s_salle));
    s->nom=n;
    for(int i=0; i<10; i++){
        s->creneaux[i]="NULL";
    }
    return s;
}

bool isFreeSalle(Salle s, Horaire h){
    bool b=true;
    for (int i=0; i<10; i++){
        if(getDebut(h)==getDebut(s->creneaux[i]->horaire) & b){
            if(getFin(h)==getFin(s->creneaux[i]->horaire)){
                b=false;
            }
        }
    }
    return b;
}



Salle ajouterS(Salle s, Creneau c){
    if(isFreeSalle(s,c->horaire)){
        for(int i=getdebut(s->creneaux[i]->horaire); i<geFin(s->creneaux[i]->horaire);i++){
            s->creneaux[i]=c;
        }
    }
    return s;
}

Salle modifierS(Salle s,Horaire hmodif, Horaire hnew){

}

Salle supprimerS()



#ifdef TEST

int main() {

    // init

    char* s1_nom = "103";
    char* s2_nom = "118";

    Horaire h1 = horaire(7, 9);
    Horaire h2 = horaire(15, 17);

    Creneau c1 = creneau(enseignant("TRUILLET", "Structure de données"), h1, "CUPGE", s1_nom);
    Creneau c2 = creneau(enseignant("GAILDRAT", "Programmation orientée objet"), h2, "CUPGE", s2_nom);

    // testing

    Salle s = salle(s1_nom);

    assert(ajouterCreneauSalle(c2)); // devrait produire une erreur
    test(isFreeSalle(s) == true);

    assert(ajouterCreneauSalle(c1));
    test(isFreeSalle(s) == false);

    test(toStringSalle(s) == "");

    modifierCreneauSalle(c1, h1, h2);

    // TODO finir test toString
    test(toStringSalle(s) == "");

    test(isFreeSalle(s, h1) == true);
    test(isFreeSalle(s, h2) == false);

    test(isEmptySalle(s) == false);

    supprimerCreneauSalle(c1, h2);

    test(isFreeSalle(s, h2) == true);

    test(isEmptySalle(s) == true);

    test(toStringSalle(s) == "pas de créneau disponible pour la salle " + s1_nom);

    return 0;
}

#endif