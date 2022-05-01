/**
 * @file creneau.h
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief En-tête de la structure de données Creneau
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __CRENEAU_H__
#define __CRENEAU_H__

#include <stdbool.h>
#include <jansson.h>
#include "enseignant.h"
#include "horaire.h"

 /**
  * @brief Objet Creneau.
  *
  */
typedef struct s_creneau* Creneau;

/**
 * @brief Construit un nouvel objet Creneau avec un objet
 * Enseignant, un objet Horaire, un Enseignement,
 * une Formation et une Salle.
 *
 * @param e Enseignant du Creneau de type Enseignant.
 * @param h Horaire du Creneau de type Horaire.
 * @param enseignement Enseignement du Creneau de type char*.
 * @param formation Formation du Creneau de type char*.
 * @param salle Salle du Creneau de type char*.
 * @return Nouvelle instance allouée du Creneau.
 */
Creneau creneau(Enseignant e, Horaire h, char* enseignement, char* formation, char* salle);

/**
 * @brief Construit un nouvel objet Creneau à partir
 * de sa représentation en objet JSON.
 *
 * @pre json_creneau doit contenir une clé "enseignant",
 * "horaire", "enseignement", "formation", "salle".
 *
 * @param json_creneau Objet JSON du Creneau.
 * @return Nouvelle instance allouée du Creneau.
 */
Creneau creneauParser(json_t* json_creneau);

/**
 * @brief Accesseur de l'objet Enseignant du Creneau.
 *
 * @param c Référence du Creneau.
 * @return Référence de Enseignant du Creneau.
 */
Enseignant getCreneauE(Creneau c);

/**
 * @brief Accesseur de l'objet Horaire du Creneau.
 *
 * @param c Référence du Creneau.
 * @return Référence de Horaire du Creneau.
 */
Horaire getCreneauH(Creneau c);

/**
 * @brief Accesseur de l'objet Enseignement du Creneau.
 *
 * @param c Référence du Creneau.
 * @return Valeur de Enseignement de type char*.
 */
char* getCreneauENS(Creneau c);

/**
 * @brief Accesseur de l'objet Formation du Creneau.
 *
 * @param c Référence du Creneau.
 * @return Valeur de la Formation de type char*.
 */
char* getCreneauF(Creneau c);

/**
 * @brief Accesseur de l'objet Salle du Creneau.
 *
 * @param c Référence du Creneau.
 * @return Valeur de la Salle de type char*.
 */
char* getCreneauS(Creneau c);

/**
 * @brief Accesseur de la représentation en objet JSON du Creneau.
 *
 * @param c Référence du Creneau.
 * @return Objet JSON de Creneau de type json_t*.
 */
json_t* getJsonCreneau(Creneau c);

/**
 * @brief Définie l'objet Enseignant du Creneau.
 *
 * @param e Référence de l'objet Enseignant.
 * @param c Référence du Creneau à modifier.
 * @return Creneau avec la nouvelle référence de Enseignant.
 */
Creneau setCreneauE(Enseignant e, Creneau c);

/**
 * @brief Définie l'objet Horaire du Creneau.
 *
 * @param h Référence de l'objet Horaire.
 * @param c Référence du Creneau à modifier.
 * @return Creneau avec la nouvelle référence de Horaire.
 */
Creneau setCreneauH(Horaire h, Creneau c);

/**
 * @brief Définie l'objet Enseignement du Creneau.
 *
 * @param enseignement Valeur de Enseignement de type char*.
 * @param c Référence du Creneau à modifier.
 * @return Creneau avec la nouvelle valeur de Enseignement.
 */
Creneau setCreneauENS(char* enseignement, Creneau c);

/**
 * @brief Définie l'objet Formation du Creneau.
 *
 * @param formation Valeur de Formation de type char*.
 * @param c Référence du Creneau à modifier.
 * @return Creneau avec la nouvelle valeur de Formation.
 */
Creneau setCreneauF(char* formation, Creneau c);

/**
 * @brief Définie l'objet Salle du Creneau.
 *
 * @param salle Valeur de Salle de type char*.
 * @param c Référence du Creneau à modifier.
 * @return Creneau avec la nouvelle valeur de Salle.
 */
Creneau setCreneauS(char* salle, Creneau c);

/**
 * @brief compare deux Creneau.
 *
 * @param c1 Creneau 1 à comparer.
 * @param c2 Creneau 2 à comparer.
 * @return true si Creneau 1 et Creneau 2 possèdent les
 * mêmes attributs Enseignant, Horaire, Formation et Salle.
 * @return false si un ou plusieurs attributs de Creneau 1 et
 * Creneau 2 diffèrent.
 */
bool equalsCreneau(Creneau c1, Creneau c2);

/**
 * @brief Imprime les attributs de Creneau sur stdout,
 * suivi d'un retour à la ligne.
 *
 * @param c Référence de Creneau à afficher.
 */
void afficheCreneau(Creneau c);

/**
 * @brief Accesseur de la représentation en chaîne de caractère
 * JSON de Creneau.
 *
 * @param c Référence de Creneau.
 * @return Représentation JSON de Creneau de type char*.
 */
char* toStringCreneau(Creneau c);

#endif