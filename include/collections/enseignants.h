#ifndef __ENSEIGNANTS_H__
#define __ENSEIGNANTS_H__

#include <stdbool.h>
#include "enseignant.h"

typedef struct s_enseignants *Enseignants;
typedef struct s_enseig *Enseig;

Enseignants enseignants();
Enseig enseig(Enseignant e);
Enseignants ajouterEs(Enseignant g, Enseignants es);
bool appartient(Enseig e, Enseignants es);
Enseignants supprimerEs(Enseignant g, Enseignants es);
void AfficherEnseignants (Enseignants es);
Enseignant getEnseignantN(Enseignants es, char *n);
Enseignant getEnseignantM(Enseignants es, char *m);

Enseignants enseignants();

Enseignant getEnseignant(Enseignants, Enseignant);
Enseignants ajouterEnseignant(Enseignants, Enseignant);
Enseignants supprimerEnseignant(Enseignants, char* nom);
char* toStringEnseignant(Enseignants);

#endif
