#include "enseignant.h"

#ifdef DEBUG
#include "tests.h"
#endif

#ifdef TEST

int main() {

    // init

    char* e1_nom = "TRUILLET";
    char* e2_nom = "GAILDRAT";
    char* e1_matiere = "Structure de données";
    char* e2_matiere = "Programmation orientée objet";

    // testing

    Enseignant e = enseignant(e1_nom, e1_matiere);

    // TODO discuter du format final attendu
    test(toString(e) == "TRUILLET, Structure de données");

    test(getNom(e) == e1_nom);
    test(getMatiere(e) == e1_matiere);

    setNom(e, e2_nom);
    setMatiere(e, e2_matiere);

    test(getNom(e) == e2_nom);
    test(getMatiere(e) == e2_matiere);

    test(toString(e) == "GAILDRAT, Programmation orientée objet");

    return 0;
}

#endif