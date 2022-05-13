# Référence du fichier src/model/formation.c

Code source de la structure de données Formation.  [Plus de détails...](#description-détaillée)

## Structures de données

|                | Nom           |
| -------------- | -------------- |
| struct | **[s_creneau_f](/Classes/structs__creneau__f.md)** <br>Structure représentant un élément de la liste chaînée de Creneau de Formation.  |
| struct | **[s_formation](/Classes/structs__formation.md)** <br>Structure représentant un objet Formation.  |

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_creneau_f](/Classes/structs__creneau__f.md) * | **[CreneauF](/Files/formation_8c.md#typedef-creneauf)**  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Formation](/Files/formation_8h.md#typedef-formation) | **[formation](/Files/formation_8c.md#fonction-formation)**(char * nom)<br>Construit un nouvel objet Formation avec un Nom et une liste de Creneau vide.  |
| [CreneauF](/Classes/structs__creneau__f.md) | **[creneauF](/Files/formation_8c.md#fonction-creneauf)**([Creneau](/Files/creneau_8h.md#typedef-creneau) c) |
| [Formation](/Files/formation_8h.md#typedef-formation) | **[formationParser](/Files/formation_8c.md#fonction-formationparser)**([json_t](/Classes/structjson__t.md) * json_formation)<br>Construit un nouvel objet Formation à partir de sa représentation en objet JSON.  |
| char * | **[getFormationN](/Files/formation_8c.md#fonction-getformationn)**([Formation](/Files/formation_8h.md#typedef-formation) f)<br>Accesseur de l'objet Nom de Formation.  |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) | **[getFormationCByIndice](/Files/formation_8c.md#fonction-getformationcbyindice)**([Formation](/Files/formation_8h.md#typedef-formation) f, int indice)<br>Accesseur de l'objet Creneau à partir de son Indice dans Formation.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonFormation](/Files/formation_8c.md#fonction-getjsonformation)**([Formation](/Files/formation_8h.md#typedef-formation) f)<br>Accesseur de la représentation en objet JSON de Formation.  |
| int | **[sizeFormationC](/Files/formation_8c.md#fonction-sizeformationc)**([Formation](/Files/formation_8h.md#typedef-formation) f)<br>Accesseur de la taille de la liste de Creneau de Formation.  |
| [Formation](/Files/formation_8h.md#typedef-formation) | **[ajouterFormationC](/Files/formation_8c.md#fonction-ajouterformationc)**([Formation](/Files/formation_8h.md#typedef-formation) f, [Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Ajoute une référence de l'objet Creneau à la liste de Créneau de Formation.  |
| [Formation](/Files/formation_8h.md#typedef-formation) | **[supprimerFormationH](/Files/formation_8c.md#fonction-supprimerformationh)**([Formation](/Files/formation_8h.md#typedef-formation) f, [Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Supprime tout Creneau alloué à Formation dans l'intervalle de Horaire.  |
| bool | **[isFreeFormation](/Files/formation_8c.md#fonction-isfreeformation)**([Formation](/Files/formation_8h.md#typedef-formation) f, [Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Vérifie si Formation ne contient aucun créneau réservé dans l'intervalle de Horaire.  |
| bool | **[isFullFormation](/Files/formation_8c.md#fonction-isfullformation)**([Formation](/Files/formation_8h.md#typedef-formation) f)<br>Vérifie si Formation a atteint son maximum de Creneau allouable pour la journée. Le maximum est fixé à 4 Creneau.  |
| void | **[afficheFormation](/Files/formation_8c.md#fonction-afficheformation)**([Formation](/Files/formation_8h.md#typedef-formation) f, bool isOrdered)<br>Imprime le nom de Formation ainsi que sa liste de Creneau sur stdout, suivi d'un retour à la ligne.  |
| char * | **[toStringFormation](/Files/formation_8c.md#fonction-tostringformation)**([Formation](/Files/formation_8h.md#typedef-formation) f)<br>Accesseur de la représentation en chaîne de caractère JSON de Formation.  |

## Description détaillée

Code source de la structure de données Formation.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef CreneauF

```c
typedef struct s_creneau_f * CreneauF;
```

## Documentation des fonctions

### fonction formation()

```c
Formation formation(
    char * nom
)
```

Construit un nouvel objet Formation avec un Nom et une liste de Creneau vide.

Constructeur par défaut de l'objet Formation.

### fonction creneauF()

```c
CreneauF creneauF(
    Creneau c
)
```

Constructeur par défaut de l'objet CreneauF, élément de la liste de Creneau, stockant l'objet Creneau passé en paramètre.

### fonction formationParser()

```c
Formation formationParser(
    json_t * json_formation
)
```

Construit un nouvel objet Formation à partir de sa représentation en objet JSON.

Construit l'objet Salles en manipulant l'API Jansson. Pour cela, à partir d'une recherche par clé (s'il existe), nous pouvons accéder à l'attribut "nom" de Formation que nous construisons à l'aide du constructeur par défaut. Nous accédons ensuite à la clé "salles", qui est un tableau de Creneau. On itère le tableau pour pouvoir ajouter chaque Creneau à la liste de Creneau, en faisant chaque fois appel à son constructeur à partir de la valeur renvoyée par l'API.

[creneauParser](/Files/creneau_8c.md#fonction-creneauparser) , [json_array_foreach](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_foreach)

### fonction getFormationN()

```c
char * getFormationN(
    Formation f
)
```

Accesseur de l'objet Nom de Formation.

**Paramètres**:

* **f** Référence de Formation.

**Renvoie**: Valeur du Nom de Formation de type char*.

### fonction getFormationCByIndice()

```c
Creneau getFormationCByIndice(
    Formation f,
    int indice
)
```

Accesseur de l'objet Creneau à partir de son Indice dans Formation.

**Paramètres**:

* **f** Référence de Formation.
* **indice** Indice à laquelle se trouve Creneau recherchée.

**Renvoie**: Creneau à l'indice indiquée.

!> **Précondition**: Indice doit être positif et strictement inférieur à la taille de la liste. Formation ne doit pas être vide.

### fonction getJsonFormation()

```c
json_t * getJsonFormation(
    Formation f
)
```

Accesseur de la représentation en objet JSON de Formation.

Renvoie la représentation objet JSON de Formation en utilisant l'API Jansson. Pour cela, on construit un nouvel objet JSON et on y attache les clés "nom" qui stocke la valeur Nom de Formation et "creneaux" qui est un tableau. En itérant ensuite la liste de Creneau de Formation, on ajoute à ce tableau la représentation objet JSON de chaque Creneau.

[getJsonCreneau](/Files/creneau_8c.md#fonction-getjsoncreneau) , [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) , [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)

### fonction sizeFormationC()

```c
int sizeFormationC(
    Formation f
)
```

Accesseur de la taille de la liste de Creneau de Formation.

**Paramètres**:

* **f** Référence de Formation.

**Renvoie**: Taille de la liste des Creneau de Formation de type int.

### fonction ajouterFormationC()

```c
Formation ajouterFormationC(
    Formation f,
    Creneau c
)
```

Ajoute une référence de l'objet Creneau à la liste de Créneau de Formation.

Lorsque toutes les conditions de Formation et Creneau sont réunies, Creneau devient la tête de la liste de Creneau.

[isFullFormation](/Files/formation_8c.md#fonction-isfullformation) , [isFreeFormation](/Files/formation_8c.md#fonction-isfreeformation)

### fonction supprimerFormationH()

```c
Formation supprimerFormationH(
    Formation f,
    Horaire h
)
```

Supprime tout Creneau alloué à Formation dans l'intervalle de Horaire.

Si un Creneau correspond à Horaire, alors on le détache de la liste chaînée de Creneau.

On ne supprime qu'un et un seul Creneau dans l'intervalle de Horaire, il faut alors s'assurer que Horaire correspond à un et un seul Creneau de Formation.

[equalsHoraire](/Files/horaire_8c.md#fonction-equalshoraire)

### fonction isFreeFormation()

```c
bool isFreeFormation(
    Formation f,
    Horaire h
)
```

Vérifie si Formation ne contient aucun créneau réservé dans l'intervalle de Horaire.

Une Formation est considéré comme "libre" si pour tout Creneau dans sa liste de Creneau, aucune borne (Debut et Fin) de Horaire indiqué en paramètre n'englobe un Horaire de Creneau et n'est dans l'intervalle Horaire indiqué pour tout Creneau dans la liste de Formation.

### fonction isFullFormation()

```c
bool isFullFormation(
    Formation f
)
```

Vérifie si Formation a atteint son maximum de Creneau allouable pour la journée. Le maximum est fixé à 4 Creneau.

La taille maximale de Creneau allouable à une Formation est 4, défini par la spécification du TAD.

### fonction afficheFormation()

```c
void afficheFormation(
    Formation f,
    bool isOrdered
)
```

Imprime le nom de Formation ainsi que sa liste de Creneau sur stdout, suivi d'un retour à la ligne.

Imprime le Nom de l'objet Formation suivi par une représentation de sa liste de Creneau qu'on itère. L'impression suit alors le format :

```txt

Salle {Salle de Creneau}
de {Horaire de Creneau}
{Enseignement de Creneau}
{Enseignant de Creneau}

Salle {Salle de Creneau}
de {Horaire de Creneau}
{Enseignement de Creneau}
{Enseignant de Creneau}

...
```

[afficheHoraire](/Files/horaire_8c.md#fonction-affichehoraire) , [afficheEnseignant](/Files/enseignant_8c.md#fonction-afficheenseignant)

### fonction toStringFormation()

```c
char * toStringFormation(
    Formation f
)
```

Accesseur de la représentation en chaîne de caractère JSON de Formation.

Renvoie la représentation JSON en chaîne de caractères de Formation en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

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

typedef struct s_creneau_f {
    Creneau creneau;
    struct s_creneau_f* suivant;
} *CreneauF;

struct s_formation {
    char* nom;
    CreneauF sentinelle;
    int taille;
};


/************************************************************\
*                Constructeurs de Formation                  *
\************************************************************/

Formation formation(char* nom) {
    Formation f = (Formation)malloc(sizeof(struct s_formation));
    f->sentinelle = (CreneauF)malloc(sizeof(struct s_creneau_f));
    f->sentinelle->suivant = f->sentinelle;
    f->nom = nom;
    f->taille = 0;
    return f;
}

CreneauF creneauF(Creneau c) {
    CreneauF e = (CreneauF)malloc(sizeof(struct s_creneau_f));
    e->creneau = c;
    return e;
}

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

Creneau getFormationCByIndice(Formation f, int indice) {
    assert(0 <= indice && indice < sizeFormationC(f));
    CreneauF courant = f->sentinelle->suivant;
    for (int i = 0; i < indice; i++) {
        courant = courant->suivant;
    }
    return courant->creneau;
}

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

bool isFreeFormation(Formation f, Horaire h) {
    bool isInCreneauH = false;
    CreneauF courant = f->sentinelle->suivant;
    for (int i = 0; i < f->taille && !isInCreneauH; i++) {
        isInCreneauH = (getDebut(getCreneauH(courant->creneau)) <= getDebut(h) && getDebut(h) < getFin(getCreneauH(courant->creneau)))
            || (getDebut(getCreneauH(courant->creneau)) < getFin(h) && getFin(h) <= getFin(getCreneauH(courant->creneau)))
            || (getDebut(h) <= getDebut(getCreneauH(courant->creneau)) && getFin(getCreneauH(courant->creneau)) <= getFin(h));
        courant = courant->suivant;
    }
    return !isInCreneauH;
}

bool isFullFormation(Formation f) {
    return f->taille == 4;
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

void afficheFormation(Formation f, bool isOrdered) {
    CreneauF courant = f->sentinelle->suivant;
    for (int i = 0;i < f->taille;i++) {
        if (isOrdered) {
            printf("(%d)\n", i + 1);
        }
        printf("Salle %s\n", getCreneauS(courant->creneau));
        printf("de ");
        afficheHoraire(getCreneauH(courant->creneau));
        printf("%s\n", getCreneauENS(courant->creneau));
        afficheEnseignant(getCreneauE(courant->creneau));
        courant = courant->suivant;
        printf("\n");
    }
}

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
    Enseignant e1 = enseignantCopie("TRUILLET", "Philippe");
    char* ens1 = "Structure de données";
    char* f1_nom = "CUPGE";
    char* s1 = "118";

    Horaire h2 = horaire(16, 18);
    Enseignant e2 = enseignantCopie("GAILDRAT", "Véronique");
    char* ens2 = "Programmation orientée objet";
    char* f2_nom = "L2 Informatique";
    char* s2 = "103";

    Creneau c1 = creneau(e1, h1, ens1, f1_nom, s1);
    Creneau c1_bis = creneau(e2, h1, ens1, f1_nom, s2);
    Creneau c2 = creneau(e2, h2, ens2, f2_nom, s2);
    Creneau c2_bis = creneau(e2, h2, ens2, f1_nom, s2);

    // testing

    Formation f = formation(f1_nom);

    // info(ajouterFormationC(f, c2)); // devrait produire une erreur

    info(ajouterFormationC(f, c1));

    info(afficheFormation(f, false));

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
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
