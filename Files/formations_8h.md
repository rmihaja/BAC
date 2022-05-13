# Référence du fichier include/formations.h

En-tête de la structure de données Formations.  [Plus de détails...](#description-détaillée)

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_formations](/Classes/structs__formations.md) * | **[Formations](/Files/formations_8h.md#typedef-formations)** <br>Objet Formations.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Formations](/Files/formations_8h.md#typedef-formations) | **[formations](/Files/formations_8h.md#fonction-formations)**(int taille_max)<br>Construit un nouvel objet Formations avec un tableau de Formation.  |
| [Formations](/Files/formations_8h.md#typedef-formations) | **[formationsParser](/Files/formations_8h.md#fonction-formationsparser)**([json_t](/Classes/structjson__t.md) * json_formations)<br>Construit un nouvel objet Formation à partir de sa représentation en objet JSON.  |
| [Formation](/Files/formation_8h.md#typedef-formation) | **[getFormationByIndice](/Files/formations_8h.md#fonction-getformationbyindice)**([Formations](/Files/formations_8h.md#typedef-formations) fs, int indice)<br>Accesseur de l'objet Formation à partir de son Indice dans Formations.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonFormations](/Files/formations_8h.md#fonction-getjsonformations)**([Formations](/Files/formations_8h.md#typedef-formations) fs)<br>Accesseur de la représentation en objet JSON de Formations.  |
| int | **[sizeFormations](/Files/formations_8h.md#fonction-sizeformations)**([Formations](/Files/formations_8h.md#typedef-formations) fs)<br>Accesseur de la taille de Formations.  |
| [Formations](/Files/formations_8h.md#typedef-formations) | **[ajouterFs](/Files/formations_8h.md#fonction-ajouterfs)**([Formations](/Files/formations_8h.md#typedef-formations) fs, [Formation](/Files/formation_8h.md#typedef-formation) f)<br>Ajoute une référence de l'objet Formation à Formations.  |
| void | **[afficherFormations](/Files/formations_8h.md#fonction-afficherformations)**([Formations](/Files/formations_8h.md#typedef-formations) fs) |
| void | **[afficherFormationsN](/Files/formations_8h.md#fonction-afficherformationsn)**([Formations](/Files/formations_8h.md#typedef-formations) fs, bool isOrdered)<br>Imprime le nom de toute Formation de Formations sur stdout, précédé de son indice dans la liste si ordonné, d'un tiret sinon et suivi d'un retour à la ligne.  |
| char * | **[toStringFormations](/Files/formations_8h.md#fonction-tostringformations)**([Formations](/Files/formations_8h.md#typedef-formations) fs)<br>Accesseur de la représentation en chaîne de caractère JSON de Formations.  |

## Description détaillée

En-tête de la structure de données Formations.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef Formations

```c
typedef struct s_formations* Formations;
```

Objet Formations.

## Documentation des fonctions

### fonction formations()

```c
Formations formations(
    int taille_max
)
```

Construit un nouvel objet Formations avec un tableau de Formation.

**Paramètres**:

* **taille_max** Taille maximale du tableau de Formation.

**Renvoie**: Nouvelle instance allouée de Formations.

Constructeur par défaut de l'objet Formations.

### fonction formationsParser()

```c
Formations formationsParser(
    json_t * json_formations
)
```

Construit un nouvel objet Formation à partir de sa représentation en objet JSON.

**Paramètres**:

* **json_formations** Objet JSON de Formations.

**Renvoie**: Nouvelles instance allouée de Formations.

!> **Précondition**: json_salles doit contenir une clé "formations" stockant un tableau de Formation.

Construit l'objet Formations en manipulant l'API Jansson. Pour cela, à partir d'une recherche par clé (s'il existe) de "formations", nous pouvons obtenir un tableau de Formation. Ensuite, on itère le tableau pour pouvoir ajouter chaque Formation à l'objet Formations, en faisant chaque fois appel à son constructeur à partir de la valeur renvoyée par l'API.

[json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string) , [json_array_foreach](https://jansson.readthedocs.pio/en/latest/apiref.html#c.json_array_foreach)

### fonction getFormationByIndice()

```c
Formation getFormationByIndice(
    Formations fs,
    int indice
)
```

Accesseur de l'objet Formation à partir de son Indice dans Formations.

**Paramètres**:

* **fs** Référence de Formations.
* **indice** Indice à laquelle se trouve la Formation recherchée.

**Renvoie**: Formation à l'indice indiquée

!> **Précondition**: Indice doit être positif et strictement inférieur à la taille de la liste. Formations ne doit pas être vide.

### fonction getJsonFormations()

```c
json_t * getJsonFormations(
    Formations fs
)
```

Accesseur de la représentation en objet JSON de Formations.

**Paramètres**:

* **fs** Référence de Formations.

**Renvoie**: Objet JSON de Formations de type json_t*.

Renvoie la représentation objet JSON de Formations en utilisant l'API Jansson. Pour cela, on construit un nouvel tableau JSON et en itérant la liste des Formations, on ajoute à ce tableau l'attribut Nom de chaque Formation.

[json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string) , [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) , [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)

### fonction sizeFormations()

```c
int sizeFormations(
    Formations fs
)
```

Accesseur de la taille de Formations.

**Paramètres**:

* **fs** Référence de Formations.

**Renvoie**: Taille de Formations de type int.

### fonction ajouterFs()

```c
Formations ajouterFs(
    Formations fs,
    Formation f
)
```

Ajoute une référence de l'objet Formation à Formations.

**Paramètres**:

* **fs** Référence de Formations.
* **f** Référence de Formation à ajouter.

**Renvoie**: Formations possédant une référence de Formation parmi son tableau de Formation.

!> **Précondition**: Formations ne doit posséder aucune autre référence à Formation.

Ajoute Formations à la tête de la liste des Formations si Formation n'en fait pas encore parti. Si non, on renvoie une erreur.

[appartientFormations](/Files/formations_8c.md#fonction-appartientformations)

### fonction afficherFormations()

```c
void afficherFormations(
    Formations fs
)
```

sa afficheFormation

### fonction afficherFormationsN()

```c
void afficherFormationsN(
    Formations fs,
    bool isOrdered
)
```

Imprime le nom de toute Formation de Formations sur stdout, précédé de son indice dans la liste si ordonné, d'un tiret sinon et suivi d'un retour à la ligne.

**Paramètres**:

* **fs** Formations à afficher.
* **isOrdered** indique si la liste doit être ordonnée par son indice.

Itère la liste des Enseignements pour pouvoir afficher le Nom de chaque Formation sur stdout, précédé de son indice dans la liste si l'ordre est paramétré à True, ou d'un tiret sinon. L'impression suit alors le format :

```txt

- {Nom de Formation}
- {Nom de Formation}
...
```

// ou : ```txt

1) {Nom de Formation}
2) {Nom de Formation}
...

```

[getFormationN](/Files/formation_8c.md#fonction-getformationn)


### fonction toStringFormations()

```c
char * toStringFormations(
    Formations fs
)
```

Accesseur de la représentation en chaîne de caractère JSON de Formations.

**Paramètres**:

* **fs** Référence de Formations.

**Renvoie**: Représentation JSON de Formations de type char*.

## Code source

```c

#ifndef __FORMATIONS_H__
#define __FORMATIONS_H__

#include <jansson.h>
#include "formation.h"

typedef struct s_formations* Formations;

Formations formations(int taille_max);

Formations formationsParser(json_t* json_formations);

Formation getFormationByIndice(Formations fs, int indice);

json_t* getJsonFormations(Formations fs);

int sizeFormations(Formations fs);

Formations ajouterFs(Formations fs, Formation f);


void afficherFormations(Formations fs);

void afficherFormationsN(Formations fs, bool isOrdered);

char* toStringFormations(Formations fs);

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
