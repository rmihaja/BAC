#ifndef __ENSEIGNANT_H__
#define __ENSEIGNANT_H__

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
Enseignant enseignantParser(json_t* json_enseignant);
json_t* getJsonEnseignant(Enseignant e);
char* toStringEnseignant(Enseignant e);
#endif

#endif