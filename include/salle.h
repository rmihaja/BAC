#ifndef __SALLE_H__
#define __SALLE_H__

#include "creneau.h"
#include <stdbool.h>

typedef struct s_salle *Salle;
Salle salle(char * n);
bool isFreeSalle(Salle s, Horaire h);
Salle ajouterS(Salle s, Creneau c);
Salle supprimerS(Salle s, Horaire h);
Salle modifierS(Salle s,Horaire hmodif, Creneau cnew);
bool estVideSalle(Salle s);
void afficherSalle(Salle s);



#endif