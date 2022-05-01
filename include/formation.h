/**
 * @file formation.h
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief En-tête de la structure de données Formation
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __FORMATION_H__
#define __FORMATION_H__

#include <stdbool.h>
#include <jansson.h>
#include "creneau.h"

 /**
  * @brief Objet Formation.
  *
  */
typedef struct s_formation* Formation;

/**
 * @brief Construit un nouvel objet Formation avec un
 * Nom et une liste de Creneau vide.
 *
 * @param nom Nom de Formation de type char*.
 * @return Nouvelle instance allouée de Formation.
 */
Formation formation(char* nom);

/**
 * @brief Construit un nouvel objet Formation à partir
 * de sa représentation en objet JSON.
 *
 * @pre json_formation doit contenir une clé "nom" et
 * "crenaux" stockant un tableau de Creneau.
 *
 * @param json_formation Objet JSON de Formation.
 * @return Nouvelle instance allouée de Formation.
 */
Formation formationParser(json_t* json_formation);

/**
 * @brief Accesseur de l'objet Nom de Formation.
 *
 * @param f Référence de Formation.
 * @return Valeur du Nom de Formation de type char*.
 */
char* getFormationN(Formation f);

/**
 * @brief Accesseur de l'objet Creneau à partir
 * de son Indice dans Formation.
 *
 * @pre Indice doit être positif et strictement inférieur
 * à la taille de la liste.
 * Formation ne doit pas être vide.
 *
 * @param f Référence de Formation.
 * @param indice Indice à laquelle se trouve Creneau recherchée.
 * @return Creneau à l'indice indiquée.
 */
Creneau getFormationCByIndice(Formation f, int indice);

/**
 * @brief Accesseur de la représentation en objet JSON
 * de Formation.
 *
 * @param f Référence de Formation.
 * @return json_t* Objet JSON de Formation de type json_t*.
 */
json_t* getJsonFormation(Formation f);

/**
 * @brief Accesseur de la taille de la liste de Creneau
 * de Formation.
 *
 * @param f Référence de Formation.
 * @return Taille de la liste des Creneau de Formation de type int.
 */
int sizeFormationC(Formation f);

/**
 * @brief Ajoute une référence de l'objet Creneau à
 * la liste de Créneau de Formation.
 *
 * @pre Formation doit être libre dans l'intervalle de Horaire indiqué
 * par Creneau.
 * Formation ne doit pas être complet.
 * Formation de Creneau doit avoir Nom de Formation comme valeur.
 *
 * @param f Référence de Formation.
 * @param c Référence de Creneau à ajouter.
 * @return Formation possédant une référence de Creneau parmi
 * la liste de Creneau si Formation était libre dans l'intervalle
 * de Horaire.
 */
Formation ajouterFormationC(Formation f, Creneau c);

/**
 * @brief Supprime tout Creneau alloué à Formation dans
 * l'intervalle de Horaire.
 *
 * @param f Référence de Formation.
 * @param h Référence de Horaire représentant l'intervalle de
 * suppression.
 * @return Formation ne possédant aucun Creneau réservé dans
 * l'intervalle de suppression, si un Creneau a été alloué.
 */
Formation supprimerFormationH(Formation f, Horaire h);

/**
 * @brief Vérifie si Formation ne contient aucun créneau réservé
 * dans l'intervalle de Horaire.
 *
 * @param f Référence de Salle.
 * @param h Référence de Horaire représentant l'intervalle de vérification.
 * @return true si aucun Creneau n'a été réservé dans l'intervalle de Horaire.
 * @return false si un ou plusieurs Creneau a été réservé dans l'intervalle de
 * Horaire.
 */
bool isFreeFormation(Formation f, Horaire h);

/**
 * @brief Vérifie si Formation a atteint son maximum de Creneau
 * allouable pour la journée.
 * Le maximum est fixé à 4 Creneau.
 *
 * @param f Référence de Formation.
 * @return true si la taille de la liste de Creneau est inférieure
 * ou égale à 4.
 * @return false si la taille dépasse le maximum de Creneau allouable
 * fixé.
 */
bool isFullFormation(Formation f);

/**
 * @brief Imprime le nom de Formation ainsi que sa liste de Creneau
 * sur stdout, suivi d'un retour à la ligne.
 *
 * @param f Formation à afficher.
 * @param isOrdered permet de préfixer l'indice de Creneau dans
 * la liste de Creneau sur son affichage
 */
void afficheFormation(Formation f, bool isOrdered);

/**
 * @brief Accesseur de la représentation en chaîne de caractère
 * JSON de Formation.
 *
 * @param f Référence de Formation.
 * @return Représentation JSON de Formation de type char*.
 */
char* toStringFormation(Formation f);

#endif