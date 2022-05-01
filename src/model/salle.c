/**
 * @file salle.c
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief Code source de la structure de données Salle.
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "salle.h"

#ifdef DEBUG
#include "tests.h"
#endif

 /************************************************************\
 *                     Structure de Salle                     *
 \************************************************************/

 /**
  * @internal
  *
  * @struct s_salle
  * @brief Structure représentant un objet Salle.
  * @details
  * Structure permettant de stocker l'attribut nom d'une
  * salle, ainsi qu'un tableau de Creneau pour pouvoir stocker les
  * créneaux réservés aux indices de l'intervalle indiqué par
  * chaque Creneau.
  *
  * @endinternal
  */
struct s_salle {
    char nom[BUFSIZ];       /*!< Nom de l'objet Salle. */
    Creneau creneaux[24];   /*!< Tableau de Créneau de l'objet Salle.
                                Chaque intervalle d'heure est délimitée par ses indices,
                                d'où la taille de 24 pour marquer un jour. */
};


/************************************************************\
*                   Constructeurs de Salle                   *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet Salle.
 *
 * @endinternal
 */
Salle salle() {
    Salle s = (Salle)malloc(sizeof(struct s_salle));
    for (int i = 0; i < 24; i++) {
        s->creneaux[i] = NULL;
    }
    return s;
}

Salle salleCopie(char* nom) {
    Salle s = salle();
    setSalleN(s, nom);
    return s;
}

/**
 * @internal
 *
 * @details
 * Construit l'objet Salle en manipulant l'API Jansson.
 * Pour cela, à partir d'une recherche par clé (s'il existe),
 * nous pouvons accéder à l'attribut "nom" de Salle
 * que nous construisons à l'aide du constructeur par défaut.
 * Nous accédons ensuite à la clé "creneaux" qui est un tableau de Creneau.
 * On itère le tableau pour pouvoir ajouter chaque Creneau
 * au tableau de l'objet Salle, en faisant chaque fois appel à son
 * constructeur lorsque la valeur renvoyé par l'API n'est pas nulle.
 *
 * @sa creneauParser ,
 * [json_array_foreach](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_foreach)
 *
 * @endinternal
 *
 */
