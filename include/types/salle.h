#ifndef __SALLE_H__
#define __SALLE_H__

#include "creneau.h"
#include <stdbool.h>

typedef struct s_salle *Salle;

Salle salle(char* nom);

Salle ajouterCreneauSalle(Salle, Creneau);
Salle modifierCreneauSalle(Salle, Horaire ancien, Horaire nouveau);
Salle supprimerCreneauSalle(Salle, Horaire);
bool isFreeSalle(Salle, Horaire);
bool isEmptySalle(Salle);
char* toStringSalle(Salle);

#endif