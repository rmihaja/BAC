/**
 * @file formation.c
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief Code source de la structure de données Formation.
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "formation.h"

#ifdef DEBUG
#include "tests.h"
#endif


 /************************************************************\
 *                  Structures de Formation                   *
 \************************************************************/

 /**
  * @internal
  *
  * @struct s_creneau_f
  * Structure permettant de stocker un élément de la liste
  * de Creneau, en stockant la référence de Creneau puis
  * l'élément suivant.
  *
  * @endinternal
  */
typedef struct s_creneau_f {
    Creneau creneau;                /*!< Référence de Creneau à stocker */
    struct s_creneau_f* suivant;     /*!< Référence de l'élément suivant
                                         de la liste de Creneau */
} *CreneauF;

/**
 * @internal
 *
 * @struct s_formation
 * @details
 * Structure permettant de stocker l'attribut nom d'une
 * formation sous forme de chaîne de caractères, ainsi
 * qu'une liste chaînée d'éléments contenant un objet
 * Creneau, avec un accès constant de la tête de liste
 * à l'aide d'une sentinelle, et de sa taille.
 *
 * @endinternal
 */
struct s_formation {
    char* nom;                      /*!< Nom de l'objet Formation */
    CreneauF sentinelle;            /*!< Sentinelle de la liste de Creneau */
    int taille;                     /*!< Taille de la liste de Creneau excluant la Sentinelle */
};


/************************************************************\
*                Constructeurs de Formation                  *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet Formation.
 *
 * @endinternal
 */
Formation formation(char* n) {
    Formation f = (Formation)malloc(sizeof(struct s_formation));
    f->sentinelle = (CreneauF)malloc(sizeof(struct s_creneau_f));
    f->sentinelle->suivant = f->sentinelle;
    f->nom = n;
    f->taille = 0;
    return f;
}

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet CreneauF, élément de la liste
 * de Creneau, stockant l'objet Creneau passé en paramètre.
 *
 * @endinternal
 */
CreneauF creneauF(Creneau c) {
    CreneauF e = (CreneauF)malloc(sizeof(struct s_creneau_f));
    e->creneau = c;
    return e;
}

/**
 * @internal
 *
 * @details
 * Construit l'objet Salles en manipulant l'API Jansson.
 * Pour cela, à partir d'une recherche par clé (s'il existe),
 * nous pouvons accéder à l'attribut "nom" de Formation
 * que nous construisons à l'aide du constructeur par défaut.
 * Nous accédons ensuite à la clé "salles", qui est un tableau de Creneau.
 * On itère le tableau pour pouvoir ajouter chaque Creneau
 * à la liste de Creneau, en faisant chaque fois appel à son constructeur
 * à partir de la valeur renvoyée par l'API.
 *
 * @sa creneauParser ,
 * [json_array_foreach](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_foreach)
 *
 * @endinternal
 *
 */