Salle salleParser(json_t* json_salle) {
    json_t* nom = json_object_get(json_salle, "nom");
    json_t* json_arr_c = json_object_get(json_salle, "creneaux");
    assert(json_is_string(nom) && json_is_array(json_arr_c));
    Salle s = salleCopie((char*)json_string_value(nom));
    size_t index;
    json_t* value;
    json_array_foreach(json_arr_c, index, value) {
        if (!json_is_null(value)) {
            ajouterSalleC(s, creneauParser(value));
        }
    }
    return s;
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

char* getSalleN(Salle s) {
    return s->nom;
}

Creneau* getSalleC(Salle s) {
    return s->creneaux;
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation objet JSON de Salle
 * en utilisant l'API Jansson.
 * Pour cela, on construit un nouvel objet JSON et on
 * y attache les clés "nom" qui stocke la valeur Nom de Salle
 * et "enseignants" qui est un tableau.
 * En itérant ensuite le tableau de Creneau de Salle, on ajoute
 * à ce tableau la représentation objet JSON de chaque Creneau ou null
 * si aucun Creneau n'est instancié à l'indice itérée.
 *
 * @sa getJsonCreneau ,
 * [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) ,
 * [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)
 *
 * @endinternal
 */
json_t* getJsonSalle(Salle s) {
    json_t* root = json_object();
    json_t* json_arr = json_array();
    json_object_set_new(root, "nom", json_string(s->nom));
    json_object_set_new(root, "creneaux", json_arr);
    for (int i = 0; i < 24; i++) {
        if (s->creneaux[i] == NULL) {
            json_array_append(json_arr, json_null());
        }
        else {
            json_array_append(json_arr, getJsonCreneau(s->creneaux[i]));
        }
    }
    return root;
}

Salle setSalleN(Salle s, char* nom) {
    strcpy(s->nom, nom);
    return s;
}

/**
 * @internal
 *
 * @details
 * Si Salle est libre dans l'intervalle de Horaire,
 * on fixe sur chaque indice de l'intervalle une référence de Creneau
 * afin de la "réserver".
 *
 * @sa isFreeSalle
 *
 * @endinternal
 */
Salle ajouterSalleC(Salle s, Creneau c) {
    if (isFreeSalle(s, getCreneauH(c))) {
        for (int i = getDebut(getCreneauH(c)); i < getFin(getCreneauH(c));i++) {
            s->creneaux[i] = c;
        }
    }
    return s;
}

/**
 * @internal
 *
 * @details
 * Si un Creneau a été instancié dans l'intervalle Horaire
 * de suppression, on réinitialise le tableau dans l'intervalle par NULL
 * pour marquer Horaire comme "libre" ou "non réservé".
 *
 * @sa isEmptySalle
 *
 * @endinternal
 */
Salle supprimerSalleH(Salle s, Horaire h) {
    if (isEmptySalle(s)) {
        return s;
    }
    for (int i = getDebut(h); i <= getFin(h); i++) {
        s->creneaux[i] = NULL;
    }
    return s;
}

/**
 * @internal
 *
 * @details
 * On supprime toute référence de Creneau instancié dans l'intervalle
 * Horaire pour pouvoir y ajouter le nouveau Creneau.
 *
 * @endinternal
 */
Salle modifierSalleHC(Salle s, Horaire horaire_modifie, Creneau c) {
    supprimerSalleH(s, horaire_modifie);
    ajouterSalleC(s, c);
    return s;
}

/**
 * @internal
 *
 * @details
 * Une salle est considéré comme "libre" si dans l'intervalle Horaire
 * indiqué en paramètre, le tableau de Creneau ne contient que des références
 * NULL, c'est-à-dire qu'il ne contient aucune instance de Creneau.
 *
 * @endinternal
 */
bool isFreeSalle(Salle s, Horaire h) {
    bool isFree = true;
    for (int i = getDebut(h); i < getFin(h) && isFree; i++) {
        isFree = s->creneaux[i] == NULL;
    }
    return isFree;
}

/**
 * @internal
 *
 * @details
 * Une salle est considéré comme "vide" si elle est libre toute
 * la journée, c'est-à-dire dans l'intervalle autorisée de Horaire
 * de \f$ \llbracket 8, 20 \rrbracket \f$.
 *
 * @endinternal
 */
bool isEmptySalle(Salle s) {
    return isFreeSalle(s, horaire(8, 20));
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Imprime le Nom de l'objet Salle suivi par une représentation
 * de son tableau de Creneau qu'on itère à partir de 8 jusqu'à 20
 * pour symboliser une journée de cours.
 * L'impression suit alors le format :
 *
 * @code {.txt}
 * -----------------
 * EDT de la Salle : {Nom de Salle}
 * -----------------
 *
 * de 8h00 à 9h00
 * VIDE                             //< si la référence à l'indice itéré est NULL
 *
 * de 9h00 à 10h00
 * {Enseignant de Creneau}          //< si la référence à l'indice itéré
 * {Formation de Creneau}               est un Creneau
 *
 * ...
 * @endcode
 *
 * @sa afficheHoraire , afficheEnseignant , getCreneauE , getCreneauF , Creneau
 *
 * @endinternal
 */
void afficheSalle(Salle s) {
    printf("-----------------\n");
    printf("EDT de la Salle : %s\n", getSalleN(s));
    printf("-----------------\n\n");
    for (int i = 8;i < 20;i++) {
        printf("de ");
        afficheHoraire(horaire(i, i + 1));
        if (s->creneaux[i] == NULL) {
            printf("VIDE");
        }
        else {
            afficheEnseignant(getCreneauE(s->creneaux[i]));
            printf("%s\n%s", getCreneauENS(s->creneaux[i]), getCreneauF(s->creneaux[i]));
        }
        printf("\n\n");
    }
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation JSON en chaîne de caractères
 * de Salle en utilisant l'API Jansson.
 * Pour cela, on accède d'abord à la représentation JSON
 * objet pour pouvoir le repasser à l'API.
 * Enfin, avant de renvoyer la chaîne de caractères, il
 * ne faut pas oublier de libérer la mémoire allouée à
 * l'objet JSON (à faire manuellement en décrémentant son
 * nombre de référencement).
 *
 * @sa [json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) ,
 * [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)
 *
 * @endinternal
 */
char* toStringSalle(Salle s) {
    json_t* json_salle = getJsonSalle(s);
    char* str = json_dumps(json_salle, 0);
#ifdef DEBUG
    puts(str);
#endif
    // deallocation json object memory
    json_decref(json_salle);

    return str;
}


/************************************************************\
*                  Tests unitaires de Salle                  *
\************************************************************/

#ifdef TEST

int main() {

    // init

    char* s1_nom = "103";
    char* s2_nom = "118";

    Horaire h1 = horaire(8, 9);
    Horaire h2 = horaire(15, 17);

    Creneau c1 = creneau(enseignantCopie("TRUILLET", "Philippe"), h1, "Structure de données", "CUPGE", s1_nom);
    Creneau c2 = creneau(enseignantCopie("GAILDRAT", "Véronique"), h2, "Programmation orientée objet", "CUPGE", s2_nom);

    // testing

    Salle s = salleCopie(s1_nom);

    info(ajouterSalleC(s, c2));
    test(isFreeSalle(s, h1) == true);

    info(ajouterSalleC(s, c1));
    test(isFreeSalle(s, h1) == false);

    info(afficheSalle(s));

    info(modifierSalleHC(s, h1, c2));

    test(isFreeSalle(s, h1) == true);
    test(isFreeSalle(s, h2) == false);

    test(isEmptySalle(s) == false);

    info(supprimerSalleH(s, h2));

    test(isFreeSalle(s, h2) == true);

    test(isEmptySalle(s) == true);

    info(afficheSalle(s));

    info(ajouterSalleC(s, c2));
    test(strcmp(toStringSalle(s), toStringSalle(salleParser(getJsonSalle(s)))) == 0);

    return 0;
}

#endif