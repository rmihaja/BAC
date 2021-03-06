/**
 * @file enseignants.c
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief Code source de la structure de données Enseignants.
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "enseignants.h"

#ifdef DEBUG
#include "tests.h"
#endif


 /************************************************************\
 *                  Strutures de Enseignants                  *
 \************************************************************/

 /**
  * @internal
  *
  * @struct s_element_es
  * @brief Structure représentant un élément de la liste chaînée Enseignants.
  * @details
  * Structure permettant de stocker un élément de la liste des Enseignants,
  * en stockant la référence de Enseignant puis l'élément suivant.
  *
  * @endinternal
  */
typedef struct s_element_es {
    Enseignant e;                   /*!< Référence de Enseignant à stocker */
    struct s_element_es* suivant;   /*!< Référence de l'élément suivant
                                         de la liste des Enseignants */
}*ElementEs;

/**
 * @internal
 *
 * @struct s_enseignants
 * @brief Structure représentant une liste chaînée de Enseignant.
 * @details
 * Structure permettant de représenter une liste chaînée d'éléments
 * contenant un objet Enseignant, avec un accès constant de
 * la tête de liste, à l'aide d'une sentinelle, et de sa taille.
 *
 * @endinternal
 */
struct s_enseignants {
    ElementEs sentinelle;           /*!< Sentinelle de l'objet Enseignants */
    int taille;                     /*!< Taille de l'objet Enseignants excluant la Sentinelle */
};


/************************************************************\
*               Constructeurs de Enseignants                 *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet Enseignants.
 *
 * @endinternal
 */
Enseignants enseignants() {
    Enseignants es = (Enseignants)malloc(sizeof(struct s_enseignants));
    es->sentinelle = (ElementEs)malloc(sizeof(struct s_element_es));
    es->sentinelle->suivant = es->sentinelle;
    es->taille = 0;
    return es;
}

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet ElementEs, élément de la liste
 * Enseignants, stockant l'objet Enseignant passé en paramètre.
 *
 * @endinternal
 */
ElementEs elementEs(Enseignant e) {
    ElementEs e_es = (ElementEs)malloc(sizeof(struct s_element_es));
    e_es->e = e;
    return e_es;
}

/**
 * @internal
 *
 * @details
 * Construit l'objet Enseignants en manipulant l'API Jansson.
 * Pour cela, à partir d'une recherche par clé (s'il existe)
 * de "enseignants", nous pouvons obtenir un tableau de Enseignant.
 * Ensuite, on itère le tableau pour pouvoir ajouter chaque Enseignant
 * à l'objet Enseignants, en faisant chaque fois appel à son constructeur
 * à partir de la valeur renvoyée par l'API.
 *
 * @sa enseignantParser ,
 * [json_array_foreach](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_foreach)
 *
 * @endinternal
 *
 */
