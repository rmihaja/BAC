#ifndef __SALLE_H__
#define __SALLE_H__

#include "creneau.h"
#include "horaire.h"
#include <stdbool.h>

typedef struct s_salle *Salle;
Salle salle(int n);
bool isFreeSalle(Salle s, Horaire h);
Salle ajouterS(Salle s, Creneau c);


#endif