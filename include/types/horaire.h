#ifndef __HORAIRE_H__
#define __HORAIRE_H__

typedef struct s_horaire *Horaire;

Horaire horaire(unsigned int debut, unsigned int fin);

char* getDebut(Horaire);
char* getFin(Horaire);
Horaire setDebut(Horaire, unsigned int);
Horaire setFin(Horaire, unsigned int);
int duree(Horaire);
char* toString(Horaire);

#endif
