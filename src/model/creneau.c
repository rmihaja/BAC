#include "creneau.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef DEBUG
#include "tests.h"
#endif

struct s_creneau{
    Enseignant enseignant;
    char * formation;
    Horaire horaire;
    char * salle;
};

Creneau creneau(Enseignant e, Horaire h, char *f, char* s){
    Creneau c=(Creneau)malloc(sizeof(struct s_creneau));
    c->enseignant=e;
    c->horaire=h;
    c->formation=f;
    c->salle=s;
    return c;
}

Creneau setCreneauE(Enseignant e, Creneau c){
    c->enseignant=e;
    return c;
}

Creneau setCreneauF(char * f, Creneau c){
    c->formation=f;
    return c;
}

Creneau setCreneauH(Horaire h, Creneau c){
    c->horaire=h;
    return c;
}

Creneau setCreneauS(char * s, Creneau c){
    c->salle=s;
    return c;
}

char * getS(Creneau c){
    return c->salle;
}

Horaire getH(Creneau c){
    return c->horaire;
}

Enseignant getE(Creneau c){
    return c->enseignant;
}

char * getF(Creneau c){
    return c->formation;
}

void afficheCreneau(Creneau c){
    printf("%s %s \n", getS(c), getF(c));
    afficheEnseignant(getE(c));
    afficheHoraire(getH(c));
}

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

    test(getNom(getE(c)) == getNom(e1));
    test(getDebut(getH(c)) == getDebut(h1));
    test(getF(c) == f1);
    test(getS(c) == s1);

    setCreneauE(e2,c);
    setCreneauF(f2,c);
    setCreneauH(h2,c);
    setCreneauS(s2,c);

    test(getMatiere(getE(c)) == getMatiere(e2));
    test(getFin(getH(c)) == getFin(h2));
    test(getF(c) == f2);
    test(getS(c) == s2);



    return 0;
}

#endif