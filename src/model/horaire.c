/**
 * @file horaire.c
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief Code source de la structure de données Horaire.
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "horaire.h"

#ifdef DEBUG
#include "tests.h"
#endif

 /**
  * @internal
  *
  * @struct s_horaire
  * @details
  * Structure permettant de stocker les attributs
  * (début et fin) d'un horaire sous forme d'entiers.
  *
  * @endinternal
  */
struct s_horaire {
    int debut; /*! Heure de début de l'objet Horaire. */
    int fin; /*! Heure de fin de l'objet Horaire. */
};


/************************************************************\
*                  Constructeurs de Horaire                  *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet Horaire.
 *
 * @endinternal
 */
Horaire horaire(int debut, int fin) {
    assert(8 <= debut && debut <= 19 && 9 <= fin && fin <= 20 && debut != fin);
    Horaire h = (Horaire)malloc(sizeof(struct s_horaire));
    h->debut = debut;
    h->fin = fin;
    return h;
}

/**
 * @internal
 *
 * @details
 * Construit l'objet Horaire en manipulant l'API Jansson.
 * Pour cela, à partir d'une recherche par clé (s'il existe),
 * nous pouvons accéder aux attributs "debut" et "fin" de Horaire,
 * que nous construisons ensuite à l'aide du constructeur
 * par défaut.
 *
 * @sa [json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) ,
 * [json_object_get](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_get) ,
 * [json_integer_value](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_integer_value)
 *
 * @endinternal
 *
 */
Horaire horaireParser(json_t* json_horaire) {
    json_t* debut = json_object_get(json_horaire, "debut");
    json_t* fin = json_object_get(json_horaire, "fin");
    assert(json_is_integer(debut) && json_is_integer(fin));
    return horaire((int)json_integer_value(debut), (int)json_integer_value(fin));
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

int getDebut(Horaire h) {
    return h->debut;
}

int getFin(Horaire h) {
    return h->fin;
}

/**
 * @internal
 *
 * Renvoie la représentation objet JSON de Horaire
 * en utilisant l'API Jansson.
 * Pour cela, on construit un nouvel objet JSON pour ensuite
 * pouvoir y attacher les attributs clé-valeurs de Horaire, défini par
 * "debut" et "fin".
 *
 * @sa [json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) ,
 * [json_object_set_new](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_set_new)
 *
 * @endinternal
 */
json_t* getJsonHoraire(Horaire h) {
    json_t* root = json_object();
    json_object_set_new(root, "debut", json_integer(getDebut(h)));
    json_object_set_new(root, "fin", json_integer(getFin(h)));
    return root;
}

/**
 * @internal
 *
 * @details
 * Calcule \f$ \vert Fin - Debut \vert \f$.
 * Mais comme \f$ Fin \gt Debut \f$ par construction,
 * on peut alors tout simplement calculer \f$ Fin - Debut \f$
 *
 * @endinternal
 */
int duree(Horaire h) {
    return (h->fin - h->debut);
}

Horaire setDebut(Horaire h, int debut) {
    h->debut = debut;
    return h;
}

Horaire setFin(Horaire h, int fin) {
    h->fin = fin;
    return h;
}

bool equalsHoraire(Horaire h1, Horaire h2) {
    return h1->debut == h2->debut
        && h1->fin == h2->fin;
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

void affiche1H(int heure) {
    printf("%dh00\n", heure);
}

/**
 * @internal
 *
 * @details
 * Imprime les attributs de l'objet Enseignant selon le format :
 * Debut à Fin (les attributs étant suivi du chaîne de caractère "h00").
 *
 * @endinternal
 */
void afficheHoraire(Horaire h) {
    printf("%dh00 à %dh00\n" ,getDebut(h) ,getFin(h));
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation JSON en chaîne de caractères
 * de Horaire en utilisant l'API Jansson.
 * Pour cela, on accède d'abord à la représentation JSON
 * objet pour pouvoir le repasser à l'API.
 * Enfin, avant de renvoyer la chaîne de caractères, il
 * ne faut pas oublier de libérer la mémoire alloué à
 * l'objet JSON (à faire manuellement en décrémentant son
 * nombre de référencement).
 *
 * @sa [json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) ,
 * [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)
 *
 * @endinternal
 */
char* toStringHoraire(Horaire h) {
    json_t* json_horaire = getJsonHoraire(h);
    char* str = json_dumps(json_horaire, 0);
#ifdef DEBUG
    puts(str);
#endif
    // deallocate json object memory
    json_decref(json_horaire);
    return str;
}


/************************************************************\
*                Tests unitaires de Horaire                  *
\************************************************************/

#ifdef TEST
#include <string.h>

int main() {

    // init

    int h1_debut = 8;
    int h2_debut = 15;
    int h1_fin = 10;
    int h2_fin = 18;

    // testing

    Horaire h = horaire(h1_debut, h1_fin);

    test(duree(h) > 0);

    test(getDebut(h) == h1_debut);
    test(getFin(h) == h1_fin);

    info(setDebut(h, h2_debut));
    info(setFin(h, h2_fin));

    test(getDebut(h) == h2_debut);
    test(getFin(h) == h2_fin);

    test(duree(h) == h2_fin - h2_debut);

    test(equalsHoraire(h, h));
    test(!equalsHoraire(h, horaire(h1_debut, h1_fin)));

    info(affiche1H(duree(h)));
    info(afficheHoraire(h));

    test(strcmp(toStringHoraire(h), toStringHoraire(horaireParser(getJsonHoraire(h)))) == 0);

    return 0;
}

#endif