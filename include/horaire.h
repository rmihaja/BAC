#ifndef __HORAIRE_H__
#define __HORAIRE_H__

#include <stdlib.h>
#include <assert.h>
#ifdef JSON
#include "jansson.h"
#endif

typedef struct s_horaire *Horaire;

Horaire horaire(int d, int f);
int getDebut(Horaire h);
int getFin(Horaire h);
Horaire setDebut(Horaire h, int d);
Horaire setFin(Horaire h, int f);
int duree(Horaire h);
void affiche1H(int i);
void afficheHoraire(Horaire h);

#ifdef JSON
Horaire horaireParser(json_t* json_horaire);
json_t* getJsonHoraire(Horaire h);
char* toStringHoraire(Horaire e);
#endif

#endif