/**
 * @file enseignants.h
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief En-tête de la struture de données Enseignants
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __ENSEIGNANTS_H__
#define __ENSEIGNANTS_H__

#include <stdbool.h>
#include "enseignant.h"
#include "jansson.h"

 /**
  * @brief Objet Enseignants.
  *
  */
typedef struct s_enseignants* Enseignants;

/**
 * @brief Construit un nouvel objet Enseignants.
 *
 * @return Instance allouée de Enseignants.
 */
Enseignants enseignants();

/**
 * @brief Construit un nouvel objet Enseignants à partir
 * de sa représentation en objet JSON.
 *
 * @pre Précondition: json_enseignants doit contenir une
 * clé "enseignants" stockant un tableau de Enseignant.
 *
 * @param json_enseignants Objet JSON de Enseignants.
 * @return Instance allouée de Enseignants.
 */
Enseignants enseignantsParser(json_t* json_enseignants);

/**
 * @brief Accesseur de l'objet Enseignant à partir de son Nom
 * parmi la liste des Enseignants.
 *
 * @pre Enseignants doit posséder une référence Enseignant ayant
 * nom comme valeur de son attribut Nom.
 *
 * @param es Référence de Enseignants.
 * @param nom Valeur du Nom à rechercher.
 * @return Référence de Enseignant ayant nom comme valeur de son
 * attribut Nom.
 */
Enseignant getEnseignantByNom(Enseignants es, char* nom);

/**
 * @brief Accesseur de l'objet Enseignant à partir de sa Matiere
 * parmi la liste des Enseignants.
 *
 * @pre Enseignants doit posséder une référence Enseignant ayant
 * matiere comme valeur de son attribut Matiere.
 *
 * @param es Référence de Enseignants.
 * @param matiere Valeur de Matiere à rechercher.
 * @return Référence de Enseignant possédant matiere comme valeur
 * de son attribut Matiere.
 */
Enseignant getEnseignantByMatiere(Enseignants es, char* matiere);

/**
 * @brief Accesseur de la représentation en objet JSON de Enseignants.
 *
 * @param es Référence de Enseignants.
 * @return Objet JSON de de Enseignants de type json_t*.
 */
json_t* getJsonEnseignants(Enseignants es);

/**
 * @brief vérifie si Enseignants possède une référence de
 * l'objet Enseignant.
 *
 * @param es Référence de Enseignants.
 * @param e Référence de Enseignant à rechercher.
 * @return true si un Enseignant de Enseignants est égale à Enseignant.
 */
bool appartient(Enseignants es, Enseignant e);

/**
 * @brief ajouter une référence de l'objet Enseignant
 * à la liste des Enseignants.
 *
 * @pre Enseignants ne doit posséder aucune autre
 * référence à Enseignant.
 *
 * @param es Référence de Enseignants.
 * @param e Référence de Enseignant à ajouter.
 * @return Enseignants possédant une référence de Enseignant.
 */
Enseignants ajouterEs(Enseignants es, Enseignant e);

/**
 * @brief Supprime toute référence de l'objet Enseignant dans
 * la liste des Enseignants.
 *
 * @pre Enseignants ne doit pas être vide.
 *
 * @param e
 * @param es
 * @return Enseignants
 */
Enseignants supprimerEs(Enseignants es, Enseignant e);

/**
 * @brief Imprime tout Enseignant de la liste des Enseignants
 * sur stdout, suivi d'un retour à ligne.
 *
 * @param es Enseignants à afficher.
 */
void afficherEnseignants(Enseignants es);

/**
 * @brief Accesseur de la représentation en chaîne de caractère
 * JSON de Enseignants.
 *
 * @param es Référence de Enseignants.
 * @return Représentation JSON de Enseignants de type char*.
 */
char* toStringEnseignants(Enseignants es);

#endif
