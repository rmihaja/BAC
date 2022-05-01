/**
 * @file controle.h
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief En-tête de la structure de données Controle
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __CONTROLE_H__
#define __CONTROLE_H__

#include "formations.h"
#include "enseignants.h"
#include "enseignements.h"
#include "salles.h"
#include "entree.h"

 /**
  * @brief Objet Controle.
  *
  */
typedef struct s_controle* Controle;

/**
 * @brief Construit un nouvelle objet Controle à partir des données
 * JSON s'il existe
 *
 * @pre le fichier JSON doit respecter les clés-valeurs de chaque
 * structure.
 *
 * @param cheminData chemin du fichier JSON contenant les données
 * @return Nouvelle instance alloué de Controle
 */
Controle controle(char* cheminData);

/**
 * @brief Boucle principale de l'interface de Controle.
 *
 * @param C Référence de Controle
 * @return 0 pour quitter.
 */
int run(Controle C);

#endif