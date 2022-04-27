#include "salles.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef DEBUG
#include "tests.h"
#endif

typedef struct s_sal{
    Salle s;
    struct s_sal *suivante;
}* Sal;

struct s_salles{
    int nbr;
    Sal salles;
};

Salles salles (){
    Salles s=(Salles) malloc(sizeof(struct s_salles));
    s->salles->s=NULL;
    s->nbr=0;
    return s;
}

Sal sal(Salle s){
    Sal l=(Sal) malloc(sizeof(struct s_sal));
    l->s=s;
    l->suivante=NULL;
    return l;
}

Salles ajouterSs(Salles Ss, Salle a){
    Sal s=sal(a);
    if(Ss->nbr==0){
        Ss->salles=s;
        Ss->nbr=1;
    }else{
        s->suivante=Ss->salles;
        Ss->salles=s;
        Ss->nbr++;
    }
    return Ss;
}

Salle getSalle(Salles Ss, char* nom){
    Salle r=salle(0);
    Sal courant=Ss->salles;
    for(int i=0;i<Ss->nbr;i++){
        if(getNomS(courant->s)==nom){
            r=courant->s;
        }
        courant=courant->suivante;
    }
    free(courant);
    return r;
}

void afficheSalles(Salles Ss){
    Sal courant=Ss->salles;
    for(int i=0;i<Ss->nbr;i++){
        afficherSalle(courant->s);
        printf("*********************");
        courant=courant->suivante;
    }
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

    ajouterSs(S, s1);
    test(getSalle(S, s1_nom) == s1);

    ajouterSs(S, s2);
    test(getSalle(S, s2_nom) == s2);
    test(getSalle(S, s1_nom) == s1);

    return 0;
}

#endif