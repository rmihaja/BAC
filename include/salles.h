/**
 * @file salles.h
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief En-tête de la structure de données Salles
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __SALLES_H__
#define __SALLES_H__

#include "salle.h"
#include "jansson.h"

 /**
  * @brief Objet Salles.
  *
  */
typedef struct s_salles* Salles;

/**
 * @brief Construit un nouvel objet Salles.
 *
 * @return Nouvelle instance allouée de Salles.
 */
Salles salles();

/**
 * @brief Construit un nouvel objet Salles à partir de
 * sa représentation en objet JSON.
 *
 * @pre json_salles doit contenir une clé "salles"
 * stockant un tableau de Salle.
 *
 * @param json_salles Objet JSON de Salles.
 * @return Nouvelles instance allouée de Salles.
 */
Salles sallesParser(json_t* json_salles);

/**
 * @brief Accesseur de l'objet Salle à partir de
 * son Nom parmi la liste des Salles.
 *
 * @pre Salles doit posséder une référence Salle ayant nom
 * comme valeur de son attribut Nom.
 *
 * @param ss Référence de Salles.
 * @param nom Valeur du Nom à rechercher.
 * @return Référence de Salle ayant nom comme valeur de son
 * attribut Nom.
 */
Salle getSalleByNom(Salles ss, char* nom);

/**
 * @brief Accesseur du Nom de l'objet Salle à partir
 * de son Indice dans la liste des Salles.
 *
 * @pre Indice doit être positif et strictement inférieur
 * à la taille de la liste.
 * Salles ne doit pas être vide.
 *
 * @param ss Référence de Salles.
 * @param indice Indice à laquelle se trouve la Salle recherchée.
 * @return Nom de la Salle de type char*.
 */
char* getSalleNByIndice(Salles ss, int indice);

/**
 * @brief Accesseur de la représentation en objet JSON de Salles.
 *
 * @param ss Référence de Salles.
 * @return json_t* Objet JSON de Salles de type json_t*.
 */
json_t* getJsonSalles(Salles ss);

/**
 * @brief Accesseur de la taille de la liste des Salles.
 *
 * @param ss Référence de Salles.
 * @return Taille de la liste des Salles de type int.
 */
int sizeSalles(Salles ss);

/**
 * @brief Ajoute une référence de l'objet Salle à
 * la liste des Salles.
 *
 * @pre Salles ne doit posséder aucune autre référence
 * à Salle.
 *
 * @param ss Référence de Salles.
 * @param s Référence de Salle à ajouter.
 * @return Salles possédant une référence de Salle parmi sa
 * liste de Salle.
 */
Salles ajouterSs(Salles ss, Salle s);

/**
 * @brief Imprime toute Salle de la liste des Salles sur
 * stdout, suivi d'un retour à la ligne.
 *
 * @param ss Salles à afficher.
 */
void afficheSalles(Salles ss);

/**
 * @brief Accesseur de la représentation en chaîne de caractère
 * JSON de Salles.
 *
 * @param s Référence de Salles.
 * @return Représentation JSON de Salles de type char*.
 */
char* toStringSalles(Salles s);

#endif