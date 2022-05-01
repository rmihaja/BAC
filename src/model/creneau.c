/**
 * @file creneau.c
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief Code source de la structure de données Creneau.
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "creneau.h"

#ifdef DEBUG
#include "tests.h"
#endif


 /************************************************************\
 *                    Structure de Creneau                    *
 \************************************************************/

 /**
  * @internal
  *
  * @struct s_creneau
  * @brief Structure représentant un objet Creneau.
  * @details
  * Structure permettant de stocker les attributs
  * (Enseignant, Horaire, Formation et Salle) d'un
  * créneau.
  *
  * @endinternal
  */
struct s_creneau {
    Enseignant enseignant;  /*!< Référence de Enseignant de l'objet Creneau */
    Horaire horaire;        /*!< Référence de Horaire de l'objet Creneau */
    char* enseignement;     /*!< Enseignement de l'objet Creneau */
    char* formation;        /*!< Formation de l'objet Creneau */
    char* salle;            /*!< Salle de l'objet Creneau */
};


/************************************************************\
*                  Constructeurs de Creneau                  *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Constructeur par défaut de l'objet Creneau.
 *
 * @endinternal
 */
Creneau creneau(Enseignant e, Horaire h, char* enseignement, char* formation, char* salle) {
    Creneau c = (Creneau)malloc(sizeof(struct s_creneau));
    c->enseignant = e;
    c->horaire = h;
    c->enseignement = enseignement;
    c->formation = formation;
    c->salle = salle;
    return c;
}

/**
 * @internal
 *
 * @details
 * Construit l'objet Creneau en manipulant l'API Jansson.
 * Pour cela, à partir d'une recherche par clé (s'il existe),
 * nous pouvons accéder aux attributs "enseignant", "horaire",
 * "enseignement", "formation" et "salle" de Creneau,
 * que nous construisons ensuite à l'aide du constructeur
 * par défaut, avec les objets Enseignant et Horaire préalablement
 * construit à partir de leur représentation JSON également.
 *
 * @sa enseignantParser , horaireParser ,
 * [json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) ,
 * [json_object_get](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_get) ,
 * [json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string)
 *
 * @endinternal
 *
 */
