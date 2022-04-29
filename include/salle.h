#ifndef __SALLE_H__
#define __SALLE_H__

#include "creneau.h"
#include <stdbool.h>
#ifdef JSON
#include "jansson.h"
#endif

typedef struct s_salle *Salle;
Salle salle(int n);
bool isFreeSalle(Salle s, Horaire h);
Salle ajouterS(Salle s, Creneau c);
Salle supprimerS(Salle s, Horaire h);
Salle modifierS(Salle s,Horaire hmodif, Creneau cnew);
bool estVideSalle(Salle s);
void afficherSalle(Salle s);
Creneau* getCreneauS(Salle s);
int getNomS(Salle s);

#ifdef JSON
Salle salleParser(json_t* json_salle);
json_t* getJsonSalle(Salle s);
char* toStringSalle(Salle s);
#endif

#endif