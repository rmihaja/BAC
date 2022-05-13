# Référence du fichier include/formation.h

En-tête de la structure de données Formation.  [Plus de détails...](#description-détaillée)

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_formation](/Classes/structs__formation.md) * | **[Formation](/Files/formation_8h.md#typedef-formation)** <br>Objet Formation.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Formation](/Files/formation_8h.md#typedef-formation) | **[formation](/Files/formation_8h.md#fonction-formation)**(char * nom)<br>Construit un nouvel objet Formation avec un Nom et une liste de Creneau vide.  |
| [Formation](/Files/formation_8h.md#typedef-formation) | **[formationParser](/Files/formation_8h.md#fonction-formationparser)**([json_t](/Classes/structjson__t.md) * json_formation)<br>Construit un nouvel objet Formation à partir de sa représentation en objet JSON.  |
| char * | **[getFormationN](/Files/formation_8h.md#fonction-getformationn)**([Formation](/Files/formation_8h.md#typedef-formation) f)<br>Accesseur de l'objet Nom de Formation.  |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) | **[getFormationCByIndice](/Files/formation_8h.md#fonction-getformationcbyindice)**([Formation](/Files/formation_8h.md#typedef-formation) f, int indice)<br>Accesseur de l'objet Creneau à partir de son Indice dans Formation.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonFormation](/Files/formation_8h.md#fonction-getjsonformation)**([Formation](/Files/formation_8h.md#typedef-formation) f)<br>Accesseur de la représentation en objet JSON de Formation.  |
| int | **[sizeFormationC](/Files/formation_8h.md#fonction-sizeformationc)**([Formation](/Files/formation_8h.md#typedef-formation) f)<br>Accesseur de la taille de la liste de Creneau de Formation.  |
| [Formation](/Files/formation_8h.md#typedef-formation) | **[ajouterFormationC](/Files/formation_8h.md#fonction-ajouterformationc)**([Formation](/Files/formation_8h.md#typedef-formation) f, [Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Ajoute une référence de l'objet Creneau à la liste de Créneau de Formation.  |
| [Formation](/Files/formation_8h.md#typedef-formation) | **[supprimerFormationH](/Files/formation_8h.md#fonction-supprimerformationh)**([Formation](/Files/formation_8h.md#typedef-formation) f, [Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Supprime tout Creneau alloué à Formation dans l'intervalle de Horaire.  |
| bool | **[isFreeFormation](/Files/formation_8h.md#fonction-isfreeformation)**([Formation](/Files/formation_8h.md#typedef-formation) f, [Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Vérifie si Formation ne contient aucun créneau réservé dans l'intervalle de Horaire.  |
| bool | **[isFullFormation](/Files/formation_8h.md#fonction-isfullformation)**([Formation](/Files/formation_8h.md#typedef-formation) f)<br>Vérifie si Formation a atteint son maximum de Creneau allouable pour la journée. Le maximum est fixé à 4 Creneau.  |
| void | **[afficheFormation](/Files/formation_8h.md#fonction-afficheformation)**([Formation](/Files/formation_8h.md#typedef-formation) f, bool isOrdered)<br>Imprime le nom de Formation ainsi que sa liste de Creneau sur stdout, suivi d'un retour à la ligne.  |
| char * | **[toStringFormation](/Files/formation_8h.md#fonction-tostringformation)**([Formation](/Files/formation_8h.md#typedef-formation) f)<br>Accesseur de la représentation en chaîne de caractère JSON de Formation.  |

## Description détaillée

En-tête de la structure de données Formation.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef Formation

```c
typedef struct s_formation* Formation;
```

Objet Formation.

## Documentation des fonctions

### fonction formation()

```c
Formation formation(
    char * nom
)
```

Construit un nouvel objet Formation avec un Nom et une liste de Creneau vide.

**Paramètres**:

* **nom** Nom de Formation de type char*.

**Renvoie**: Nouvelle instance allouée de Formation.

Constructeur par défaut de l'objet Formation.

### fonction formationParser()

```c
Formation formationParser(
    json_t * json_formation
)
```

Construit un nouvel objet Formation à partir de sa représentation en objet JSON.

**Paramètres**:

* **json_formation** Objet JSON de Formation.

**Renvoie**: Nouvelle instance allouée de Formation.

!> **Précondition**: json_formation doit contenir une clé "nom" et "crenaux" stockant un tableau de Creneau.

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

**Paramètres**:

* **f** Référence de Formation.

**Renvoie**: json_t*Objet JSON de Formation de type json_t*.

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

**Paramètres**:

* **f** Référence de Formation.
* **c** Référence de Creneau à ajouter.

**Renvoie**: Formation possédant une référence de Creneau parmi la liste de Creneau si Formation était libre dans l'intervalle de Horaire.

!> **Précondition**: Formation doit être libre dans l'intervalle de Horaire indiqué par Creneau. Formation ne doit pas être complet. Formation de Creneau doit avoir Nom de Formation comme valeur.

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

**Paramètres**:

* **f** Référence de Formation.
* **h** Référence de Horaire représentant l'intervalle de suppression.

**Renvoie**: Formation ne possédant aucun Creneau réservé dans l'intervalle de suppression, si un Creneau a été alloué.

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

**Paramètres**:

* **f** Référence de Salle.
* **h** Référence de Horaire représentant l'intervalle de vérification.

**Renvoie**:

* true si aucun Creneau n'a été réservé dans l'intervalle de Horaire.
* false si un ou plusieurs Creneau a été réservé dans l'intervalle de Horaire.

Une Formation est considéré comme "libre" si pour tout Creneau dans sa liste de Creneau, aucune borne (Debut et Fin) de Horaire indiqué en paramètre n'englobe un Horaire de Creneau et n'est dans l'intervalle Horaire indiqué pour tout Creneau dans la liste de Formation.

### fonction isFullFormation()

```c
bool isFullFormation(
    Formation f
)
```

Vérifie si Formation a atteint son maximum de Creneau allouable pour la journée. Le maximum est fixé à 4 Creneau.

**Paramètres**:

* **f** Référence de Formation.

**Renvoie**:

* true si la taille de la liste de Creneau est inférieure ou égale à 4.
* false si la taille dépasse le maximum de Creneau allouable fixé.

La taille maximale de Creneau allouable à une Formation est 4, défini par la spécification du TAD.

### fonction afficheFormation()

```c
void afficheFormation(
    Formation f,
    bool isOrdered
)
```

Imprime le nom de Formation ainsi que sa liste de Creneau sur stdout, suivi d'un retour à la ligne.

**Paramètres**:

* **f** Formation à afficher.
* **isOrdered** permet de préfixer l'indice de Creneau dans la liste de Creneau sur son affichage

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

**Paramètres**:

* **f** Référence de Formation.

**Renvoie**: Représentation JSON de Formation de type char*.

Renvoie la représentation JSON en chaîne de caractères de Formation en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

#ifndef __FORMATION_H__
#define __FORMATION_H__

#include <stdbool.h>
#include <jansson.h>
#include "creneau.h"

typedef struct s_formation* Formation;

Formation formation(char* nom);

Formation formationParser(json_t* json_formation);

char* getFormationN(Formation f);

Creneau getFormationCByIndice(Formation f, int indice);

json_t* getJsonFormation(Formation f);

int sizeFormationC(Formation f);

Formation ajouterFormationC(Formation f, Creneau c);

Formation supprimerFormationH(Formation f, Horaire h);

bool isFreeFormation(Formation f, Horaire h);

bool isFullFormation(Formation f);

void afficheFormation(Formation f, bool isOrdered);

char* toStringFormation(Formation f);

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
