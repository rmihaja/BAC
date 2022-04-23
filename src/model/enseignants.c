#include "enseignants.h"

#ifdef DEBUG
#include "tests.h"
#endif

// attributs, constructor, methods here

#ifdef TEST

int main() {

    // init

    char* e1_nom = "TRUILLET";
    char* e2_nom = "GAILDRAT";

    Enseignant e1 = enseignant(e1_nom, "Structure de données");
    Enseignant e2 = enseignant(e2_nom, "Programmation orientée objet");

    // testing

    Enseignants E = enseignants();

    test(toStringEnseignants(E) == "");

    ajouterEnseignant(E, e1);
    test(getEnseignant(E, e1_nom) == e1);
    assert(ajouterEnseignant(E, e1)); // devrait produire une erreur

    ajouterEnseignant(E, e2);
    test(getNom(getEnseignant(E, e2_nom)) == getNom(e2));

    supprimerEnseignant(E, e1_nom);
    assert(getEnseignant(E, e1_nom)); // devrait produire une erreur
    test(getEnseignant(E, e2_nom) == e2);

    test(toStringEnseignants(E) == toStringEnseignant(e2));

    return 0;
}

#endif