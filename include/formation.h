#ifndef __FORMATION_H__
#define __FORMATION_H__

#include "creneau.h"
#include <stdbool.h>

typedef struct s_formation *Formation;

Formation formation(char* n);
bool estComplet(Formation f);
Formation ajouterC(Formation f, Creneau c);
Formation supprimerH (Formation f, Horaire h);
void afficheFormation(Formation f);

#endif