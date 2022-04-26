#ifndef __ENSEIGNANT_H__
#define __ENSEIGNANT_H__

typedef struct s_enseignant *Enseignant;


Enseignant enseignant (char* n, char* m);
char* toStringEnseignant (Enseignant e);
Enseignant setMatiere(Enseignant e, char* m);
Enseignant setNom(Enseignant e, char* n);
char* getMatiere(Enseignant e);
char* getNom(Enseignant e);

#endif