#ifndef __SALLES_H__
#define __SALLES_H__

#include "salle.h"
#ifdef JSON
#include "jansson.h"
#endif

typedef struct s_salles *Salles;

Salles salles();
Salles ajouterSs(Salles Ss, Salle a);
Salle getSalle(Salles Ss, char* salle);
void afficheSalles(Salles Ss);
char * getNomSParIndice(Salles Ss, int n);
int getnbr(Salles Ss);

#ifdef JSON
Salles sallesParser(json_t* json_salles);
json_t* getJsonSalles(Salles s);
char* toStringSalles(Salles s);
#endif

#endif