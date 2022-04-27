#ifndef __HORAIRE_H__
#define __HORAIRE_H__

typedef struct s_horaire *Horaire;

Horaire horaire(int d, int f);
int getDebut(Horaire h);
int getFin(Horaire h);
Horaire setDebut(Horaire h, int d);
Horaire setFin(Horaire h, int f);
int duree(Horaire h);
void Affiche1H(int i);
void AfficheHoraire(Horaire h);

#endif