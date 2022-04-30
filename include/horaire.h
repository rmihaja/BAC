/**
 * @file horaire.h
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief En-tête de la structure de données Horaire
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __HORAIRE_H__
#define __HORAIRE_H__

#include <stdlib.h>
#include <stdbool.h>
#include "jansson.h"

/**
 * @brief Objet Horaire.
 *
 */
typedef struct s_horaire *Horaire;

/**
 * @brief construit un nouvel objet Horaire avec un Début et une Fin.
 *
 * @pre Pré-condition: Debut doit être dans l'intervalle
 * \f$ \llbracket 8, 19 \rrbracket \f$ et Fin doit être dans l'intervalle
 * \f$ \llbracket 9, 20 \rrbracket \f$.
 * Debut et Fin ne doivent pas être égaux.
 *
 * @param debut Heure de début de Horaire de type int.
 * @param fin Heur de fin de Horaire de type int.
 * @return Instance allouée de Horaire.
 */
Horaire horaire(int debut, int fin);

/**
 * @brief construit un nouvel objet Horaire à partir de sa représentation
 * objet JSON.
 *
 * @pre Precondition: json_horaire doit contenir une clé "debut" et "fin".
 *
 * @param json_horaire Objet JSON de Horaire.
 * @return Instance allouée de Horaire .
 */
Horaire horaireParser(json_t* json_horaire);

/**
 * @brief Accesseur de l'objet Debut de Horaire.
 *
 * @param h Référence de Horaire.
 * @return Valeur de Debut de type int.
 */
int getDebut(Horaire h);

/**
 * @brief Accesseur de l'objet Fin de Horaire.
 *
 * @param h Référence de Horaire.
 * @return Valeur de Fin de type int.
 */
int getFin(Horaire h);

/**
 * @brief Accesseur de la représentation en objet JSON de Horaire.
 *
 * @param h Référence de Horaire.
 * @return Représentation JSON de Enseignant de type json_t*.
 */
json_t* getJsonHoraire(Horaire h);

/**
 * @brief Calcule la durée d'une horaire.
 *
 * @param h Référence de Horaire.
 * @return Durée de Horaire de type int.
 */
int duree(Horaire h);

/**
 * @brief Définie l'objet Debut de Horaire.
 *
 * @param h Référence de Horaire à modifier.
 * @param debut Valeur de Debut de type int.
 * @return Horaire avec la nouvelle valeur de Debut.
 */
Horaire setDebut(Horaire h, int debut);

/**
 * @brief Définie l'objet Fin de Horaire.
 *
 * @param h Référence de Horaire à modifier.
 * @param fin Valeur de Fin de type int.
 * @return Horaire avec la nouvelle valeur de Fin.
 */
Horaire setFin(Horaire h, int fin);

/**
 * @brief compare deux Horaire.
 *
 * @param h1 Horaire 1 à comparer.
 * @param h2 Horaire 2 à comparer.
 * @return true si Horaire 1 et Horaire 2 possède les mêmes
 * attributs Debut et Fin.
 * @return false si un ou plusieurs attributs de Horaire 1
 * et Horaire 2 diffèrent.
 */
bool equalsHoraire(Horaire h1, Horaire h2);

/**
 * @brief Imprime une heure?
 *
 * // TODO
 * @todo check necessity
 * @param i
 */
void affiche1H(int i);

/**
 * @brief Imprime les attributs de Horaire sur stdout,
 * suivi d'un retour à la ligne.
 *
 * @param h Horaire à afficher.
 */
void afficheHoraire(Horaire h);

/**
 * @brief Accesseur de la représentation en chaîne de caractère
 * JSON de Horaire.
 *
 * @param e Référence de Enseignant.
 * @return Représentation JSON de Enseignant de type char*.
 */
char* toStringHoraire(Horaire e);

#endif