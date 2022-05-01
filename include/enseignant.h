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
typedef struct s_enseignant* Enseignant;

/**
 * @brief Construit un nouvel objet Enseignant avec un Nom
 * et un Prenom.
 *
 * @param nom Nom de Enseignant de type char*.
 * @param prenom Prenom de Enseignant de type char*.
 * @return Nouvelle instance allouée de Enseignant.
 */
Enseignant enseignant(char* nom, char* prenom);

/**
 * @brief Construit un nouvel objet Enseignant à partir de sa
 * représentation en objet JSON.
 *
 * @pre json_enseignant doit contenir une clé
 * "nom" et "prenom".
 *
 * @param json_enseignant Objet JSON de Enseignant.
 * @return Nouvelle instance allouée de Enseignant.
 */
Enseignant enseignantParser(json_t* json_enseignant);

/**
 * @brief Accesseur de l'objet Nom de Enseignant.
 *
 * @param e Référence de Enseignant.
 * @return Valeur du Nom de type char*.
 */
char* getNom(Enseignant e);

/**
 * @brief Accesseur de l'objet Prenom de Enseignant.
 *
 * @param e Référence de Enseignant.
 * @return Valeur de la Prenom de type char*.
 */
char* getPrenom(Enseignant e);

/**
 * @brief Accesseur de la représentation en objet JSON de Enseignant.
 *
 * @param e Référence de Enseignant.
 * @return Objet JSON de Enseignant de type json_t*.
 */
json_t* getJsonEnseignant(Enseignant e);

/**
 * @brief Définie l'objet Nom de Enseignant.
 *
 * @param e Référence de Enseignant à modifier.
 * @param nom Valeur du Nom de type char*.
 * @return Enseignant avec la nouvelle valeur de Nom.
 */
Enseignant setNom(Enseignant e, char* n);

/**
 * @brief Définie l'objet Prenom de Enseignant.
 *
 * @param e Référence de Enseignant à modifier.
 * @param prenom Valeur de Matière de type char*.
 * @return Enseignant avec la nouvelle valeur de Prenom.
 */
Enseignant setPrenom(Enseignant e, char* prenom);

/**
 * @brief compare deux Enseignant.
 *
 * @param e1 Enseignant 1 à comparer.
 * @param e2 Enseignant 2 à comparer.
 * @return true si Enseignant 1 et Enseignant 2 possèdent les mêmes
 * attributs Nom et Prenom.
 * @return false si un ou plusieurs attributs de Enseignant 1 et
 * Enseignant 2 diffèrent.
 *
 */
bool equalsEnseignant(Enseignant e1, Enseignant e2);

/**
 * @brief Imprime les attributs de Enseignant sur stdout,
 * suivi d'un retour à la ligne.
 *
 * @param e Référence de Enseignant à afficher.
 */
void afficheEnseignant(Enseignant e);

/**
 * @brief Accesseur de la représentation en chaîne de caractère
 * JSON de Enseignant.
 *
 * @param e Référence de Enseignant.
 * @return Représentation JSON de Enseignant de type char*.
 */
char* toStringEnseignant(Enseignant e);

#endif