#ifndef __CONTROLE_H__
#define __CONTROLE_H__

#include "formation.h"
#include "enseignants.h"
#include "salles.h"


typedef struct s_controle *Controle;

Controle controle();
Controle reserver(Controle Ct, Creneau c);
Controle annuler(Controle Ct, Creneau c);
Controle modifier(Controle Ct, Creneau c);
void afficherEDTSalles(Controle Ct);
void afficherEDTFormation(Controle Ct);
void afficherEDTEnseignants(Controle Ct);
void afficherEDTSalle(Controle Ct);

#endif