Creneau creneauParser(json_t* json_creneau) {
    json_t* enseignant = json_object_get(json_creneau, "enseignant");
    json_t* horaire = json_object_get(json_creneau, "horaire");
    json_t* enseignement = json_object_get(json_creneau, "enseignement");
    json_t* formation = json_object_get(json_creneau, "formation");
    json_t* salle = json_object_get(json_creneau, "salle");
    assert(json_is_string(enseignement)
        && json_is_string(formation)
        && json_is_string(salle)
        && json_is_object(horaire)
        && json_is_object(enseignant));
    return creneau(enseignantParser(enseignant), horaireParser(horaire),
        (char*)json_string_value(enseignement), (char*)json_string_value(formation),
        (char*)json_string_value(salle));
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

Enseignant getCreneauE(Creneau c) {
    return c->enseignant;
}

Horaire getCreneauH(Creneau c) {
    return c->horaire;
}

char* getCreneauENS(Creneau c) {
    return c->enseignement;
}

char* getCreneauF(Creneau c) {
    return c->formation;
}

char* getCreneauS(Creneau c) {
    return c->salle;
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation objet JSON du Creneau
 * en utilisant l'API Jansson.
 * Pour cela, on construit un nouvel objet JSON pour ensuite
 * pouvoir y attacher les attributs clé-valeurs du Creneau, défini par
 * "enseignant" et "horaire", faisant appel à la représentation objet JSON
 * de Enseignant et Horaire, ainsi que "formation" et "salle".
 *
 * @sa getJsonEnseignant , getJsonHoraire ,
 * [json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) ,
 * [json_object_set_new](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_set_new)
 *
 * @endinternal
 */
json_t* getJsonCreneau(Creneau c) {
    json_t* root = json_object();
    json_object_set_new(root, "enseignant", getJsonEnseignant(getCreneauE(c)));
    json_object_set_new(root, "horaire", getJsonHoraire(getCreneauH(c)));
    json_object_set_new(root, "enseignement", json_string(getCreneauENS(c)));
    json_object_set_new(root, "formation", json_string(getCreneauF(c)));
    json_object_set_new(root, "salle", json_string(getCreneauS(c)));
    return root;
}

Creneau setCreneauE(Enseignant e, Creneau c) {
    c->enseignant = e;
    return c;
}

Creneau setCreneauH(Horaire h, Creneau c) {
    c->horaire = h;
    return c;
}

Creneau setCreneauENS(char* enseignement, Creneau c) {
    c->enseignement = enseignement;
    return c;
}

Creneau setCreneauF(char* formation, Creneau c) {
    c->formation = formation;
    return c;
}

Creneau setCreneauS(char* salle, Creneau c) {
    c->salle = salle;
    return c;
}

bool equalsCreneau(Creneau c1, Creneau c2) {
    return equalsEnseignant(getCreneauE(c1), getCreneauE(c2))
        && equalsHoraire(getCreneauH(c1), getCreneauH(c2))
        && strcmp(getCreneauENS(c1), getCreneauENS(c2)) == 0
        && strcmp(getCreneauF(c1), getCreneauF(c2)) == 0
        && strcmp(getCreneauS(c1), getCreneauS(c2)) == 0;
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

/**
 * @internal
 *
 * @details
 * Imprime les attributs de l'objet Creneau en réutilisant l'affichage
 * des objets Enseignant et Horaire, respectant alors le format :
 *
 * @code {.txt}
 * {Salle} {Formation}
 * {Enseignement}
 * {Enseignant}
 * {Horaire}
 * @endcode
 *
 * @sa afficheEnseignant , afficheHoraire
 *
 * @endinternal
 */
void afficheCreneau(Creneau c) {
    printf("Salle %s %s\n%s\n", getCreneauS(c), getCreneauF(c), getCreneauENS(c));
    afficheEnseignant(getCreneauE(c));
    afficheHoraire(getCreneauH(c));
}

/**
 * @internal
 *
 * @details
 * Renvoie la représentation JSON en chaîne de caractères
 * du Creneau en utilisant l'API Jansson.
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
char* toStringCreneau(Creneau c) {
    json_t* json_creneau = getJsonCreneau(c);
    char* str = json_dumps(json_creneau, 0);
#ifdef DEBUG
    puts(str);
#endif
    // deallocate json object memory
    json_decref(json_creneau);
    return str;
}


/************************************************************\
*                 Tests unitaires de Creneau                 *
\************************************************************/

#ifdef TEST

int main() {

    // init

    Enseignant e1 = enseignantCopie("TRUILLET", "Philippe");
    Enseignant e2 = enseignantCopie("GAILDRAT", "Véronique");
    Horaire h1 = horaire(13, 15);
    Horaire h2 = horaire(16, 18);
    char* ens1 = "Structure de données";
    char* ens2 = "Programmation orientée objet";
    char* f1 = "L2 Informatique";
    char* f2 = "CUPGE";
    char* s1 = "108";
    char* s2 = "118";

    // testing

    Creneau c = creneau(e1, h1, ens1, f1, s1);

    test(strcmp(getNom(getCreneauE(c)), getNom(e1)) == 0);
    test(getDebut(getCreneauH(c)) == getDebut(h1));
    test(strcmp(getCreneauENS(c), ens1) == 0);
    test(strcmp(getCreneauF(c), f1) == 0);
    test(strcmp(getCreneauS(c), s1) == 0);

    info(setCreneauE(e2, c));
    info(setCreneauH(h2, c));
    info(setCreneauENS(ens2, c));
    info(setCreneauF(f2, c));
    info(setCreneauS(s2, c));

    test(strcmp(getPrenom(getCreneauE(c)), getPrenom(e2)) == 0);
    test(getFin(getCreneauH(c)) == getFin(h2));
    test(strcmp(getCreneauF(c), f2) == 0);
    test(strcmp(getCreneauS(c), s2) == 0);

    info(afficheCreneau(c));

    test(strcmp(toStringCreneau(c), toStringCreneau(creneauParser(getJsonCreneau(c)))) == 0);

    return 0;
}

#endif