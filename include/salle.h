/**
 * @file salle.h
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief En-tête de la structure de données Salle
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __SALLE_H__
#define __SALLE_H__

#include <stdbool.h>
#include "creneau.h"
#include <jansson.h>

 /**
  * @brief Objet Salle.
  *
  */
typedef struct s_salle* Salle;

/**
 * @brief Construit un nouvel objet Salle avec un Nom vide
 * et un tableau de Creneau vide.
 *
 * @param nom Nom de Salle de type char*.
 * @return Nouvelle instance allouée de Salle.
 */
Salle salle();

/**
 * @brief Construit un nouvel objet Salle avec un Nom
 * et un tableau de Creneau vide.
 *
 * @param nom Nom de Salle de type char*.
 * @return Nouvelle instance allouée de Salle.
 */
Salle salleCopie(char* nom);

/**
 * @brief Construit un nouvel objet Salle à partir de sa
 * représentation en objet JSON.
 *
 * @pre json_salle doit contenir une clé "nom" et "creneaux"
 * stockant un tableau de Creneau ou null.
 *
 * @param json_salle Objet JSON de Salle.
 * @return Nouvelle instance allouée de Salle.
 */
Salle salleParser(json_t* json_salle);

/**
 * @brief Accesseur de l'objet Nom de Salle.
 *
 * @param s Référence de Salle.
 * @return Valeur du Nom de Salle de type char*.
 */
char* getSalleN(Salle s);

/**
 * @brief Accesseur du tableau de Creneau de Salle.
 *
 * @param s Référence de Salle.
 * @return Adresse de la première case du tableau de Creneau, de type Creneau*.
 */
Creneau* getSalleC(Salle s);

/**
 * @brief Accesseur de la représentation en objet JSON de Salle.
 *
 * @param s Référence de Salle.
 * @return Objet JSON de Salle de type json_t*.
 */
json_t* getJsonSalle(Salle s);

/**
 * @brief Définie l'objet Nom de Salle.
 *
 * @param s Référence de Salle à modifier.
 * @param nom Valeur du Nom de type char*.
 * @return Salle avec la nouvelle valeur de Nom.
 */
Salle setSalleN(Salle s, char* nom);

/**
 * @brief Ajoute une référence de l'objet Creneau au tableau
 * de Creneau de Salle.
 *
 * @pre Salle ne doit contenir aucune autre référence de Creneau
 * dans l'intervalle de Horaire indiqué par Creneau.
 *
 * @param s Référence de Salle.
 * @param c Référence de Creneau à ajouter.
 * @return Salle possédant une référence de Creneau parmi le tableau de
 * Creneau si Salle était libre dans l'intervalle de Horaire.
 */
Salle ajouterSalleC(Salle s, Creneau c);

/**
 * @brief Supprime tout Creneau réservé dans l'intervalle
 * de Horaire.
 *
 * @param s Référence de Salle.
 * @param h Référence de Horaire représentant l'intervalle de suppression.
 * @return Salle ne possédant aucun Creneau réservé dans l'intervalle
 * de suppression.
 */
Salle supprimerSalleH(Salle s, Horaire h);

/**
 * @brief Modifie le Creneau à l'Horaire horaire_modifié pour le remplacer
 * par un nouveau Creneau.
 *
 * @pre Salle doit avoir un Creneau réservé à l'Horaire horaire_modifié.
 *
 * @param s Référence de Salle.
 * @param horaire_modifie Référence de Horaire du Creneau à modifier.
 * @param c Référence du nouveau Creneau à ajouter.
 * @return Salle possédant une référence de Creneau parmi le tableau de
 * Creneau.
 */
Salle modifierSalleHC(Salle s, Horaire horaire_modifie, Creneau c);

/**
 * @brief Vérifie si Salle ne contient aucun créneau réservé
 * dans l'intervalle de Horaire.
 *
 * @param s Référence de Salle.
 * @param h Référence de Horaire représentant l'intervalle de vérification.
 * @return true si aucun Creneau n'a été réservé dans l'intervalle de Horaire.
 * @return false si un ou plusieurs Creneau a été réservé dans l'intervalle de
 * Horaire.
 */
bool isFreeSalle(Salle s, Horaire h);

/**
 * @brief Vérifie si Salle ne contient aucun créneau réservé.
 *
 * @param s Référence de Salle.
 * @return true si Salle ne contient aucun Creneau réservé dans
 * son tableau de Creneau.
 * @return false si un Creneau est réservé dans le tableau de Creneau
 * de Salle.
 */
bool isEmptySalle(Salle s);

/**
 * @brief Imprime le nom de Salle ainsi que son tableau de Creneau
 * sur stdout, suivi d'un retour à la ligne.
 *
 * @param s Salle à afficher.
 */
void afficheSalle(Salle s);

/**
 * @brief Accesseur de la représentation en chaîne de caractère
 * JSON de Salle.
 *
 * @param s Référence de Salle.
 * @return Représentation JSON de Salle de type char*.
 */
char* toStringSalle(Salle s);

#endif