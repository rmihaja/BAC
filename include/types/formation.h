#ifndef __FORMATION_H__
#define __FORMATION_H__

#include "creneau.h"
#include "horaire.h"
#include <stdbool.h>

typedef struct s_formation *Formation;

Formation formation(char* nom);

Formation ajouterCreneauFormation(Formation, Creneau);
Formation supprimerCreneauFormation(Formaton, Horaire);
bool isFullFormation(Formation);
char* toStringFormation(Formation);


#endif