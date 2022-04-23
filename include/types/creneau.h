#ifndef __CRENEAU_H__
#define __CRENEAU_H__

#include "enseignant.h"
#include "horaire.h"

typedef struct s_creneau *Creneau;

Creneau creneau(Enseignant enseignant, Horaire horaire, char* formation, char* salle);

Creneau setCreneau(Creneau, Enseignant, Horaire, char* formation, char* salle);
Enseignant getEnseignant(Creneau);
Horaire getHoraire(Creneau);
char* getFormation(Creneau);
char* getSalle(Creneau);
char* toString(Creneau);

#endif