Enseignants enseignantsParser(json_t* json_enseignants) {
    assert(json_is_array(json_enseignants));
    Enseignants es = enseignants();
    size_t index;
    json_t* value;
    json_array_foreach(json_enseignants, index, value) {
        ajouterEs(es, enseignantParser(value));
    }
    return es;
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Itère parmi la liste des Enseignants jusqu'à trouver
 * un Enseignant dont l'attribut Nom correspond au paramètre.
 * Sinon, renvoie une erreur.
 *
 * @endinternal
 */
Enseignant getEnseignantByNom(Enseignants es, char* nom) {
    bool isFound = false;
    ElementEs courant = es->sentinelle;
    for (int i = 0; i < sizeEnseignants(es) && !isFound; i++) {
        courant = courant->suivant;
        isFound = strcmp(nom, getNom(courant->e)) == 0;
    }
    assert(isFound);
    return courant->e;
}

/**
 * @internal
 *
 * @details
 * Itère parmi la liste des Enseignants jusqu'à trouver
 * un Enseignant dont Prenom correspond au paramètre.
 * Sinon renvoie une erreur.
 *
 * @endinternal
 */
Enseignant getEnseignantByPrenom(Enseignants es, char* prenom) {
    bool isFound = false;
    ElementEs courant = es->sentinelle;
    for (int i = 0; i < sizeEnseignants(es) && !isFound; i++) {
        courant = courant->suivant;
        isFound = strcmp(prenom, getPrenom(courant->e)) == 0;
    }
    assert(isFound);
    return courant->e;
}

Enseignant getEnseignantByIndice(Enseignants es, int indice) {
    assert(0 <= indice && indice < sizeEnseignants(es));
    ElementEs courant = es->sentinelle->suivant;
    for (int i = 0; i < indice; i++) {
        courant = courant->suivant;
    }
    return courant->e;
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation objet JSON de Enseignants
 * en utilisant l'API Jansson.
 * Pour cela, on construit un nouvel objet JSON et on
 * y attache la clé "enseignants" qui est un tableau.
 * En itérant ensuite la liste des Enseignants, on ajoute
 * à ce tableau la représentation objet JSON de chaque Enseignant.
 *
 * @sa getJsonEnseignant ,
 * [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) ,
 * [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)
 *
 * @endinternal
 */
json_t* getJsonEnseignants(Enseignants es) {
    json_t* root = json_array();
    ElementEs courant = es->sentinelle->suivant;
    for (int i = 0; i < sizeEnseignants(es); i++) {
        json_array_append(root, getJsonEnseignant(courant->e));
        courant = courant->suivant;
    }
    return root;
}

int sizeEnseignants(Enseignants es) {
    return es->taille;
}

/**
 * @internal
 *
 * @details
 * Vérifie par itération si un élément Enseignant de la liste
 * des Enseignants est égale à l'objet Enseignant passé en paramètre.
 *
 * @endinternal
 */
bool appartientEnseignants(Enseignants es, Enseignant e) {
    bool isEqual = false;
    ElementEs courant = es->sentinelle->suivant;
    for (int i = 0; i < sizeEnseignants(es) && !isEqual; i++) {
        isEqual = equalsEnseignant(courant->e, e);
        courant = courant->suivant;
    }
    return isEqual;
}

/**
 * @internal
 *
 * @details
 * Ajoute Enseignants à la tête de la liste des Enseignants
 * si Enseignant n'en fait pas encore parti. Si non,
 * on renvoie une erreur.
 *
 * @sa appartientEnseignants
 *
 * @endinternal
 */
Enseignants ajouterEs(Enseignants es, Enseignant e) {
    assert(!appartientEnseignants(es, e));
    ElementEs e_es = elementEs(e);
    e_es->suivant = es->sentinelle->suivant;
    es->sentinelle->suivant = e_es;
    es->taille++;
    return es;
}

/**
 * @internal
 *
 * @details
 * Vérifie d'abord que la liste ne soit pas vide.
 * Ensuite, On itère jusqu'à ce qu'on trouve un élément de
 * la liste des Enseignants dont l'objet Enseignant stocké
 * est égale à celui en paramètre.
 * Dans ce cas, on l'isole de la liste chaînée pour pouvoir
 * libérer sa mémoire.
 * Sinon, aucun élément ne sera supprimé.
 *
 * @endinternal
 */
Enseignants supprimerEs(Enseignants es, Enseignant e) {
    assert(!sizeEnseignants(es) == 0);
    ElementEs precedent = es->sentinelle;
    ElementEs courant = es->sentinelle->suivant;
    int i = 0;
    while (!equalsEnseignant(e, courant->e) && (i < sizeEnseignants(es))) {
        precedent = courant;
        courant = courant->suivant;
        i++;
    }
    if (equalsEnseignant(e, courant->e)) {
        precedent->suivant = courant->suivant;
        free(courant);
        es->taille--;
    }
    return es;
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Itère la liste des Enseignants pour pouvoir afficher chaque
 * Enseignant à partir de sa représentation externe sur stdout,
 * précédé de son indice dans la liste si l'ordre est paramétré à
 * True, ou d'un tiret sinon.
 * L'impression suit alors le format :
 *
 * @code {.txt}
 * - {Enseignant}
 * - {Enseignant}
 * ...
 * @endcode
 * ou :
 * @code {.txt}
 * 1) {Enseignant}
 * 2) {Enseignant}
 * ...
 * @endcode
 *
 * @sa afficheEnseignant
 *
 * @endinternal
 */
void afficherEnseignants(Enseignants es, bool isOrdered) {
    ElementEs courant = es->sentinelle->suivant;
    for (int i = 0; i < sizeEnseignants(es);i++) {
        if (isOrdered) {
            printf("%d) ", i + 1);
        }
        else {
            printf("- ");
        }
        afficheEnseignant(courant->e);
        courant = courant->suivant;
    }
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation JSON en chaîne de caractères
 * de Enseignants en utilisant l'API Jansson.
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
char* toStringEnseignants(Enseignants es) {
    json_t* json_enseignants = getJsonEnseignants(es);
    char* str = json_dumps(json_enseignants, 0);
#ifdef DEBUG
    puts(str);
#endif
    // deallocate json object memory
    json_decref(json_enseignants);
    return str;
}


/************************************************************\
*               Tests unitaires de Enseignants               *
\************************************************************/

#ifdef TEST
#include <string.h>

int main() {

    // init

    char* e1_nom = "TRUILLET";
    char* e2_nom = "GAILDRAT";
    char* e1_prenom = "Philippe";
    char* e2_prenom = "Véronique";
    Enseignant e1 = enseignantCopie(e1_nom, e1_prenom);
    Enseignant e2 = enseignantCopie(e2_nom, e2_prenom);

    // testing

    Enseignants es = enseignants();

    info(ajouterEs(es, e1));
    info(ajouterEs(es, e2));

    test(equalsEnseignant(getEnseignantByNom(es, e2_nom), e2));
    test(equalsEnseignant(getEnseignantByPrenom(es, e2_prenom), e2));

    test(sizeEnseignants(es) == 2);

    test(appartientEnseignants(es, e1));
    info(supprimerEs(es, e2));
    test(!appartientEnseignants(es, e2));

    test(sizeEnseignants(es) == 1);

    info(afficherEnseignants(es, false));

    test(strcmp(toStringEnseignants(es), toStringEnseignants(enseignantsParser(getJsonEnseignants(es)))) == 0);

    return 0;
}

#endif