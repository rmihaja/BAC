#include "horaire.h"

#ifdef DEBUG
#include "tests.h"
#endif

struct s_horaire{
    int debut;
    int fin;
};

Horaire horaire(int d, int f){
    assert(7<d<20 && 8<f<21);
    Horaire h= (Horaire)malloc(sizeof(struct s_horaire));
    h->debut=d;
    h->fin=f;
    return h;
}

int getDebut(Horaire h){
    return h->debut;
}

int getFin(Horaire h){
    return h->fin;
}

Horaire setDebut(Horaire h, int d){
    h->debut=d;
    return h;
}

Horaire setFin(Horaire h, int f){
    h->fin=f;
    return h;
}

int duree(Horaire h){
    return (h->fin - h->debut);
}

void Affiche1H(int i){
    printf("%dh00", i);
}

void AfficheHoraire(Horaire h){
    printf("%dh00 à %dh00",h->debut,h->fin);
}



#ifdef TEST

int main() {

    // init

    unsigned int h1_debut = 8;
    unsigned int h2_debut = 15;
    unsigned int h1_fin = 10;
    unsigned int h2_fin = 18;

    // testing

    Horaire h = horaire(h1_debut, h1_fin);

    test(toStringHoraire(h) == "8h00 à 10h00")
    test(duree(h) > 0);

    test(getDebut(h) == h1_debut);
    test(getFin(h) == h1_fin);

    setDebut(h, h2_debut);
    setFin(h, h2_fin);

    test(getDebut(h) == h2_debut);
    test(getFin(h) == h2_fin);

    test(duree(h) == h2_fin - h2_debut);
    test(toStringHoraire(h) == "15h00 à 18h00")

    return 0;
}

#endif