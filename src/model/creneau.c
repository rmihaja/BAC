#include "creneau.h"

#ifdef DEBUG
#include "tests".h
#endif

#ifdef TEST

int main() {

    // init

    Enseignant e1 = enseignant("TRUILLET", "Structure de données");
    Enseignant e2 = enseignant("GAILDRAT", "Programmation orientée objet");
    Horaire h1 = horaire(13, 15);
    Horaire h2 = horaire(16, 18);
    char* f1 = "L2 Informatique";
    char* f2 = "CUPGE";
    char* s1 = "108";
    char* s2 = "118";

    // testing

    Creneau c = creneau(e1, h1, f1, s1);

    // TODO définir format toString
    test(toString(c) == "");

    test(getNom(getEnseignant(c)) == getNom(e1));
    test(getDebut(getHoraire(c)) == getDebut(h1));
    test(getFormation(c) == f1);
    test(getSalle(c) == s1);

    setCreneau(c, e2, h2, f2, s2);

    test(getMatiere(getEnseignant(c)) == getMatiere(e2));
    test(getFin(getHoraire(c)) == getFin(h2));
    test(getFormation(c) == f2);
    test(getSalle(c) == s2);

    test(toString(c) == "");

    return 0;
}

#endif