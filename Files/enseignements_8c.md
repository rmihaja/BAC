# Référence du fichier src/model/enseignements.c

Code source de la structure de données Enseignements.  [Plus de détails...](#description-détaillée)

## Structures de données

|                | Nom           |
| -------------- | -------------- |
| struct | **[s_enseignement](/Classes/structs__enseignement.md)** <br>Structure représentant un élément de la liste chaînée Enseignements.  |
| struct | **[s_enseignements](/Classes/structs__enseignements.md)** <br>Structure représentant une liste chaînée de Enseignement.  |

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_enseignement](/Classes/structs__enseignement.md) * | **[Enseignement](/Files/enseignements_8c.md#typedef-enseignement)**  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Enseignements](/Files/enseignements_8h.md#typedef-enseignements) | **[enseignements](/Files/enseignements_8c.md#fonction-enseignements)**()<br>Construit un nouvel objet Enseignements.  |
| [Enseignement](/Classes/structs__enseignement.md) | **[enseignement](/Files/enseignements_8c.md#fonction-enseignement)**(char * nom) |
| [Enseignements](/Files/enseignements_8h.md#typedef-enseignements) | **[enseignementsParser](/Files/enseignements_8c.md#fonction-enseignementsparser)**([json_t](/Classes/structjson__t.md) * json_enseignements)<br>Construit un nouvel objet Enseignements à partir de sa représentation en objet JSON.  |
| char * | **[getEnseignementByIndice](/Files/enseignements_8c.md#fonction-getenseignementbyindice)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens, int indice)<br>Accesseur d'un Enseignement à partir de son Indice dans Enseignements.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonEnseignements](/Files/enseignements_8c.md#fonction-getjsonenseignements)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens)<br>Accesseur de la représentation en objet JSON de Enseignements.  |
| int | **[sizeEnseignements](/Files/enseignements_8c.md#fonction-sizeenseignements)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens)<br>Accesseur de la taille de Enseignements.  |
| bool | **[appartientEnseignements](/Files/enseignements_8c.md#fonction-appartientenseignements)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens, char * nom)<br>vérifie si Enseignements possède une référence de l'objet Enseignement.  |
| [Enseignements](/Files/enseignements_8h.md#typedef-enseignements) | **[ajouterEns](/Files/enseignements_8c.md#fonction-ajouterens)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens, char * nom)<br>Ajoute une référence de l'objet Enseignement à la liste des Enseignements.  |
| [Enseignements](/Files/enseignements_8h.md#typedef-enseignements) | **[supprimerEns](/Files/enseignements_8c.md#fonction-supprimerens)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens, char * nom)<br>Supprime toute référence de l'objet Enseignement dans la liste des Enseignements.  |
| void | **[afficherEnseignements](/Files/enseignements_8c.md#fonction-afficherenseignements)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens, bool isOrdered)<br>Imprime tout Enseignement de la liste des Enseignements sur stdout, suivi d'un retour à ligne.  |
| char * | **[toStringEnseignements](/Files/enseignements_8c.md#fonction-tostringenseignements)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens)<br>Accesseur de la représentation en chaîne de caractère JSON de Enseignements.  |

## Description détaillée

Code source de la structure de données Enseignements.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef Enseignement

```c
typedef struct s_enseignement* Enseignement;
```

## Documentation des fonctions

### fonction enseignements()

```c
Enseignements enseignements()
```

Construit un nouvel objet Enseignements.

Constructeur par défaut de l'objet Enseignements.

### fonction enseignement()

```c
Enseignement enseignement(
    char * nom
)
```

Constructeur par défaut de l'objet Enseignement, élément de la liste Enseignements, stockant la valeur Nom de Enseignement passé en paramètre.

### fonction enseignementsParser()

```c
Enseignements enseignementsParser(
    json_t * json_enseignements
)
```

Construit un nouvel objet Enseignements à partir de sa représentation en objet JSON.

Construit l'objet Enseignements en manipulant l'API Jansson. Pour cela, on vérifie d'abord que json_enseignements est bien un tableau de caractère possédant le nom de chaque Enseignement. On itère alors le tableau pour pouvoir ajouter chaque nom de Enseignement à l'objet Enseignements, à partir de la valeur renvoyée par l'API.

[json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string) , [json_array_foreach](https://jansson.readthedocs.pio/en/latest/apiref.html#c.json_array_foreach)

### fonction getEnseignementByIndice()

```c
char * getEnseignementByIndice(
    Enseignements ens,
    int indice
)
```

Accesseur d'un Enseignement à partir de son Indice dans Enseignements.

**Paramètres**:

* **ens** Référence de Enseignements.
* **indice** Indice à laquelle se trouve Enseignement recherchée.

**Renvoie**: Enseignement à l'indice indiquée de type char*.

!> **Précondition**: Indice doit être positif et strictement inférieur à la taille de la liste. Enseignements ne doit pas être vide.

### fonction getJsonEnseignements()

```c
json_t * getJsonEnseignements(
    Enseignements ens
)
```

Accesseur de la représentation en objet JSON de Enseignements.

Renvoie la représentation objet JSON de Enseignements en utilisant l'API Jansson. Pour cela, on construit un nouvel tableau JSON et en itérant la liste des Enseignements, on ajoute à ce tableau l'attribut Nom de chaque Enseignement.

[json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string) , [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) , [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)

### fonction sizeEnseignements()

```c
int sizeEnseignements(
    Enseignements ens
)
```

Accesseur de la taille de Enseignements.

**Paramètres**:

* **ens** Référence de Enseignements

**Renvoie**: int Taille de Enseignements de type int.

### fonction appartientEnseignements()

```c
bool appartientEnseignements(
    Enseignements ens,
    char * nom
)
```

vérifie si Enseignements possède une référence de l'objet Enseignement.

Vérifie par itération si un Nom de Enseignement de la liste des Enseignements est égale au Nom de Enseignement passé en paramètre.

### fonction ajouterEns()

```c
Enseignements ajouterEns(
    Enseignements ens,
    char * nom
)
```

Ajoute une référence de l'objet Enseignement à la liste des Enseignements.

Ajoute Enseignements à la tête de la liste des Enseignements si Enseignement n'en fait pas encore parti. Si non, on renvoie une erreur.

[appartientEnseignements](/Files/enseignements_8c.md#fonction-appartientenseignements)

### fonction supprimerEns()

```c
Enseignements supprimerEns(
    Enseignements ens,
    char * nom
)
```

Supprime toute référence de l'objet Enseignement dans la liste des Enseignements.

Vérifie d'abord que la liste ne soit pas vide. Ensuite, On itère jusqu'à ce qu'on trouve un élément de la liste des Enseignements dont le Nom de Enseignement stocké est égale à celui en paramètre. Dans ce cas, on l'isole de la liste chaînée pour pouvoir libérer sa mémoire. Sinon, aucun élément ne sera supprimé.

### fonction afficherEnseignements()

```c
void afficherEnseignements(
    Enseignements ens,
    bool isOrdered
)
```

Imprime tout Enseignement de la liste des Enseignements sur stdout, suivi d'un retour à ligne.

Itère la liste des Enseignements pour pouvoir afficher le Nom de chaque Enseignement sur stdout, précédé de son indice dans la liste si l'ordre est paramétré à True, ou d'un tiret sinon. L'impression suit alors le format :

```txt
- {Nom de Enseignement}
- {Nom de Enseignement}
...
```

ou :

```txt
1) {Nom de Enseignement}
2) {Nom de Enseignement}
...
```

### fonction toStringEnseignements()

```c
char * toStringEnseignements(
    Enseignements ens
)
```

Accesseur de la représentation en chaîne de caractère JSON de Enseignements.

Renvoie la représentation JSON en chaîne de caractères de Enseignements en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

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

typedef struct s_enseignement {
    char nom[BUFSIZ];
    struct s_enseignement* suivant;
}*Enseignement;

struct s_enseignements {
    Enseignement sentinelle;
    int taille;
};


/************************************************************\
*             Constructeurs de Enseignements                 *
\************************************************************/

Enseignements enseignements() {
    Enseignements ens = (Enseignements)malloc(sizeof(struct s_enseignements));
    ens->sentinelle = (Enseignement)malloc(sizeof(struct s_enseignement));
    ens->sentinelle->suivant = ens->sentinelle;
    ens->taille = 0;
    return ens;
}

Enseignement enseignement(char* nom) {
    Enseignement e_ens = (Enseignement)malloc(sizeof(struct s_enseignement));
    strcpy(e_ens->nom, nom);
    return e_ens;
}

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

bool appartientEnseignements(Enseignements ens, char* nom) {
    bool isEqual = false;
    Enseignement courant = ens->sentinelle->suivant;
    for (int i = 0; i < sizeEnseignements(ens) && !isEqual; i++) {
        isEqual = strcmp(courant->nom, nom) == 0;
        courant = courant->suivant;
    }
    return isEqual;
}

Enseignements ajouterEns(Enseignements ens, char* nom) {
    assert(!appartientEnseignements(ens, nom));
    Enseignement e_ens = enseignement(nom);
    e_ens->suivant = ens->sentinelle->suivant;
    ens->sentinelle->suivant = e_ens;
    ens->taille++;
    return ens;
}

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
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0

[Voir la documentation Doxygen originale](https://rmihaja.github.io/BAC/doxygen/index.html)
