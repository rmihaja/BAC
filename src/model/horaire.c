#include "horaire.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifdef DEBUG
#include "tests.h"
#endif

struct s_horaire{
    int debut;
    int fin;
};

Horaire horaire(int d, int f){
    assert(7<d && d<20 && 8<f && f<21);
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

void affiche1H(int i){
    printf("%dh00\n", i);
}

void afficheHoraire(Horaire h){
    printf("%dh00 à %dh00\n",getDebut(h),getFin(h));
}

#ifdef JSON
json_t* getJsonHoraire(Horaire h) {

    json_t *root = json_object();

    json_object_set_new(root, "debut", json_integer(getDebut(h)));
    json_object_set_new(root, "fin", json_integer(getFin(h)));

    return root;
}

char* toStringHoraire(Horaire h) {

    json_t *json_horaire = getJsonHoraire(h);
    char* str = json_dumps(json_horaire, 0);

    #ifdef DEBUG
    puts(str);
    #endif

    // deallocate json object memory
    json_decref(json_horaire);

    return str;
}
#endif

#ifdef TEST

int main() {

    // init

    int h1_debut = 8;
    int h2_debut = 15;
    int h1_fin = 10;
    int h2_fin = 18;

    // testing

    Horaire h = horaire(h1_debut, h1_fin);

    test(duree(h) > 0);

    test(getDebut(h) == h1_debut);
    test(getFin(h) == h1_fin);

    info(setDebut(h, h2_debut));
    info(setFin(h, h2_fin));

    test(getDebut(h) == h2_debut);
    test(getFin(h) == h2_fin);

    test(duree(h) == h2_fin - h2_debut);

    info(affiche1H(duree(h)));
    info(afficheHoraire(h));

    #ifdef JSON
    info(toStringHoraire(h));
    #endif

    return 0;
}

#endif