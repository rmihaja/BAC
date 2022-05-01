/**
 * @file salles.c
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief Code source de la structure de données Salles.
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "salles.h"

#ifdef DEBUG
#include "tests.h"
#endif


 /************************************************************\
 *                    Structures de Salles                    *
 \************************************************************/

 /**
  * @internal
  *
  * @struct s_element_ss
  * @brief Structure représentant un élément de la liste chaînée Salles.
  * @details
  * Structure permettant de stocker un élément de la liste des
  * Salles, en stockant la référence de Salle puis l'élément
  * suivant.
  *
  * @endinternal
  */
typedef struct s_element_ss {
    Salle s;                        /*!< Référence de Salle à stocker */
    struct s_element_ss* suivant;   /*!< Référence de l'élément suivant
                                         de la liste des Salles */
}*ElementSs;

/**
 * @internal
 *
 * @struct s_salles
 * @brief Structure représentant une liste chaînée de Salle.
 *
 * @details
 * Structure permettant de représenter une liste chaînée d'éléments
 * contenant un objet Salle, avec un accès constant de la tête de liste,
 * à l'aide d'une sentinelle, et de sa taille.
 *
 * @endinternal
 */
struct s_salles {
    ElementSs sentinelle;           /*!< Sentinelle de l'objet Salles */
    int taille;                     /*!< Taille de l'objet Salles excluant la Sentinelle */
};


/************************************************************\
*                 Constructeurs de Salles                    *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet Salles.
 *
 * @endinternal
 */
Salles salles() {
    Salles ss = (Salles)malloc(sizeof(struct s_salles));
    ss->sentinelle = (ElementSs)malloc(sizeof(struct s_element_ss));
    ss->sentinelle->suivant = ss->sentinelle;
    ss->taille = 0;
    return ss;
}

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet ElementSs, élément de la liste
 * Salles, stockant l'objet Salle passé en paramètre.
 *
 * @endinternal
 */
ElementSs elementSs(Salle s) {
    ElementSs e_ss = (ElementSs)malloc(sizeof(struct s_element_ss));
    e_ss->s = s;
    return e_ss;
}

/**
 * @internal
 *
 * @details
 * Construit l'objet Salles en manipulant l'API Jansson.
 * Pour cela, à partir d'une recherche par clé (s'il existe)
 * de "salles", nous pouvons obtenir un tableau de Salle.
 * Ensuite, on itère le tableau pour pouvoir ajouter chaque Salle
 * à l'objet Salles, en faisant chaque fois appel à son constructeur
 * à partir de la valeur renvoyée par l'API.
 *
 * @sa salleParser ,
 * [json_array_foreach](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_foreach)
 *
 * @endinternal
 *
 */
