#ifndef __SALLES_H__
#define __SALLES_H__

#include "salle.h"

typedef struct s_salles *Salles;
typedef struct s_sal *Sal;

Salles salles();
Sal sal(Salle s);
Salles ajouterSs(Salles Ss, Salle a);
Salle getSalle(Salles Ss, char* salle);
void afficheSalles(Salles Ss);


#endif