/**
 * @file formations.c
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief Code source de la structure de données Formations.
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "formations.h"

#ifdef DEBUG
#include "tests.h"
#endif

 /************************************************************\
 *                  Structure de Formations                   *
 \************************************************************/

 /**
  * @internal
  *
  * @struct s_formations
  * @brief Structure représentant un tableau de Formation.
  * @details
  * Structure permettant de stocker un tableau de Formation marqué
  * par l'adresse de sa première indice et sa taille.
  *
  * @endinternal
  */
struct s_formations {
    Formation* formations;          /*!< Adresse du premier élément du tableau de Formation */
    int taille;                     /*!< Taille du tableau de Formation */
    int capacite;                   /*!< Taille maximalle du tableau de Formation */
};


/************************************************************\
*                Constructeurs de Formations                 *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet Formations.
 *
 * @endinternal
 */
Formations formations(int taille_max) {
    Formations fs = (Formations)malloc(sizeof(struct s_formations));
    fs->formations = (Formation*)malloc(taille_max * sizeof(Formation));
    fs->taille = 0;
    fs->capacite = taille_max;
    return fs;
}

/**
 * @internal
 *
 * @details
 * Construit l'objet Formations en manipulant l'API Jansson.
 * Pour cela, à partir d'une recherche par clé (s'il existe)
 * de "formations", nous pouvons obtenir un tableau de Formation.
 * Ensuite, on itère le tableau pour pouvoir ajouter chaque Formation
 * à l'objet Formations, en faisant chaque fois appel à son constructeur
 * à partir de la valeur renvoyée par l'API.
 *
 * @sa [json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string) ,
 * [json_array_foreach](https://jansson.readthedocs.pio/en/latest/apiref.html#c.json_array_foreach)
 *
 * @endinternal
 */
Formations formationsParser(json_t* json_formations) {
    assert(json_is_array(json_formations));
    Formations fs = formations((int)json_array_size(json_formations));
    size_t index;
    json_t* value;
    json_array_foreach(json_formations, index, value) {
        ajouterFs(fs, formationParser(value));
    }
    return fs;
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

Formation getFormationByIndice(Formations fs, int indice) {
    assert(0 <= indice && indice < sizeFormations(fs));
    return fs->formations[indice];
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation objet JSON de Formations
 * en utilisant l'API Jansson.
 * Pour cela, on construit un nouvel tableau JSON et
 * en itérant la liste des Formations, on ajoute
 * à ce tableau l'attribut Nom de chaque Formation.
 *
 * @sa [json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string) ,
 * [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) ,
 * [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)
 *
 * @endinternal
 */
json_t* getJsonFormations(Formations fs) {
    json_t* root = json_array();
    for (int i = 0; i < sizeFormations(fs); i++) {
        json_array_append(root, getJsonFormation(fs->formations[i]));
    }
    return root;
}

int sizeFormations(Formations fs) {
    return fs->taille;
}

/**
 * @internal
 *
 * @details
 * Vérifie par itération si un Nom de Formation de Formations
 * est égale au Nom de Formation passé en paramètre.
 *
 * @endinternal
 */
bool appartientFormations(Formations fs, char* nom) {
    bool isEqual = false;
    for (int i = 0; i < sizeFormations(fs) && !isEqual; i++) {
        isEqual = strcmp(getFormationN(fs->formations[i]), nom) == 0;
    }
    return isEqual;
}

/**
 * @internal
 *
 * @details
 * Ajoute Formations à la tête de la liste des Formations
 * si Formation n'en fait pas encore parti. Si non,
 * on renvoie une erreur.
 *
 * @sa appartientFormations
 *
 * @endinternal
 */
Formations ajouterFs(Formations fs, Formation f) {
    assert(!appartientFormations(fs, getFormationN(f)));
    assert(fs->taille + 1 <= fs->capacite);
    fs->formations[sizeFormations(fs)] = f;
    fs->taille++;
    return fs;
}

/************************************************************\
*                 Représentations externes                   *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Itère la liste des Formations pour pouvoir afficher chaque
 * Formation à partir de sa représentation externe sur stdout.
 * L'impression suit alors le format :
 *
 * @code {.txt}
 * {Formation}
 *
 * {Formation}
 *
 * ...
 * @endcode
 *
 * @sa afficheFormation
 *
 * @endinternal
 */
void afficherFormations(Formations fs) {
    for (int i = 0; i < sizeFormations(fs); i++) {
        afficheFormation(fs->formations[i], false);
    }
}

/**
 * @internal
 *
 * @details
 * Itère la liste des Formations pour pouvoir afficher le Nom de
 * chaque Formation sur stdout, précédé de son indice dans la liste
 * si l'ordre est paramétré à True, ou d'un tiret sinon.
 * L'impression suit alors le format :
 *
 * @code {.txt}
 * - {Nom de Formation}
 * - {Nom de Formation}
 * ...
 * @endcode
 *
 * ou :
 *
 * @code {.txt}
 * 1) {Nom de Formation}
 * 2) {Nom de Formation}
 * ...
 * @endcode
 *
 * @sa getFormationN
 *
 * @endinternal
 */
void afficherFormationsN(Formations fs, bool isOrdered) {
    for (int i = 0; i < sizeFormations(fs); i++) {
        if (isOrdered) {
            printf("%d) %s\n", i + 1, getFormationN(fs->formations[i]));
        }
        else {
            printf("- %s\n", getFormationN(fs->formations[i]));
        }
    }
}

/************************************************************\
*               Tests unitaires de Formations                *
\************************************************************/

#ifdef TEST

int main() {

    // init

    char* f1_nom = "CUPGE";
    char* f2_nom = "L2 Informatique";

    Formation f1 = formation(f1_nom);
    Formation f2 = formation(f2_nom);

    // testing

    Formations F = formations(2);

    info(ajouterFs(F, f1));
    test(appartientFormations(F, getFormationN(f1)));
    test(getFormationByIndice(F, 0) == f1);
    // info(ajouterFs(F, f1)); // devrait produire une erreur

    info(ajouterFs(F, f2));
    test(getFormationByIndice(F, 1) == f2);
    test(getFormationByIndice(F, 0) == f1);

    info(afficherFormations(F));
    return 0;
}

#endif