#ifndef __SALLES_H__
#define __SALLES_H__

#include "salle.h"

typedef struct s_salles *Salles;

Salles salles();

Salle getSalle(Salles, char* nom);
Salles ajouterSalle(Salles, Salle);
char* toStringSalles(Salles);

#endif