Formation formationParser(json_t* json_formation) {
    json_t* nom = json_object_get(json_formation, "nom");
    json_t* json_arr_c = json_object_get(json_formation, "creneaux");
    assert(json_is_string(nom) && json_is_array(json_arr_c));
    Formation f = formation((char*)json_string_value(nom));
    size_t index;
    json_t* value;
    json_array_foreach(json_arr_c, index, value) {
        ajouterFormationC(f, creneauParser(value));
    }
    return f;
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

char* getFormationN(Formation f) {
    return f->nom;
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation objet JSON de Formation
 * en utilisant l'API Jansson.
 * Pour cela, on construit un nouvel objet JSON et on
 * y attache les clés "nom" qui stocke la valeur Nom de Formation
 * et "creneaux" qui est un tableau.
 * En itérant ensuite la liste de Creneau de Formation, on ajoute
 * à ce tableau la représentation objet JSON de chaque Creneau.
 *
 * @sa getJsonCreneau ,
 * [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) ,
 * [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)
 *
 * @endinternal
 */
json_t* getJsonFormation(Formation f) {
    json_t* root = json_object();
    json_t* json_arr = json_array();
    json_object_set_new(root, "nom", json_string(f->nom));
    json_object_set_new(root, "creneaux", json_arr);
    CreneauF courant = f->sentinelle->suivant;
    for (int i = 0; i < f->taille; i++) {
        json_array_append(json_arr, getJsonCreneau(courant->creneau));
        courant = courant->suivant;
    }
    return root;
}

int sizeFormationC(Formation f) {
    return f->taille;
}

/**
 * @internal
 *
 * @details
 * Lorsque toutes les conditions de Formation et Creneau
 * sont réunies, Creneau devient la tête de la liste de
 * Creneau.
 *
 * @sa isFullFormation , isFreeFormation
 *
 * @endinternal
 */
Formation ajouterFormationC(Formation f, Creneau c) {
    assert(!isFullFormation(f));
    assert(strcmp(getCreneauF(c), f->nom) == 0);
    assert(isFreeFormation(f, getCreneauH(c)));
    CreneauF e = creneauF(c);
    e->suivant = f->sentinelle->suivant;
    f->sentinelle->suivant = e;
    f->taille++;
    return f;
}

/**
 * @internal
 *
 * @details
 * Si un Creneau correspond à Horaire, alors on le
 * détache de la liste chaînée de Creneau.
 *
 * @warning On ne supprime qu'un et un seul Creneau dans
 * l'intervalle de Horaire, il faut alors s'assurer
 * que Horaire correspond à un et un seul Creneau de Formation.
 *
 * @sa equalsHoraire
 *
 * @endinternal
 */
Formation supprimerFormationH(Formation f, Horaire h) {
    CreneauF precedent = f->sentinelle;
    CreneauF courant = f->sentinelle->suivant;
    bool isFound = false;
    for (int i = 0; i < f->taille && !isFound; i++) {
        isFound = (equalsHoraire(getCreneauH(courant->creneau), h));
        precedent = courant;
        courant = courant->suivant;
    }
    if (isFound) {
        precedent->suivant = courant->suivant;
        free(courant);
        f->taille--;
    }
    return f;
}

/**
 * @internal
 *
 * @details
 * Une Formation est considéré comme "libre" si pour tout Creneau dans
 * sa liste de Creneau, aucune borne (Debut et Fin) de Horaire indiqué
 * en paramètre n'englobe un Horaire de Creneau et n'est dans l'intervalle
 * Horaire indiqué pour tout Creneau dans la liste de Formation.
 *
 * @endinternal
 */
bool isFreeFormation(Formation f, Horaire h) {
    bool isInCreneauH = false;
    CreneauF courant = f->sentinelle->suivant;
    for (int i = 0; i < f->taille && !isInCreneauH; i++) {
        isInCreneauH = (getDebut(getCreneauH(courant->creneau)) <= getDebut(h) && getDebut(h) <= getFin(getCreneauH(courant->creneau)))
            || (getDebut(getCreneauH(courant->creneau)) <= getFin(h) && getFin(h) <= getFin(getCreneauH(courant->creneau)))
            || (getDebut(h) <= getDebut(getCreneauH(courant->creneau)) && getFin(getCreneauH(courant->creneau)) <= getFin(h));
        courant = courant->suivant;
    }
    return !isInCreneauH;
}

/**
 * @internal
 *
 * @details
 * La taille maximale de Creneau allouable à une Formation est 4,
 * défini par la spécification du TAD.
 *
 * @endinternal
 */
bool isFullFormation(Formation f) {
    return f->taille == 4;
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Imprime le Nom de l'objet Formation suivi par une
 * représentation de sa liste de Creneau qu'on itère.
 * L'impression suit alors le format :
 *
 * @code {.txt}
 * ---------------------
 * EDT de la formation : {Nom de Formation}
 * ---------------------
 *
 * Salle {Salle de Creneau}
 * de {Horaire de Creneau}
 * {Enseignant de Creneau}
 *
 * Salle {Salle de Creneau}
 * de {Horaire de Creneau}
 * {Enseignant de Creneau}
 *
 * ...
 * @endcode
 *
 * @sa afficheHoraire , afficheEnseignant
 *
 * @endinternal
 */
void afficheFormation(Formation f) {
    printf("---------------------\n");
    printf("EDT de la formation : %s\n", getFormationN(f));
    printf("---------------------\n\n");
    CreneauF courant = f->sentinelle->suivant;
    for (int i = 0;i < f->taille;i++) {
        printf("Salle %s\n", getCreneauS(courant->creneau));
        printf("de ");
        afficheHoraire(getCreneauH(courant->creneau));
        afficheEnseignant(getCreneauE(courant->creneau));
        courant = courant->suivant;
        printf("\n");
    }
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation JSON en chaîne de caractères
 * de Formation en utilisant l'API Jansson.
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
char* toStringFormation(Formation f) {
    json_t* json_formation = getJsonFormation(f);
    char* str = json_dumps(json_formation, 0);
#ifdef DEBUG
    puts(str);
#endif
    // deallocation json object memory
    json_decref(json_formation);
    return str;
}


/************************************************************\
*                Tests unitaires de Formation                *
\************************************************************/

#ifdef TEST

int main() {

    // init

    Horaire h1 = horaire(13, 15);
    Enseignant e1 = enseignant("TRUILLET", "Structure de données");
    char* f1_nom = "CUPGE";
    char* s1 = "118";

    Horaire h2 = horaire(16, 18);
    Enseignant e2 = enseignant("GAILDRAT", "Programmation orientée objet");
    char* f2_nom = "L2 Informatique";
    char* s2 = "103";

    Creneau c1 = creneau(e1, h1, f1_nom, s1);
    Creneau c1_bis = creneau(e2, h1, f1_nom, s2);
    Creneau c2 = creneau(e2, h2, f2_nom, s2);
    Creneau c2_bis = creneau(e2, h2, f1_nom, s2);

    // testing

    Formation f = formation(f1_nom);

    // info(ajouterFormationC(f, c2)); // devrait produire une erreur

    info(ajouterFormationC(f, c1));

    info(afficheFormation(f));

    // info(ajouterFormationC(f, c1_bis)); // devrait produire une erreur

    // info(ajouterFormationC(f, c1));
    // info(ajouterFormationC(f, c1));
    // info(ajouterFormationC(f, c1));

    test(isFullFormation(f) == false);

    // info(supprimerFormationH(f, h2)); // devrait produire une erreur
    info(supprimerFormationH(f, h1));

    info(ajouterFormationC(f, c2_bis));

    test(strcmp(toStringFormation(f), toStringFormation(formationParser(getJsonFormation(f)))) == 0);

    return 0;
}

#endif