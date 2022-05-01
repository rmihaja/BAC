/**
 * @file enseignements.c
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief Code source de la structure de données Enseignements.
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "enseignements.h"

#ifdef DEBUG
#include "tests.h"
#endif


 /************************************************************\
 *                Strutures de Enseignements                  *
 \************************************************************/

 /**
  * @internal
  *
  * @struct s_enseignement
  * @brief Structure représentant un élément de la liste chaînée Enseignements.
  * @details
  * Structure permettant de stocker un élément de la liste des Enseignements,
  * en stockant la référence de Enseignement puis l'élément suivant.
  *
  * @endinternal
  */
typedef struct s_enseignement {
    char nom[BUFSIZ];                   /*!< Référence du nom de Enseignement à stocker */
    struct s_enseignement* suivant;     /*!< Référence de l'élément suivant
                                         de la liste des Enseignements */
}*Enseignement;

/**
 * @internal
 *
 * @struct s_enseignements
 * @brief Structure représentant une liste chaînée de Enseignement.
 * @details
 * Structure permettant de représenter une liste chaînée d'éléments
 * contenant un objet Enseignement, avec un accès constant de
 * la tête de liste, à l'aide d'une sentinelle, et de sa taille.
 *
 * @endinternal
 */
struct s_enseignements {
    Enseignement sentinelle;            /*!< Sentinelle de l'objet Enseignements */
    int taille;                         /*!< Taille de l'objet Enseignements excluant la Sentinelle */
};


/************************************************************\
*             Constructeurs de Enseignements                 *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet Enseignements.
 *
 * @endinternal
 */
Enseignements enseignements() {
    Enseignements ens = (Enseignements)malloc(sizeof(struct s_enseignements));
    ens->sentinelle = (Enseignement)malloc(sizeof(struct s_enseignement));
    ens->sentinelle->suivant = ens->sentinelle;
    ens->taille = 0;
    return ens;
}

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet Enseignement, élément de la liste
 * Enseignements, stockant la valeur Nom de Enseignement passé en paramètre.
 *
 * @endinternal
 */
Enseignement enseignement(char* nom) {
    Enseignement e_ens = (Enseignement)malloc(sizeof(struct s_enseignement));
    strcpy(e_ens->nom, nom);
    return e_ens;
}

/**
 * @internal
 *
 * @details
 * Construit l'objet Enseignements en manipulant l'API Jansson.
 * Pour cela, on vérifie d'abord que json_enseignements est bien
 * un tableau de caractère possédant le nom de chaque Enseignement.
 * On itère alors le tableau pour pouvoir ajouter chaque nom de Enseignement
 * à l'objet Enseignements, à partir de la valeur renvoyée par l'API.
 *
 * @sa [json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string) ,
 * [json_array_foreach](https://jansson.readthedocs.pio/en/latest/apiref.html#c.json_array_foreach)
 *
 * @endinternal
 *
 */
