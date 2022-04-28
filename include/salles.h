#ifndef __SALLES_H__
#define __SALLES_H__

#include "salle.h"
#ifdef JSON
#include "jansson.h"
#endif

typedef struct s_salles *Salles;
typedef struct s_sal *Sal;

Salles salles();
Sal sal(Salle s);
Salles ajouterSs(Salles Ss, Salle a);
Salle getSalle(Salles Ss, char* salle);
void afficheSalles(Salles Ss);

#ifdef JSON
json_t* getJsonSalles(Salles s);
char* toStringSalles(Salles s);
#endif

#endif