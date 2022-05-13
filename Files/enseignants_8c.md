# Référence du fichier src/model/enseignants.c

Code source de la structure de données Enseignants.  [Plus de détails...](#description-détaillée)

## Structures de données

|                | Nom           |
| -------------- | -------------- |
| struct | **[s_element_es](/Classes/structs__element__es.md)** <br>Structure représentant un élément de la liste chaînée Enseignants.  |
| struct | **[s_enseignants](/Classes/structs__enseignants.md)** <br>Structure représentant une liste chaînée de Enseignant.  |

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_element_es](/Classes/structs__element__es.md) * | **[ElementEs](/Files/enseignants_8c.md#typedef-elementes)**  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Enseignants](/Files/enseignants_8h.md#typedef-enseignants) | **[enseignants](/Files/enseignants_8c.md#fonction-enseignants)**()<br>Construit un nouvel objet Enseignants.  |
| [ElementEs](/Classes/structs__element__es.md) | **[elementEs](/Files/enseignants_8c.md#fonction-elementes)**([Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e) |
| [Enseignants](/Files/enseignants_8h.md#typedef-enseignants) | **[enseignantsParser](/Files/enseignants_8c.md#fonction-enseignantsparser)**([json_t](/Classes/structjson__t.md) * json_enseignants)<br>Construit un nouvel objet Enseignants à partir de sa représentation en objet JSON.  |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[getEnseignantByNom](/Files/enseignants_8c.md#fonction-getenseignantbynom)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, char * nom)<br>Accesseur de l'objet Enseignant à partir de son Nom parmi la liste des Enseignants.  |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[getEnseignantByPrenom](/Files/enseignants_8c.md#fonction-getenseignantbyprenom)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, char * prenom)<br>Accesseur de l'objet Enseignant à partir de sa Prenom parmi la liste des Enseignants.  |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[getEnseignantByIndice](/Files/enseignants_8c.md#fonction-getenseignantbyindice)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, int indice)<br>Accesseur de l'objet Enseignant à partir de son Indice dans Enseignants.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonEnseignants](/Files/enseignants_8c.md#fonction-getjsonenseignants)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es)<br>Accesseur de la représentation en objet JSON de Enseignants.  |
| int | **[sizeEnseignants](/Files/enseignants_8c.md#fonction-sizeenseignants)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es)<br>Accesseur de la taille de Enseignants.  |
| bool | **[appartientEnseignants](/Files/enseignants_8c.md#fonction-appartientenseignants)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>vérifie si Enseignants possède une référence de l'objet Enseignant.  |
| [Enseignants](/Files/enseignants_8h.md#typedef-enseignants) | **[ajouterEs](/Files/enseignants_8c.md#fonction-ajouteres)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>Ajoute une référence de l'objet Enseignant à la liste des Enseignants.  |
| [Enseignants](/Files/enseignants_8h.md#typedef-enseignants) | **[supprimerEs](/Files/enseignants_8c.md#fonction-supprimeres)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>Supprime toute référence de l'objet Enseignant dans la liste des Enseignants.  |
| void | **[afficherEnseignants](/Files/enseignants_8c.md#fonction-afficherenseignants)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, bool isOrdered)<br>Imprime tout Enseignant de la liste des Enseignants sur stdout, suivi d'un retour à ligne.  |
| char * | **[toStringEnseignants](/Files/enseignants_8c.md#fonction-tostringenseignants)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es)<br>Accesseur de la représentation en chaîne de caractère JSON de Enseignants.  |

## Description détaillée

Code source de la structure de données Enseignants.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef ElementEs

```c
typedef struct s_element_es* ElementEs;
```

## Documentation des fonctions

### fonction enseignants()

```c
Enseignants enseignants()
```

Construit un nouvel objet Enseignants.

Constructeur par défaut de l'objet Enseignants.

### fonction elementEs()

```c
ElementEs elementEs(
    Enseignant e
)
```

Constructeur par défaut de l'objet ElementEs, élément de la liste Enseignants, stockant l'objet Enseignant passé en paramètre.

### fonction enseignantsParser()

```c
Enseignants enseignantsParser(
    json_t * json_enseignants
)
```

Construit un nouvel objet Enseignants à partir de sa représentation en objet JSON.

Construit l'objet Enseignants en manipulant l'API Jansson. Pour cela, à partir d'une recherche par clé (s'il existe) de "enseignants", nous pouvons obtenir un tableau de Enseignant. Ensuite, on itère le tableau pour pouvoir ajouter chaque Enseignant à l'objet Enseignants, en faisant chaque fois appel à son constructeur à partir de la valeur renvoyée par l'API.

[enseignantParser](/Files/enseignant_8c.md#fonction-enseignantparser) , [json_array_foreach](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_foreach)

### fonction getEnseignantByNom()

```c
Enseignant getEnseignantByNom(
    Enseignants es,
    char * nom
)
```

Accesseur de l'objet Enseignant à partir de son Nom parmi la liste des Enseignants.

Itère parmi la liste des Enseignants jusqu'à trouver un Enseignant dont l'attribut Nom correspond au paramètre. Sinon, renvoie une erreur.

### fonction getEnseignantByPrenom()

```c
Enseignant getEnseignantByPrenom(
    Enseignants es,
    char * prenom
)
```

Accesseur de l'objet Enseignant à partir de sa Prenom parmi la liste des Enseignants.

Itère parmi la liste des Enseignants jusqu'à trouver un Enseignant dont Prenom correspond au paramètre. Sinon renvoie une erreur.

### fonction getEnseignantByIndice()

```c
Enseignant getEnseignantByIndice(
    Enseignants es,
    int indice
)
```

Accesseur de l'objet Enseignant à partir de son Indice dans Enseignants.

**Paramètres**:

* **es** Référence de Enseignants.
* **indice** Indice à laquelle se trouve Enseignant recherchée.

**Renvoie**: Enseignant à l'indice indiquée.

!> **Précondition**: Indice doit être positif et strictement inférieur à la taille de la liste. Enseignants ne doit pas être vide.

### fonction getJsonEnseignants()

```c
json_t * getJsonEnseignants(
    Enseignants es
)
```

Accesseur de la représentation en objet JSON de Enseignants.

Renvoie la représentation objet JSON de Enseignants en utilisant l'API Jansson. Pour cela, on construit un nouvel objet JSON et on y attache la clé "enseignants" qui est un tableau. En itérant ensuite la liste des Enseignants, on ajoute à ce tableau la représentation objet JSON de chaque Enseignant.

[getJsonEnseignant](/Files/enseignant_8c.md#fonction-getjsonenseignant) , [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) , [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)

### fonction sizeEnseignants()

```c
int sizeEnseignants(
    Enseignants es
)
```

Accesseur de la taille de Enseignants.

**Paramètres**:

* **es** Référence de Enseignants

**Renvoie**: int Taille de Enseignants de type int.

### fonction appartientEnseignants()

```c
bool appartientEnseignants(
    Enseignants es,
    Enseignant e
)
```

vérifie si Enseignants possède une référence de l'objet Enseignant.

Vérifie par itération si un élément Enseignant de la liste des Enseignants est égale à l'objet Enseignant passé en paramètre.

### fonction ajouterEs()

```c
Enseignants ajouterEs(
    Enseignants es,
    Enseignant e
)
```

Ajoute une référence de l'objet Enseignant à la liste des Enseignants.

Ajoute Enseignants à la tête de la liste des Enseignants si Enseignant n'en fait pas encore parti. Si non, on renvoie une erreur.

[appartientEnseignants](/Files/enseignants_8c.md#fonction-appartientenseignants)

### fonction supprimerEs()

```c
Enseignants supprimerEs(
    Enseignants es,
    Enseignant e
)
```

Supprime toute référence de l'objet Enseignant dans la liste des Enseignants.

Vérifie d'abord que la liste ne soit pas vide. Ensuite, On itère jusqu'à ce qu'on trouve un élément de la liste des Enseignants dont l'objet Enseignant stocké est égale à celui en paramètre. Dans ce cas, on l'isole de la liste chaînée pour pouvoir libérer sa mémoire. Sinon, aucun élément ne sera supprimé.

### fonction afficherEnseignants()

```c
void afficherEnseignants(
    Enseignants es,
    bool isOrdered
)
```

Imprime tout Enseignant de la liste des Enseignants sur stdout, suivi d'un retour à ligne.

Itère la liste des Enseignants pour pouvoir afficher chaque Enseignant à partir de sa représentation externe sur stdout, précédé de son indice dans la liste si l'ordre est paramétré à True, ou d'un tiret sinon. L'impression suit alors le format :

```txt

- {Enseignant}
- {Enseignant}
...
```

 ou : ```txt

1) {Enseignant}
2) {Enseignant}
...

```

[afficheEnseignant](/Files/enseignant_8c.md#fonction-afficheenseignant)


### fonction toStringEnseignants()

```c
char * toStringEnseignants(
    Enseignants es
)
```

Accesseur de la représentation en chaîne de caractère JSON de Enseignants.

Renvoie la représentation JSON en chaîne de caractères de Enseignants en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

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

typedef struct s_element_es {
    Enseignant e;
    struct s_element_es* suivant;
}*ElementEs;

struct s_enseignants {
    ElementEs sentinelle;
    int taille;
};


/************************************************************\
*               Constructeurs de Enseignants                 *
\************************************************************/

Enseignants enseignants() {
    Enseignants es = (Enseignants)malloc(sizeof(struct s_enseignants));
    es->sentinelle = (ElementEs)malloc(sizeof(struct s_element_es));
    es->sentinelle->suivant = es->sentinelle;
    es->taille = 0;
    return es;
}

ElementEs elementEs(Enseignant e) {
    ElementEs e_es = (ElementEs)malloc(sizeof(struct s_element_es));
    e_es->e = e;
    return e_es;
}

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

bool appartientEnseignants(Enseignants es, Enseignant e) {
    bool isEqual = false;
    ElementEs courant = es->sentinelle->suivant;
    for (int i = 0; i < sizeEnseignants(es) && !isEqual; i++) {
        isEqual = equalsEnseignant(courant->e, e);
        courant = courant->suivant;
    }
    return isEqual;
}

Enseignants ajouterEs(Enseignants es, Enseignant e) {
    assert(!appartientEnseignants(es, e));
    ElementEs e_es = elementEs(e);
    e_es->suivant = es->sentinelle->suivant;
    es->sentinelle->suivant = e_es;
    es->taille++;
    return es;
}

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
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