Enseignements enseignementsParser(json_t* json_enseignements) {
    assert(json_is_array(json_enseignements));
    Enseignements ens = enseignements();
    size_t index;
    json_t* value;
    json_array_foreach(json_enseignements, index, value) {
        ajouterEns(ens, (char*)json_string_value(value));
    }
    return ens;
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

char* getEnseignementByIndice(Enseignements ens, int indice) {
    assert(0 <= indice && indice < sizeEnseignements(ens));
    Enseignement courant = ens->sentinelle->suivant;
    for (int i = 0; i < indice; i++) {
        courant = courant->suivant;
    }
    return courant->nom;
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation objet JSON de Enseignements
 * en utilisant l'API Jansson.
 * Pour cela, on construit un nouvel tableau JSON et
 * en itérant la liste des Enseignements, on ajoute
 * à ce tableau l'attribut Nom de chaque Enseignement.
 *
 * @sa [json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string) ,
 * [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) ,
 * [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)
 *
 * @endinternal
 */
json_t* getJsonEnseignements(Enseignements ens) {
    json_t* root = json_array();
    Enseignement courant = ens->sentinelle->suivant;
    for (int i = 0; i < sizeEnseignements(ens); i++) {
        json_array_append(root, json_string(courant->nom));
        courant = courant->suivant;
    }
    return root;
}

int sizeEnseignements(Enseignements ens) {
    return ens->taille;
}

/**
 * @internal
 *
 * @details
 * Vérifie par itération si un Nom de Enseignement de la liste
 * des Enseignements est égale au Nom de Enseignement passé en paramètre.
 *
 * @endinternal
 */
bool appartientEnseignements(Enseignements ens, char* nom) {
    bool isEqual = false;
    Enseignement courant = ens->sentinelle->suivant;
    for (int i = 0; i < sizeEnseignements(ens) && !isEqual; i++) {
        isEqual = strcmp(courant->nom, nom) == 0;
        courant = courant->suivant;
    }
    return isEqual;
}

/**
 * @internal
 *
 * @details
 * Ajoute Enseignements à la tête de la liste des Enseignements
 * si Enseignement n'en fait pas encore parti. Si non,
 * on renvoie une erreur.
 *
 * @sa appartientEnseignements
 *
 * @endinternal
 */
Enseignements ajouterEns(Enseignements ens, char* nom) {
    assert(!appartientEnseignements(ens, nom));
    Enseignement e_ens = enseignement(nom);
    e_ens->suivant = ens->sentinelle->suivant;
    ens->sentinelle->suivant = e_ens;
    ens->taille++;
    return ens;
}

/**
 * @internal
 *
 * @details
 * Vérifie d'abord que la liste ne soit pas vide.
 * Ensuite, On itère jusqu'à ce qu'on trouve un élément de
 * la liste des Enseignements dont le Nom de Enseignement stocké
 * est égale à celui en paramètre.
 * Dans ce cas, on l'isole de la liste chaînée pour pouvoir
 * libérer sa mémoire.
 * Sinon, aucun élément ne sera supprimé.
 *
 * @endinternal
 */
Enseignements supprimerEns(Enseignements ens, char* nom) {
    assert(!sizeEnseignements(ens) == 0);
    Enseignement precedent = ens->sentinelle;
    Enseignement courant = ens->sentinelle->suivant;
    int i = 0;
    while (strcmp(nom, courant->nom) && (i < sizeEnseignements(ens))) {
        precedent = courant;
        courant = courant->suivant;
        i++;
    }
    if (strcmp(nom, courant->nom) == 0) {
        precedent->suivant = courant->suivant;
        free(courant);
        ens->taille--;
    }
    return ens;
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Itère la liste des Enseignements pour pouvoir afficher le Nom de
 * chaque Enseignement sur stdout, précédé de son indice dans la liste
 * si l'ordre est paramétré à True, ou d'un tiret sinon.
 * L'impression suit alors le format :
 *
 * @code {.txt}
 * - {Nom de Enseignement}
 * - {Nom de Enseignement}
 * ...
 * @endcode
 * ou :
 * @code {.txt}
 * 1) {Nom de Enseignement}
 * 2) {Nom de Enseignement}
 * ...
 * @endcode
 *
 * @endinternal
 */
void afficherEnseignements(Enseignements ens, bool isOrdered) {
    Enseignement courant = ens->sentinelle->suivant;
    for (int i = 0; i < sizeEnseignements(ens);i++) {
        if (isOrdered) {
            printf("%d) %s\n", i + 1, courant->nom);
        }
        else {
            printf("- %s\n", courant->nom);
        }
        courant = courant->suivant;
    }
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation JSON en chaîne de caractères
 * de Enseignements en utilisant l'API Jansson.
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
char* toStringEnseignements(Enseignements ens) {
    json_t* json_enseignements = getJsonEnseignements(ens);
    char* str = json_dumps(json_enseignements, 0);
#ifdef DEBUG
    puts(str);
#endif
    // deallocate json object memory
    json_decref(json_enseignements);
    return str;
}


/************************************************************\
*             Tests unitaires de Enseignements               *
\************************************************************/

#ifdef TEST

int main() {

    // init

    char* ens1_nom = "Structure de données";
    char* ens2_nom = "Programmation orientée objet";

    // testing

    Enseignements ens = enseignements();

    info(ajouterEns(ens, ens1_nom));
    info(ajouterEns(ens, ens2_nom));

    test(strcmp(getEnseignementByIndice(ens, 1), ens1_nom) == 0);

    test(sizeEnseignements(ens) == 2);

    test(appartientEnseignements(ens, ens1_nom));
    info(supprimerEns(ens, ens2_nom));
    test(!appartientEnseignements(ens, ens2_nom));

    test(sizeEnseignements(ens) == 1);

    info(afficherEnseignements(ens, false));

    test(strcmp(toStringEnseignements(ens), toStringEnseignements(enseignementsParser(getJsonEnseignements(ens)))) == 0);

    return 0;
}

#endif