Salles sallesParser(json_t* json_salles) {
    assert(json_is_array(json_salles));
    Salles ss = salles();
    size_t index;
    json_t* value;
    json_array_foreach(json_salles, index, value) {
        ajouterSs(ss, salleParser(value));
    }
    return ss;
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Itère parmi la liste des Salles jusqu'à trouver une Salle
 * dont l'attribut Nom correspond au paramètre.
 * Sinon, renvoie une erreur.
 *
 * @endinternal
 */
Salle getSalleByNom(Salles ss, char* nom) {
    bool isFound = false;
    ElementSs courant = ss->sentinelle;
    for (int i = 0;i < sizeSalles(ss) && !isFound; i++) {
        courant = courant->suivant;
        isFound = strcmp(nom, getSalleN(courant->s)) == 0;
    }
    assert(isFound);
    return courant->s;
}

/**
 * @internal
 *
 * @details
 * Itère parmi la liste des Salles Indice fois
 * puis renvoie la référence de Salle stockée
 * par l'élément courant.
 *
 * @endinternal
 */
Salle getSalleByIndice(Salles ss, int indice) {
    assert(0 <= indice && indice < sizeSalles(ss));
    ElementSs courant = ss->sentinelle->suivant;
    for (int i = 0;i < indice;i++) {
        courant = courant->suivant;
    }
    return courant->s;
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation objet JSON de Salles
 * en utilisant l'API Jansson.
 * Pour cela, on construit un nouvel objet JSON et on y
 * attache la clé "salles" qui est un tableau.
 * En itérant ensuite la liste des Salles, on ajoute à
 * ce tableau la représentation objet JSON de chaque Salle.
 *
 * @sa getJsonSalle ,
 * [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) ,
 * [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)
 *
 * @endinternal
 */
json_t* getJsonSalles(Salles ss) {
    json_t* root = json_array();
    ElementSs courant = ss->sentinelle->suivant;
    for (int i = 0; i < sizeSalles(ss); i++) {
        json_array_append(root, getJsonSalle(courant->s));
        courant = courant->suivant;
    }
    return root;
}

int sizeSalles(Salles ss) {
    return ss->taille;
}

/**
 * @internal
 *
 * @details
 * Vérifie par itération si un élément Salle de la liste
 * des Salles est égale à l'objet Salle passé en paramètre.
 * Deux Salle sont considérés égaux s'ils ont le même nom.
 *
 * @endinternal
 */
bool appartientSalles(Salles ss, Salle s) {
    bool isEqual = false;
    ElementSs courant = ss->sentinelle->suivant;
    for (int i = 0; i < sizeSalles(ss) && !isEqual; i++) {
        isEqual = strcmp(getSalleN(courant->s), getSalleN(s)) == 0;
        courant = courant->suivant;
    }
    return isEqual;
}

/**
 * @internal
 *
 * @details
 * Ajoute Salle à la tête de la liste des Salles
 * si Salle n'en fait pas encore parti. Si non,
 * on renvoie une erreur.
 *
 * @sa appartientSalles
 *
 * @endinternal
 */
Salles ajouterSs(Salles ss, Salle s) {
    assert(!appartientSalles(ss, s));
    ElementSs e_ss = elementSs(s);
    e_ss->suivant = ss->sentinelle->suivant;
    ss->sentinelle->suivant = e_ss;
    ss->taille++;
    return ss;
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Itère la liste des Salles pour pouvoir afficher chaque
 * Salle à partir de sa représentation externe sur stdout.
 * L'impression suit alors le format :
 *
 * @code {.txt}
 * {Salle}
 *
 * {Salle}
 *
 * ...
 * @endcode
 *
 * @sa afficheSalle
 *
 * @endinternal
 */
void afficherSalles(Salles ss) {
    ElementSs courant = ss->sentinelle->suivant;
    for (int i = 0;i < sizeSalles(ss);i++) {
        afficheSalle(courant->s);
        courant = courant->suivant;
    }
}

void afficherSallesN(Salles ss, bool isOrdered) {
    ElementSs courant = ss->sentinelle->suivant;
    for (int i = 0;i < sizeSalles(ss);i++) {
        if (isOrdered) {
            printf("%d) %s\n", i + 1, getSalleN(courant->s));
        }
        else {
            printf("- %s\n", getSalleN(courant->s));
        }
        courant = courant->suivant;
    }
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation JSON en chaîne de caractères
 * de Salles en utilisant l'API Jansson.
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
char* toStringSalles(Salles ss) {
    json_t* json_salles = getJsonSalles(ss);
    char* str = json_dumps(json_salles, 0);
#ifdef DEBUG
    puts(str);
#endif
    // deallocation json object memory
    json_decref(json_salles);
    return str;
}


/************************************************************\
*                 Tests unitaires de Salles                  *
\************************************************************/

#ifdef TEST

int main() {

    // init

    char* s1_nom = "118";
    char* s2_nom = "103";

    Salle s1 = salleCopie(s1_nom);
    Salle s2 = salleCopie(s2_nom);

    // testing

    Salles S = salles();

    // info(getSalleByNom(S, s1_nom)); // devrait produire une erreur

    info(ajouterSs(S, s1));
    test(appartientSalles(S, s1));
    test(getSalleByNom(S, s1_nom) == s1);
    // info(ajouterSs(S, s1)); // devrait produire une erreur

    info(ajouterSs(S, s2));
    test(getSalleByNom(S, s2_nom) == s2);
    test(getSalleByNom(S, s1_nom) == s1);

    info(afficherSalles(S));

    info(toStringSalles(sallesParser(getJsonSalles(S))));

    return 0;
}

#endif