/**
 * @file formations.h
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief En-tête de la structure de données Formations
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __FORMATIONS_H__
#define __FORMATIONS_H__

#include <jansson.h>
#include "formation.h"

 /**
  * @brief Objet Formations.
  *
  */
typedef struct s_formations* Formations;

/**
 * @brief Construit un nouvel objet Formations
 * avec un tableau de Formation.
 *
 * @param taille_max Taille maximale du tableau de Formation.
 * @return Nouvelle instance allouée de Formations.
 */
Formations formations(int taille_max);

/**
 * @brief Construit un nouvel objet Formation à partir de
 * sa représentation en objet JSON.
 *
 * @pre json_salles doit contenir une clé "formations"
 * stockant un tableau de Formation.
 *
 * @param json_formations Objet JSON de Formations.
 * @return Nouvelles instance allouée de Formations.
 */
Formations formationsParser(json_t* json_formations);

/**
 * @brief Accesseur de l'objet Formation à partir
 * de son Indice dans Formations.
 *
 * @pre Indice doit être positif et strictement inférieur
 * à la taille de la liste.
 * Formations ne doit pas être vide.
 *
 * @param fs Référence de Formations.
 * @param indice Indice à laquelle se trouve la Formation recherchée.
 * @return Formation à l'indice indiquée
 */
Formation getFormationByIndice(Formations fs, int indice);

/**
 * @brief Accesseur de la représentation en objet JSON de Formations.
 *
 * @param fs Référence de Formations.
 * @return Objet JSON de Formations de type json_t*.
 */
json_t* getJsonFormations(Formations fs);

/**
 * @brief Accesseur de la taille de Formations.
 *
 * @param fs Référence de Formations.
 * @return Taille de Formations de type int.
 */
int sizeFormations(Formations fs);

/**
 * @brief Ajoute une référence de l'objet Formation à
 * Formations.
 *
 * @pre Formations ne doit posséder aucune autre référence
 * à Formation.
 *
 * @param fs Référence de Formations.
 * @param f Référence de Formation à ajouter.
 * @return Formations possédant une référence de Formation parmi son
 * tableau de Formation.
 */
Formations ajouterFs(Formations fs, Formation f);


void afficherFormations(Formations fs);

/**
 * @brief Imprime le nom de toute Formation de Formations
 * sur stdout, précédé de son indice dans la liste
 * si ordonné, d'un tiret sinon et suivi d'un retour à la ligne.
 *
 * @param fs Formations à afficher.
 * @param isOrdered indique si la liste doit être ordonnée par son indice.
 *
 */
void afficherFormationsN(Formations fs, bool isOrdered);

/**
 * @brief Accesseur de la représentation en chaîne de caractère
 * JSON de Formations.
 *
 * @param fs Référence de Formations.
 * @return Représentation JSON de Formations de type char*.
 */
char* toStringFormations(Formations fs);

#endif