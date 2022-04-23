#ifndef __ENSEIGNANTS_H__
#define __ENSEIGNANTS_H__

#include "enseignant.h"

typedef struct s_enseignants *Enseignants;

Enseignants enseignants();

Enseignant getEnseignant(Enseignants, Enseignant);
Enseignants ajouterEnseignant(Enseignants, Enseignant);
Enseignants supprimerEnseignant(Enseignants, char* nom);
char* toStringEnseignant(Enseignants);

#endif
