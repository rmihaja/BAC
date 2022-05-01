/**
 * @file enseignant.c
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief Code source de la structure de données Enseignant.
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "enseignant.h"

#ifdef DEBUG
#include "tests.h"
#endif


 /************************************************************\
 *                  Structure de Enseignant                   *
 \************************************************************/

 /**
  * @internal
  *
  * @struct s_enseignant
  * @details
  * Structure permettant de stocker les attributs
  * (nom et matière) d'un enseignant sous forme de
  * chaînes de caractères.
  *
  * @endinternal
  *
  */
struct s_enseignant {
    char* nom;      /*!< Nom de l'objet Enseignant. */
    char* matiere;  /*!< Matiere de l'objet Enseignant. */
};


/************************************************************\
*                Constructeurs de Enseignant                 *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet Enseignant.
 *
 * @endinternal
 */
Enseignant enseignant(char* n, char* m) {
    Enseignant e = (Enseignant)malloc(sizeof(struct s_enseignant));
    e->nom = n;
    e->matiere = m;
    return e;
}

/**
 * @internal
 *
 * @details
 * Construit l'objet Enseignant en manipulant l'API Jansson.
 * Pour cela, à partir d'une recherche par clé (s'il existe),
 * nous pouvons accéder aux attributs "nom" et "matiere" de Enseignant,
 * que nous construisons ensuite à l'aide du constructeur
 * par défaut.
 *
 * @sa [json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) ,
 * [json_object_get](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_get) ,
 * [json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string)
 *
 * @endinternal
 *
 */
Enseignant enseignantParser(json_t* json_enseignant) {
    json_t* nom = json_object_get(json_enseignant, "nom");
    json_t* matiere = json_object_get(json_enseignant, "matiere");
    assert(json_is_string(nom) && json_is_string(matiere));
    return enseignant((char*)json_string_value(nom), (char*)json_string_value(matiere));
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

char* getNom(Enseignant e) {
    return e->nom;
}

char* getMatiere(Enseignant e) {
    return e->matiere;
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation objet JSON de Enseignant
 * en utilisant l'API Jansson.
 * Pour cela, on construit un nouvel objet JSON pour ensuite
 * pouvoir y attacher les attributs clé-valeurs de Enseignant, défini par
 * "nom" et "matiere".
 *
 * @sa [json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) ,
 * [json_object_set_new](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_set_new)
 *
 * @endinternal
 */
json_t* getJsonEnseignant(Enseignant e) {
    json_t* root = json_object();
    json_object_set_new(root, "nom", json_string(getNom(e)));
    json_object_set_new(root, "matiere", json_string(getMatiere(e)));
    return root;
}

Enseignant setMatiere(Enseignant e, char* matiere) {
    e->matiere = matiere;
    return e;
}

Enseignant setNom(Enseignant e, char* n) {
    e->nom = n;
    return e;
}

bool equalsEnseignant(Enseignant e1, Enseignant e2) {
    return strcmp(getNom(e1), getNom(e2)) == 0
        && strcmp(getMatiere(e1), getMatiere(e2)) == 0;
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Imprime les attributs de l'objet Enseignant selon le format :
 *
 * @code {.txt}
 * {Nom}, {Matiere}
 * @endcode
 *
 * @endinternal
 */
void afficheEnseignant(Enseignant e) {
    printf("%s, %s\n", getNom(e), getMatiere(e));
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation JSON en chaîne de caractères
 * de Enseignant en utilisant l'API Jansson.
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
char* toStringEnseignant(Enseignant e) {
    json_t* json_enseignant = getJsonEnseignant(e);
    char* str = json_dumps(json_enseignant, 0);
#ifdef DEBUG
    puts(str);
#endif
    // deallocate json object memory
    json_decref(json_enseignant);
    return str;
}


/************************************************************\
*               Tests unitaires de Enseignant                *
\************************************************************/

#ifdef TEST

int main() {

    // init

    char* e1_nom = "TRUILLET";
    char* e2_nom = "GAILDRAT";
    char* e1_matiere = "Structure de données";
    char* e2_matiere = "Programmation orientée objet";

    // testing

    Enseignant e = enseignant(e1_nom, e1_matiere);

    info(afficheEnseignant(e)); // "TRUILLET, Structure de données"

    test(getNom(e) == e1_nom);
    test(getMatiere(e) == e1_matiere);

    info(setNom(e, e2_nom));
    info(setMatiere(e, e2_matiere));

    test(getNom(e) == e2_nom);
    test(getMatiere(e) == e2_matiere);

    test(equalsEnseignant(e, e));
    test(!equalsEnseignant(e, enseignant(e1_nom, e1_matiere)));

    info(afficheEnseignant(e)); // "GAILDRAT, Programmation orientée objet"

    test(strcmp(toStringEnseignant(e), toStringEnseignant(enseignantParser(getJsonEnseignant(e)))) == 0);

    return 0;
}

#endif