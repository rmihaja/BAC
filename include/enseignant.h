/**
 * @file enseignant.h
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief En-tête de la structure de données Enseignant
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __ENSEIGNANT_H__
#define __ENSEIGNANT_H__

#include <stdbool.h>
#include "jansson.h"

/**
 * @brief Objet Enseignant.
 *
 */
typedef struct s_enseignant *Enseignant;

/**
 * @brief Construit un nouvel objet Enseignant avec un Nom
 * et une Matière
 *
 * @param nom Nom de Enseignant de type char*.
 * @param matiere Matière de Enseignant de type char*.
 * @return Instance allouée de Enseignant.
 */
Enseignant enseignant(char *nom, char *matiere);

/**
 * @brief construit un nouvel objet Enseignant à partir de sa
 * représentation en objet JSON.
 *
 * @pre Precondition: json_enseignant doit contenir une clé
 * "nom" et "matiere".
 *
 * @param json_enseignant Objet JSON de Enseignant.
 * @return Instance allouée de Enseignant.
 */
Enseignant enseignantParser(json_t *json_enseignant);

/**
 * @brief Accesseur de l'objet Nom de Enseignant.
 *
 * @param e Référence de Enseignant.
 * @return Valeur du Nom de type char*.
 */
char *getNom(Enseignant e);

/**
 * @brief Accesseur de l'objet Matiere de Enseignant.
 *
 * @param e Référence de Enseignant.
 * @return Valeur de la Matiere de type char*.
 */
char *getMatiere(Enseignant e);

/**
 * @brief Accesseur de la représentation en objet JSON de Enseignant.
 *
 * @param e Référence de Enseignant.
 * @return Représentation JSON de Enseignant de type json_t*.
 */
json_t *getJsonEnseignant(Enseignant e);

/**
 * @brief Définie l'objet Nom de Enseignant.
 *
 * @param e Référence de Enseignant à modifier.
 * @param nom Valeur du Nom de type char*.
 * @return Enseignant avec la nouvelle valeur de Nom.
 */
Enseignant setNom(Enseignant e, char *n);

/**
 * @brief Définie l'objet Matiere de Enseignant.
 *
 * @param e Référence de Enseignant à modifier.
 * @param matiere Valeur de Matière de type char*.
 * @return Enseignant avec la nouvelle valeur de Matiere.
 */
Enseignant setMatiere(Enseignant e, char *matiere);

/**
 * @brief compare deux Enseignant.
 *
 * @param e1 Enseignant 1 à comparer.
 * @param e2 Enseignant 2 à comparer.
 * @return true si Enseignant 1 et Enseignant 2 possède les mêmes
 * attributs Nom et Matiere.
 * @return false si un ou plusieurs attributs de Enseignant 1 et
 * Enseignant 2 diffèrent.
 *
 */
bool equalsEnseignant(Enseignant e1, Enseignant e2);

/**
 * @brief Imprime les attributs de Enseignant sur stdout,
 * suivi d'un retour à la ligne.
 *
 * @param e Enseignant à afficher.
 */
void afficheEnseignant(Enseignant e);

/**
 * @brief Accesseur de la représentation en chaîne de caractère
 * JSON de Enseignant.
 *
 * @param e Référence de Enseignant.
 * @return Représentation JSON de Enseignant de type char*.
 */
char *toStringEnseignant(Enseignant e);
// #endif

#endif