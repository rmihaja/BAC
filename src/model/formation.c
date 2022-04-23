#include "formation.h"

#ifdef DEBUG
#include "tests.h"
#endif

// attributs, constructor, methods here

#ifdef TEST

int main() {

    // init

    Horaire h1 = horaire(13, 15);
    Enseignant e1 = enseignant("TRUILLET", "Structure de données");
    char* f1_nom = "CUPGE";
    char* s1 = "118";

    Horaire h2 = horaire(16, 18);
    Enseignant e2 = enseignant("GAILDRAT", "Programmation orientée objet");
    char* f2_nom = "L2 Informatique";
    char* s2 = "103";

    Creneau c1 = creneau(e1, h1, f1_nom, s1);
    Creneau c1_bis = creneau(e2, h1, f1_nom, s2);
    Creneau c2 = creneau(e2, h2, f2_nom, s2);

    // testing

    Formation f = formation(f1_nom);

    ajouterCreneauFormation(f, c2); // devrait produire une erreur

    ajouterCreneauFormation(c1);

    // TODO finir test toString
    test(toStringFormation(f) == "");

    ajouterCreneauFormation(f, c1_bis); // devrait produire une erreur

    ajouterCreneauFormation(f, c1);
    ajouterCreneauFormation(f, c1);
    ajouterCreneauFormation(f, c1);

    test(isFullFormation(f) == false);

    supprimerCreneauFormation(f, h2); // devrait produire une erreur

    supprimerCreneauFormation(f, h1);
    test(toStringFormation(f) == "pas de créneau pour la formation " + f1_nom);

    return 0;
}

#endif