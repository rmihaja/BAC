// ? structure modèle de toutes les modules du projet
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "enseignants.h"
#include "salles.h"
#include "formation.h"


#ifdef DEBUG
#include "tests.h"
#endif

struct s_controle{
    bool isAdmin;
    Enseignants enseignants;
    Salles salles;
    Formation formations;
}*Controle;

Controle controle(){
    
}



#ifdef TEST

int main() {

    // init

    // testing

    return 0;
}

#endif