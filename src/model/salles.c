#include "salles.h"

#ifdef DEBUG
#include "tests.h"
#endif

struct s_salles{
    int nbr;
    Sal salle;
};

struct s_sal{
    Salle s;
    Salle suivante;
};

Salles salles (){
    Salles s=(salles) malloc(sizeof(struct s_salles));
    s->salle="NULL";
    s->nbr=0;
    return s;
}

Sal sal(Salle s){
    Sal l=(Sal) malloc(sizeof(struct s_sal));
    l->s=s;
    l->suivante="NULL";
    return l;
}

#ifdef TEST

int main() {

    // init

    char* s1_nom = "118";
    char* s2_nom = "103";

    Salle s1 = salle(s1_nom);
    Salle s2 = salle(s2_nom);

    // testing

    Salles S = salles();

    test(toStringSalles(S) == "");

    assert(getSalle(S, s1_nom)); // devrait produire une erreur

    ajouterSalle(S, s1);
    test(getSalle(S, s1_nom) == s1);
    ajouterSalle(S, s1); // devrait produire une erreur

    test(toStringSalles(S) == toStringSalle(s1));

    ajouterSalle(S, s2);
    test(getSalle(S, s2_nom) == s2);
    test(getSalle(S, s1_nom) == s1);

    return 0;
}

#endif