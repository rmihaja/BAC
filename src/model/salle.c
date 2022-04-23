#include "salle.h"

#ifdef DEBUG
#include "tests.h"
#endif

// attributs, constructor, methods here

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