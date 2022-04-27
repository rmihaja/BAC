#ifndef __CRENEAU_H__
#define __CRENEAU_H__

#include "enseignant.h"
#include "horaire.h"

typedef struct s_creneau *Creneau;

Creneau creneau(Enseignant e, Horaire h, char *f, char* s);
Creneau setCreneauE(Enseignant e, Creneau c);
Creneau setCreneauF(char * f, Creneau c);
Creneau setCreneauH(Horaire h, Creneau c);
Creneau setCreneauS(char * s, Creneau c);
void afficheCreneau(Creneau c);
char * getS(Creneau c);
Horaire getH(Creneau c);
Enseignant getE(Creneau c);
char * getF(Creneau c);



#endif