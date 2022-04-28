#ifndef __ENSEIGNANTS_H__
#define __ENSEIGNANTS_H__

#include <stdbool.h>
#include "enseignant.h"
#ifdef JSON
#include "jansson.h"
#endif

typedef struct s_enseignants *Enseignants;

Enseignants enseignants();
Enseignants ajouterEs(Enseignant g, Enseignants es);
bool appartient(Enseignant e, Enseignants es);
Enseignants supprimerEs(Enseignant g, Enseignants es);
void afficherEnseignants (Enseignants es);
Enseignant getEnseignantN(Enseignants es, char *n);
Enseignant getEnseignantM(Enseignants es, char *m);

#ifdef JSON
json_t* getJsonEnseignants(Enseignants es);
char* toStringEnseignants(Enseignants es);
#endif

#endif
