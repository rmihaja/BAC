# Référence du fichier include/enseignements.h

En-tête de la struture de données Enseignements.  [Plus de détails...](#description-détaillée)

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_enseignements](/Classes/structs__enseignements.md) * | **[Enseignements](/Files/enseignements_8h.md#typedef-enseignements)** <br>Objet Enseignements.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Enseignements](/Files/enseignements_8h.md#typedef-enseignements) | **[enseignements](/Files/enseignements_8h.md#fonction-enseignements)**()<br>Construit un nouvel objet Enseignements.  |
| [Enseignements](/Files/enseignements_8h.md#typedef-enseignements) | **[enseignementsParser](/Files/enseignements_8h.md#fonction-enseignementsparser)**([json_t](/Classes/structjson__t.md) * json_enseignements)<br>Construit un nouvel objet Enseignements à partir de sa représentation en objet JSON.  |
| char * | **[getEnseignementByIndice](/Files/enseignements_8h.md#fonction-getenseignementbyindice)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens, int indice)<br>Accesseur d'un Enseignement à partir de son Indice dans Enseignements.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonEnseignements](/Files/enseignements_8h.md#fonction-getjsonenseignements)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens)<br>Accesseur de la représentation en objet JSON de Enseignements.  |
| int | **[sizeEnseignements](/Files/enseignements_8h.md#fonction-sizeenseignements)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens)<br>Accesseur de la taille de Enseignements.  |
| bool | **[appartientEnseignements](/Files/enseignements_8h.md#fonction-appartientenseignements)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens, char * nom)<br>vérifie si Enseignements possède une référence de l'objet Enseignement.  |
| [Enseignements](/Files/enseignements_8h.md#typedef-enseignements) | **[ajouterEns](/Files/enseignements_8h.md#fonction-ajouterens)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens, char * nom)<br>Ajoute une référence de l'objet Enseignement à la liste des Enseignements.  |
| [Enseignements](/Files/enseignements_8h.md#typedef-enseignements) | **[supprimerEns](/Files/enseignements_8h.md#fonction-supprimerens)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens, char * nom)<br>Supprime toute référence de l'objet Enseignement dans la liste des Enseignements.  |
| void | **[afficherEnseignements](/Files/enseignements_8h.md#fonction-afficherenseignements)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens, bool isOrdered)<br>Imprime tout Enseignement de la liste des Enseignements sur stdout, suivi d'un retour à ligne.  |
| char * | **[toStringEnseignements](/Files/enseignements_8h.md#fonction-tostringenseignements)**([Enseignements](/Files/enseignements_8h.md#typedef-enseignements) ens)<br>Accesseur de la représentation en chaîne de caractère JSON de Enseignements.  |

## Description détaillée

En-tête de la struture de données Enseignements.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef Enseignements

```c
typedef struct s_enseignements* Enseignements;
```

Objet Enseignements.

## Documentation des fonctions

### fonction enseignements()

```c
Enseignements enseignements()
```

Construit un nouvel objet Enseignements.

**Renvoie**: Nouvelle instance allouée de Enseignements.

Constructeur par défaut de l'objet Enseignements.

### fonction enseignementsParser()

```c
Enseignements enseignementsParser(
    json_t * json_enseignements
)
```

Construit un nouvel objet Enseignements à partir de sa représentation en objet JSON.

**Paramètres**:

* **json_enseignements** Objet JSON de Enseignements.

**Renvoie**: Nouvelle instance allouée de Enseignements.

!> **Précondition**: json_enseignements doit contenir une clé "enseignements" stockant un tableau de Enseignement.

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

**Paramètres**:

* **ens** Référence de Enseignements.

**Renvoie**: Objet JSON de Enseignements de type json_t*.

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

**Paramètres**:

* **ens** Référence de Enseignements.
* **nom** Valeur de Enseignement de type char* à rechercher.

**Renvoie**: true si un Enseignement de Enseignements est égale à Enseignement.

Vérifie par itération si un Nom de Enseignement de la liste des Enseignements est égale au Nom de Enseignement passé en paramètre.

### fonction ajouterEns()

```c
Enseignements ajouterEns(
    Enseignements ens,
    char * nom
)
```

Ajoute une référence de l'objet Enseignement à la liste des Enseignements.

**Paramètres**:

* **ens** Référence de Enseignements.
* **nom** Valeur de Enseignement à ajouter de type char*.

**Renvoie**: Enseignements possédant une référence de Enseignement parmi sa liste de Salle.

!> **Précondition**: Enseignements ne doit posséder aucune autre référence à Enseignement.

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

**Paramètres**:

* **ens** Référence de Enseignements.
* **nom** Valeur de Enseignement à supprimer de type char*.

**Renvoie**: Enseignements ne possédant aucune référence de Enseignement.

!> **Précondition**: Enseignements ne doit pas être vide.

Vérifie d'abord que la liste ne soit pas vide. Ensuite, On itère jusqu'à ce qu'on trouve un élément de la liste des Enseignements dont le Nom de Enseignement stocké est égale à celui en paramètre. Dans ce cas, on l'isole de la liste chaînée pour pouvoir libérer sa mémoire. Sinon, aucun élément ne sera supprimé.

### fonction afficherEnseignements()

```c
void afficherEnseignements(
    Enseignements ens,
    bool isOrdered
)
```

Imprime tout Enseignement de la liste des Enseignements sur stdout, suivi d'un retour à ligne.

**Paramètres**:

* **ens** Enseignements à afficher.
* **isOrdered** indique si la liste doit être ordonnée par son indice.

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

**Paramètres**:

* **ens** Référence de Enseignements.

**Renvoie**: Représentation JSON de Enseignements de type char*.

Renvoie la représentation JSON en chaîne de caractères de Enseignements en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

#ifndef __ENSEIGNEMENTS_H__
#define __ENSEIGNEMENTS_H__

#include <stdbool.h>
#include <jansson.h>

typedef struct s_enseignements* Enseignements;

Enseignements enseignements();

Enseignements enseignementsParser(json_t* json_enseignements);

char* getEnseignementByIndice(Enseignements ens, int indice);

json_t* getJsonEnseignements(Enseignements ens);

int sizeEnseignements(Enseignements ens);

bool appartientEnseignements(Enseignements ens, char* nom);

Enseignements ajouterEns(Enseignements ens, char* nom);

Enseignements supprimerEns(Enseignements ens, char* nom);

void afficherEnseignements(Enseignements ens, bool isOrdered);

char* toStringEnseignements(Enseignements ens);

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
