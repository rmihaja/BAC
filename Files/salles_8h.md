# Référence du fichier include/salles.h

En-tête de la structure de données Salles.  [Plus de détails...](#description-détaillée)

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_salles](/Classes/structs__salles.md) * | **[Salles](/Files/salles_8h.md#typedef-salles)** <br>Objet Salles.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Salles](/Files/salles_8h.md#typedef-salles) | **[salles](/Files/salles_8h.md#fonction-salles)**()<br>Construit un nouvel objet Salles.  |
| [Salles](/Files/salles_8h.md#typedef-salles) | **[sallesParser](/Files/salles_8h.md#fonction-sallesparser)**([json_t](/Classes/structjson__t.md) * json_salles)<br>Construit un nouvel objet Salles à partir de sa représentation en objet JSON.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[getSalleByNom](/Files/salles_8h.md#fonction-getsallebynom)**([Salles](/Files/salles_8h.md#typedef-salles) ss, char * nom)<br>Accesseur de l'objet Salle à partir de son Nom parmi la liste des Salles.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[getSalleByIndice](/Files/salles_8h.md#fonction-getsallebyindice)**([Salles](/Files/salles_8h.md#typedef-salles) ss, int indice)<br>Accesseur de l'objet Salle à partir de son Indice dans la liste des Salles.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonSalles](/Files/salles_8h.md#fonction-getjsonsalles)**([Salles](/Files/salles_8h.md#typedef-salles) ss)<br>Accesseur de la représentation en objet JSON de Salles.  |
| int | **[sizeSalles](/Files/salles_8h.md#fonction-sizesalles)**([Salles](/Files/salles_8h.md#typedef-salles) ss)<br>Accesseur de la taille de la liste des Salles.  |
| bool | **[appartientSalles](/Files/salles_8h.md#fonction-appartientsalles)**([Salles](/Files/salles_8h.md#typedef-salles) ss, [Salle](/Files/salle_8h.md#typedef-salle) s)<br>vérifie si Salles possède une référence de l'objet Salle avec le même nom.  |
| [Salles](/Files/salles_8h.md#typedef-salles) | **[ajouterSs](/Files/salles_8h.md#fonction-ajouterss)**([Salles](/Files/salles_8h.md#typedef-salles) ss, [Salle](/Files/salle_8h.md#typedef-salle) s)<br>Ajoute une référence de l'objet Salle à la liste des Salles.  |
| void | **[afficherSalles](/Files/salles_8h.md#fonction-affichersalles)**([Salles](/Files/salles_8h.md#typedef-salles) ss)<br>Imprime toute Salle de la liste des Salles sur stdout, suivi d'un retour à la ligne.  |
| void | **[afficherSallesN](/Files/salles_8h.md#fonction-affichersallesn)**([Salles](/Files/salles_8h.md#typedef-salles) ss, bool isOrdered)<br>Imprime le nom de toute Salle de la liste des Salles sur stdout, précédé de son indice dans la liste si ordonné, d'un tiret sinon et suivi d'un retour à la ligne.  |
| char * | **[toStringSalles](/Files/salles_8h.md#fonction-tostringsalles)**([Salles](/Files/salles_8h.md#typedef-salles) ss)<br>Accesseur de la représentation en chaîne de caractère JSON de Salles.  |

## Description détaillée

En-tête de la structure de données Salles.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef Salles

```c
typedef struct s_salles* Salles;
```

Objet Salles.

## Documentation des fonctions

### fonction salles()

```c
Salles salles()
```

Construit un nouvel objet Salles.

**Renvoie**: Nouvelle instance allouée de Salles.

Constructeur par défaut de l'objet Salles.

### fonction sallesParser()

```c
Salles sallesParser(
    json_t * json_salles
)
```

Construit un nouvel objet Salles à partir de sa représentation en objet JSON.

**Paramètres**:

* **json_salles** Objet JSON de Salles.

**Renvoie**: Nouvelles instance allouée de Salles.

!> **Précondition**: json_salles doit contenir une clé "salles" stockant un tableau de Salle.

Construit l'objet Salles en manipulant l'API Jansson. Pour cela, à partir d'une recherche par clé (s'il existe) de "salles", nous pouvons obtenir un tableau de Salle. Ensuite, on itère le tableau pour pouvoir ajouter chaque Salle à l'objet Salles, en faisant chaque fois appel à son constructeur à partir de la valeur renvoyée par l'API.

[salleParser](/Files/salle_8c.md#fonction-salleparser) , [json_array_foreach](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_foreach)

### fonction getSalleByNom()

```c
Salle getSalleByNom(
    Salles ss,
    char * nom
)
```

Accesseur de l'objet Salle à partir de son Nom parmi la liste des Salles.

**Paramètres**:

* **ss** Référence de Salles.
* **nom** Valeur du Nom à rechercher.

**Renvoie**: Référence de Salle ayant nom comme valeur de son attribut Nom.

!> **Précondition**: Salles doit posséder une référence Salle ayant nom comme valeur de son attribut Nom.

Itère parmi la liste des Salles jusqu'à trouver une Salle dont l'attribut Nom correspond au paramètre. Sinon, renvoie une erreur.

### fonction getSalleByIndice()

```c
Salle getSalleByIndice(
    Salles ss,
    int indice
)
```

Accesseur de l'objet Salle à partir de son Indice dans la liste des Salles.

**Paramètres**:

* **ss** Référence de Salles.
* **indice** Indice à laquelle se trouve la Salle recherchée.

**Renvoie**: Nom de la Salle de type char*.

!> **Précondition**: Indice doit être positif et strictement inférieur à la taille de la liste. La liste des Salles ne doit pas être vide.

Itère parmi la liste des Salles Indice fois puis renvoie la référence de Salle stockée par l'élément courant.

### fonction getJsonSalles()

```c
json_t * getJsonSalles(
    Salles ss
)
```

Accesseur de la représentation en objet JSON de Salles.

**Paramètres**:

* **ss** Référence de Salles.

**Renvoie**: json_t*Objet JSON de Salles de type json_t*.

Renvoie la représentation objet JSON de Salles en utilisant l'API Jansson. Pour cela, on construit un nouvel objet JSON et on y attache la clé "salles" qui est un tableau. En itérant ensuite la liste des Salles, on ajoute à ce tableau la représentation objet JSON de chaque Salle.

[getJsonSalle](/Files/salle_8c.md#fonction-getjsonsalle) , [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) , [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)

### fonction sizeSalles()

```c
int sizeSalles(
    Salles ss
)
```

Accesseur de la taille de la liste des Salles.

**Paramètres**:

* **ss** Référence de Salles.

**Renvoie**: Taille de la liste des Salles de type int.

### fonction appartientSalles()

```c
bool appartientSalles(
    Salles ss,
    Salle s
)
```

vérifie si Salles possède une référence de l'objet Salle avec le même nom.

**Paramètres**:

* **ss** Référence de Salles.
* **s** Référence de Salle à comparer.

**Renvoie**: true si une Salle de Salles a le même nom que Salle.

Vérifie par itération si un élément Salle de la liste des Salles est égale à l'objet Salle passé en paramètre. Deux Salle sont considérés égaux s'ils ont le même nom.

### fonction ajouterSs()

```c
Salles ajouterSs(
    Salles ss,
    Salle s
)
```

Ajoute une référence de l'objet Salle à la liste des Salles.

**Paramètres**:

* **ss** Référence de Salles.
* **s** Référence de Salle à ajouter.

**Renvoie**: Salles possédant une référence de Salle parmi sa liste de Salle.

!> **Précondition**: Salles ne doit posséder aucune autre référence à Salle.

Ajoute Salle à la tête de la liste des Salles si Salle n'en fait pas encore parti. Si non, on renvoie une erreur.

[appartientSalles](/Files/salles_8c.md#fonction-appartientsalles)

### fonction afficherSalles()

```c
void afficherSalles(
    Salles ss
)
```

Imprime toute Salle de la liste des Salles sur stdout, suivi d'un retour à la ligne.

**Paramètres**:

* **ss** Salles à afficher.

Itère la liste des Salles pour pouvoir afficher chaque Salle à partir de sa représentation externe sur stdout. L'impression suit alors le format :

```txt

{Salle}

{Salle}

...
```

[afficheSalle](/Files/salle_8c.md#fonction-affichesalle)

### fonction afficherSallesN()

```c
void afficherSallesN(
    Salles ss,
    bool isOrdered
)
```

Imprime le nom de toute Salle de la liste des Salles sur stdout, précédé de son indice dans la liste si ordonné, d'un tiret sinon et suivi d'un retour à la ligne.

**Paramètres**:

* **ss** Salles à afficher.
* **isOrdered** indique si la liste doit être ordonnée par son indice.

### fonction toStringSalles()

```c
char * toStringSalles(
    Salles ss
)
```

Accesseur de la représentation en chaîne de caractère JSON de Salles.

**Paramètres**:

* **ss** Référence de Salles.

**Renvoie**: Représentation JSON de Salles de type char*.

Renvoie la représentation JSON en chaîne de caractères de Salles en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

#ifndef __SALLES_H__
#define __SALLES_H__

#include "salle.h"
#include <jansson.h>

typedef struct s_salles* Salles;

Salles salles();

Salles sallesParser(json_t* json_salles);

Salle getSalleByNom(Salles ss, char* nom);

Salle getSalleByIndice(Salles ss, int indice);

json_t* getJsonSalles(Salles ss);

int sizeSalles(Salles ss);

bool appartientSalles(Salles ss, Salle s);

Salles ajouterSs(Salles ss, Salle s);

void afficherSalles(Salles ss);

void afficherSallesN(Salles ss, bool isOrdered);


char* toStringSalles(Salles ss);

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
