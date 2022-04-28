#ifndef __FORMATION_H__
#define __FORMATION_H__

#include "creneau.h"
#include <stdbool.h>
#ifdef JSON
#include "jansson.h"
#endif

typedef struct s_formation *Formation;

Formation formation(char* n);
bool estComplet(Formation f);
Formation ajouterH(Formation f, Creneau c);
Formation supprimerH (Formation f, Horaire h);

#ifdef JSON
Formation formationParser(json_t* json_formation);
json_t* getJsonFormation(Formation f);
char* toStringFormation(Formation f);
#endif

#endif