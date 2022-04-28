#ifndef __ENSEIGNANT_H__
#define __ENSEIGNANT_H__

#include <stdlib.h>
#include <stdio.h>
#ifdef JSON
#include "jansson.h"
#endif

typedef struct s_enseignant *Enseignant;

Enseignant enseignant (char* n, char* m);
void afficheEnseignant (Enseignant e);
Enseignant setMatiere(Enseignant e, char* m);
Enseignant setNom(Enseignant e, char* n);
char* getMatiere(Enseignant e);
char* getNom(Enseignant e);

#ifdef JSON
json_t* getJsonEnseignant(Enseignant e);
char* toStringEnseignant(Enseignant e);
#endif

#endif