#ifndef __ENSEIGNANT_H__
#define __ENSEIGNANT_H__

typedef struct s_enseignant *Enseignant;

Enseignant enseignant(char* nom, char* matiere);

char* getNom(Enseignant);
char* getMatiere(Enseignant);
Enseignant setNom(Enseignant, char*);
Enseignant setMatiere(Enseignant, char*);
char* toString(Enseignant);

#endif