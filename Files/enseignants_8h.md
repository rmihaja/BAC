# Référence du fichier include/enseignants.h

En-tête de la struture de données Enseignants.  [Plus de détails...](#description-détaillée)

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_enseignants](/Classes/structs__enseignants.md) * | **[Enseignants](/Files/enseignants_8h.md#typedef-enseignants)** <br>Objet Enseignants.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Enseignants](/Files/enseignants_8h.md#typedef-enseignants) | **[enseignants](/Files/enseignants_8h.md#fonction-enseignants)**()<br>Construit un nouvel objet Enseignants.  |
| [Enseignants](/Files/enseignants_8h.md#typedef-enseignants) | **[enseignantsParser](/Files/enseignants_8h.md#fonction-enseignantsparser)**([json_t](/Classes/structjson__t.md) * json_enseignants)<br>Construit un nouvel objet Enseignants à partir de sa représentation en objet JSON.  |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[getEnseignantByNom](/Files/enseignants_8h.md#fonction-getenseignantbynom)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, char * nom)<br>Accesseur de l'objet Enseignant à partir de son Nom parmi la liste des Enseignants.  |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[getEnseignantByPrenom](/Files/enseignants_8h.md#fonction-getenseignantbyprenom)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, char * prenom)<br>Accesseur de l'objet Enseignant à partir de sa Prenom parmi la liste des Enseignants.  |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[getEnseignantByIndice](/Files/enseignants_8h.md#fonction-getenseignantbyindice)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, int indice)<br>Accesseur de l'objet Enseignant à partir de son Indice dans Enseignants.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonEnseignants](/Files/enseignants_8h.md#fonction-getjsonenseignants)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es)<br>Accesseur de la représentation en objet JSON de Enseignants.  |
| int | **[sizeEnseignants](/Files/enseignants_8h.md#fonction-sizeenseignants)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es)<br>Accesseur de la taille de Enseignants.  |
| bool | **[appartientEnseignants](/Files/enseignants_8h.md#fonction-appartientenseignants)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>vérifie si Enseignants possède une référence de l'objet Enseignant.  |
| [Enseignants](/Files/enseignants_8h.md#typedef-enseignants) | **[ajouterEs](/Files/enseignants_8h.md#fonction-ajouteres)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>Ajoute une référence de l'objet Enseignant à la liste des Enseignants.  |
| [Enseignants](/Files/enseignants_8h.md#typedef-enseignants) | **[supprimerEs](/Files/enseignants_8h.md#fonction-supprimeres)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>Supprime toute référence de l'objet Enseignant dans la liste des Enseignants.  |
| void | **[afficherEnseignants](/Files/enseignants_8h.md#fonction-afficherenseignants)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es, bool isOrdered)<br>Imprime tout Enseignant de la liste des Enseignants sur stdout, suivi d'un retour à ligne.  |
| char * | **[toStringEnseignants](/Files/enseignants_8h.md#fonction-tostringenseignants)**([Enseignants](/Files/enseignants_8h.md#typedef-enseignants) es)<br>Accesseur de la représentation en chaîne de caractère JSON de Enseignants.  |

## Description détaillée

En-tête de la struture de données Enseignants.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef Enseignants

```c
typedef struct s_enseignants* Enseignants;
```

Objet Enseignants.

## Documentation des fonctions

### fonction enseignants()

```c
Enseignants enseignants()
```

Construit un nouvel objet Enseignants.

**Renvoie**: Nouvelle instance allouée de Enseignants.

Constructeur par défaut de l'objet Enseignants.

### fonction enseignantsParser()

```c
Enseignants enseignantsParser(
    json_t * json_enseignants
)
```

Construit un nouvel objet Enseignants à partir de sa représentation en objet JSON.

**Paramètres**:

* **json_enseignants** Objet JSON de Enseignants.

**Renvoie**: Nouvelle instance allouée de Enseignants.

!> **Précondition**: json_enseignants doit contenir une clé "enseignants" stockant un tableau de Enseignant.

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

**Paramètres**:

* **es** Référence de Enseignants.
* **nom** Valeur du Nom à rechercher.

**Renvoie**: Référence de Enseignant ayant nom comme valeur de son attribut Nom.

!> **Précondition**: Enseignants doit posséder une référence Enseignant ayant nom comme valeur de son attribut Nom.

Itère parmi la liste des Enseignants jusqu'à trouver un Enseignant dont l'attribut Nom correspond au paramètre. Sinon, renvoie une erreur.

### fonction getEnseignantByPrenom()

```c
Enseignant getEnseignantByPrenom(
    Enseignants es,
    char * prenom
)
```

Accesseur de l'objet Enseignant à partir de sa Prenom parmi la liste des Enseignants.

**Paramètres**:

* **es** Référence de Enseignants.
* **prenom** Valeur de Prenom à rechercher.

**Renvoie**: Référence de Enseignant possédant prenom comme valeur de son attribut Prenom.

!> **Précondition**: Enseignants doit posséder une référence Enseignant ayant prenom comme valeur de son attribut Prenom.

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

**Paramètres**:

* **es** Référence de Enseignants.

**Renvoie**: Objet JSON de Enseignants de type json_t*.

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

**Paramètres**:

* **es** Référence de Enseignants.
* **e** Référence de Enseignant à rechercher.

**Renvoie**: true si un Enseignant de Enseignants est égale à Enseignant.

Vérifie par itération si un élément Enseignant de la liste des Enseignants est égale à l'objet Enseignant passé en paramètre.

### fonction ajouterEs()

```c
Enseignants ajouterEs(
    Enseignants es,
    Enseignant e
)
```

Ajoute une référence de l'objet Enseignant à la liste des Enseignants.

**Paramètres**:

* **es** Référence de Enseignants.
* **e** Référence de Enseignant à ajouter.

**Renvoie**: Enseignants possédant une référence de Enseignant parmi sa liste de Enseignement.

!> **Précondition**: Enseignants ne doit posséder aucune autre référence à Enseignant.

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

**Paramètres**:

* **e** Référence de Enseignants.
* **es** Référence de Enseignant à supprimer.

**Renvoie**: Enseignants ne possédant aucune référence de Enseignant.

!> **Précondition**: Enseignants ne doit pas être vide.

Vérifie d'abord que la liste ne soit pas vide. Ensuite, On itère jusqu'à ce qu'on trouve un élément de la liste des Enseignants dont l'objet Enseignant stocké est égale à celui en paramètre. Dans ce cas, on l'isole de la liste chaînée pour pouvoir libérer sa mémoire. Sinon, aucun élément ne sera supprimé.

### fonction afficherEnseignants()

```c
void afficherEnseignants(
    Enseignants es,
    bool isOrdered
)
```

Imprime tout Enseignant de la liste des Enseignants sur stdout, suivi d'un retour à ligne.

**Paramètres**:

* **es** Enseignants à afficher.
* **isOrdered** indique si la liste doit être ordonnée par son indice.

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

**Paramètres**:

* **es** Référence de Enseignants.

**Renvoie**: Représentation JSON de Enseignants de type char*.

Renvoie la représentation JSON en chaîne de caractères de Enseignants en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

#ifndef __ENSEIGNANTS_H__
#define __ENSEIGNANTS_H__

#include <stdbool.h>
#include <jansson.h>
#include "enseignant.h"

typedef struct s_enseignants* Enseignants;

Enseignants enseignants();

Enseignants enseignantsParser(json_t* json_enseignants);

Enseignant getEnseignantByNom(Enseignants es, char* nom);

Enseignant getEnseignantByPrenom(Enseignants es, char* prenom);

Enseignant getEnseignantByIndice(Enseignants es, int indice);

json_t* getJsonEnseignants(Enseignants es);

int sizeEnseignants(Enseignants es);

bool appartientEnseignants(Enseignants es, Enseignant e);

Enseignants ajouterEs(Enseignants es, Enseignant e);

Enseignants supprimerEs(Enseignants es, Enseignant e);

void afficherEnseignants(Enseignants es, bool isOrdered);

char* toStringEnseignants(Enseignants es);

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
