#ifndef __HORAIRE_H__
#define __HORAIRE_H__

#include <stdlib.h>
#include <assert.h>

typedef struct s_horaire *Horaire;

Horaire horaire(int d, int f);
int getDebut(Horaire h);
int getFin(Horaire h);
Horaire setDebut(Horaire h, int d);
Horaire setFin(Horaire h, int f);
int duree(Horaire h);
void affiche1H(int i);
void afficheHoraire(Horaire h);

#endif