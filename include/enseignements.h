/**
 * @file enseignements.h
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief En-tête de la struture de données Enseignements
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __ENSEIGNEMENTS_H__
#define __ENSEIGNEMENTS_H__

#include <stdbool.h>
#include <jansson.h>

 /**
  * @brief Objet Enseignements.
  *
  */
typedef struct s_enseignements* Enseignements;

/**
 * @brief Construit un nouvel objet Enseignements.
 *
 * @return Nouvelle instance allouée de Enseignements.
 */
Enseignements enseignements();

/**
 * @brief Construit un nouvel objet Enseignements à partir
 * de sa représentation en objet JSON.
 *
 * @pre json_enseignements doit contenir une
 * clé "enseignements" stockant un tableau de Enseignement.
 *
 * @param json_enseignements Objet JSON de Enseignements.
 * @return Nouvelle instance allouée de Enseignements.
 */
Enseignements enseignementsParser(json_t* json_enseignements);

/**
 * @brief Accesseur d'un Enseignement à partir
 * de son Indice dans Enseignements.
 *
 * @pre Indice doit être positif et strictement inférieur
 * à la taille de la liste.
 * Enseignements ne doit pas être vide.
 *
 * @param ens Référence de Enseignements.
 * @param indice Indice à laquelle se trouve Enseignement recherchée.
 * @return Enseignement à l'indice indiquée de type char*.
 */
char* getEnseignementByIndice(Enseignements ens, int indice);

/**
 * @brief Accesseur de la représentation en objet JSON de Enseignements.
 *
 * @param ens Référence de Enseignements.
 * @return Objet JSON de Enseignements de type json_t*.
 */
json_t* getJsonEnseignements(Enseignements ens);

/**
 * @brief Accesseur de la taille de Enseignements.
 *
 * @param ens Référence de Enseignements
 * @return int Taille de Enseignements de type int.
 */
int sizeEnseignements(Enseignements ens);

/**
 * @brief vérifie si Enseignements possède une référence de
 * l'objet Enseignement.
 *
 * @param ens Référence de Enseignements.
 * @param nom Valeur de Enseignement de type char* à rechercher.
 * @return true si un Enseignement de Enseignements est égale à Enseignement.
 */
bool appartientEnseignements(Enseignements ens, char* nom);

/**
 * @brief Ajoute une référence de l'objet Enseignement
 * à la liste des Enseignements.
 *
 * @pre Enseignements ne doit posséder aucune autre
 * référence à Enseignement.
 *
 * @param ens Référence de Enseignements.
 * @param nom Valeur de Enseignement à ajouter de type char*.
 * @return Enseignements possédant une référence de Enseignement
 * parmi sa liste de Salle.
 */
Enseignements ajouterEns(Enseignements ens, char* nom);

/**
 * @brief Supprime toute référence de l'objet Enseignement dans
 * la liste des Enseignements.
 *
 * @pre Enseignements ne doit pas être vide.
 *
 * @param ens Référence de Enseignements.
 * @param nom Valeur de Enseignement à supprimer de type char*.
 * @return Enseignements ne possédant aucune référence de Enseignement.
 */
Enseignements supprimerEns(Enseignements ens, char* nom);

/**
 * @brief Imprime tout Enseignement de la liste des Enseignements
 * sur stdout, suivi d'un retour à ligne.
 *
 * @param ens Enseignements à afficher.
 * @param isOrdered indique si la liste doit être ordonnée par son indice.
 */
void afficherEnseignements(Enseignements ens, bool isOrdered);

/**
 * @brief Accesseur de la représentation en chaîne de caractère
 * JSON de Enseignements.
 *
 * @param ens Référence de Enseignements.
 * @return Représentation JSON de Enseignements de type char*.
 */
char* toStringEnseignements(Enseignements ens);

#endif
