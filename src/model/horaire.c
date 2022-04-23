#include "horaire.h"

#ifdef DEBUG
#include "tests.h"
#endif

#ifdef TEST

int main() {

    // init

    unsigned int h1_debut = 8;
    unsigned int h2_debut = 15;
    unsigned int h1_fin = 10;
    unsigned int h2_fin = 18;

    // testing

    Horaire h = horaire(h1_debut, h1_fin);

    test(toString(h) == "8h00 à 10h00")
    test(duree(h) > 0);

    test(getDebut(h) == h1_debut);
    test(getFin(h) == h1_fin);

    setDebut(h, h2_debut);
    setFin(h, h2_fin);

    test(getDebut(h) == h2_debut);
    test(getFin(h) == h2_fin);

    test(duree(h) == h2_fin - h2_debut);
    test(toString(h) == "15h00 à 18h00")

    return 0;
}

#endif