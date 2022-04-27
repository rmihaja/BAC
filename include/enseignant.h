#ifndef __ENSEIGNANT_H__
#define __ENSEIGNANT_H__

//#include "jansson.h"

typedef struct s_enseignant *Enseignant;

Enseignant enseignant (char* n, char* m);
void afficheEnseignant (Enseignant e);
Enseignant setMatiere(Enseignant e, char* m);
Enseignant setNom(Enseignant e, char* n);
char* getMatiere(Enseignant e);
char* getNom(Enseignant e);

//json_t* getJson(Enseignant e);

#endif