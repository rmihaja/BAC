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
 * @return Nouvelle instance allouée de Enseignants.
 */
Enseignants enseignants();

/**
 * @brief Construit un nouvel objet Enseignants à partir
 * de sa représentation en objet JSON.
 *
 * @pre json_enseignants doit contenir une
 * clé "enseignants" stockant un tableau de Enseignant.
 *
 * @param json_enseignants Objet JSON de Enseignants.
 * @return Nouvelle instance allouée de Enseignants.
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
 * @brief Accesseur de l'objet Enseignant à partir de sa Prenom
 * parmi la liste des Enseignants.
 *
 * @pre Enseignants doit posséder une référence Enseignant ayant
 * prenom comme valeur de son attribut Prenom.
 *
 * @param es Référence de Enseignants.
 * @param prenom Valeur de Prenom à rechercher.
 * @return Référence de Enseignant possédant prenom comme valeur
 * de son attribut Prenom.
 */
Enseignant getEnseignantByPrenom(Enseignants es, char* prenom);

/**
 * @brief Accesseur de l'objet Enseignant à partir
 * de son Indice dans Enseignants.
 *
 * @pre Indice doit être positif et strictement inférieur
 * à la taille de la liste.
 * Enseignants ne doit pas être vide.
 *
 * @param ss Référence de Salles.
 * @param indice Indice à laquelle se trouve la Salle recherchée.
 * @return Nom de la Salle de type char*.
 */
Enseignant getEnseignantByIndice(Enseignants es, int indice);
/**
 * @brief Accesseur de la représentation en objet JSON de Enseignants.
 *
 * @param es Référence de Enseignants.
 * @return Objet JSON de Enseignants de type json_t*.
 */
json_t* getJsonEnseignants(Enseignants es);

/**
 * @brief Accesseur de la taille de Enseignants.
 *
 * @param es Référence de Enseignants
 * @return int Taille de Enseignants de type int.
 */
int sizeEnseignants(Enseignants es);

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
 * @brief Ajoute une référence de l'objet Enseignant
 * à la liste des Enseignants.
 *
 * @pre Enseignants ne doit posséder aucune autre
 * référence à Enseignant.
 *
 * @param es Référence de Enseignants.
 * @param e Référence de Enseignant à ajouter.
 * @return Enseignants possédant une référence de Enseignant
 * parmi sa liste de Salle.
 */
Enseignants ajouterEs(Enseignants es, Enseignant e);

/**
 * @brief Supprime toute référence de l'objet Enseignant dans
 * la liste des Enseignants.
 *
 * @pre Enseignants ne doit pas être vide.
 *
 * @param e Référence de Enseignants.
 * @param es Référence de Enseignant à supprimer.
 * @return Enseignants ne possédant aucune référence de Enseignant.
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
