# Référence du fichier include/creneau.h

En-tête de la structure de données Creneau.  [Plus de détails...](#description-détaillée)

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_creneau](/Classes/structs__creneau.md) * | **[Creneau](/Files/creneau_8h.md#typedef-creneau)** <br>Objet Creneau.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) | **[creneau](/Files/creneau_8h.md#fonction-creneau)**([Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e, [Horaire](/Files/horaire_8h.md#typedef-horaire) h, char * enseignement, char * formation, char * salle)<br>Construit un nouvel objet Creneau avec un objet Enseignant, un objet Horaire, un Enseignement, une Formation et une Salle.  |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) | **[creneauParser](/Files/creneau_8h.md#fonction-creneauparser)**([json_t](/Classes/structjson__t.md) * json_creneau)<br>Construit un nouvel objet Creneau à partir de sa représentation en objet JSON.  |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[getCreneauE](/Files/creneau_8h.md#fonction-getcreneaue)**([Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Accesseur de l'objet Enseignant du Creneau.  |
| [Horaire](/Files/horaire_8h.md#typedef-horaire) | **[getCreneauH](/Files/creneau_8h.md#fonction-getcreneauh)**([Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Accesseur de l'objet Horaire du Creneau.  |
| char * | **[getCreneauENS](/Files/creneau_8h.md#fonction-getcreneauens)**([Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Accesseur de l'objet Enseignement du Creneau.  |
| char * | **[getCreneauF](/Files/creneau_8h.md#fonction-getcreneauf)**([Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Accesseur de l'objet Formation du Creneau.  |
| char * | **[getCreneauS](/Files/creneau_8h.md#fonction-getcreneaus)**([Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Accesseur de l'objet Salle du Creneau.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonCreneau](/Files/creneau_8h.md#fonction-getjsoncreneau)**([Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Accesseur de la représentation en objet JSON du Creneau.  |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) | **[setCreneauE](/Files/creneau_8h.md#fonction-setcreneaue)**([Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e, [Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Définie l'objet Enseignant du Creneau.  |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) | **[setCreneauH](/Files/creneau_8h.md#fonction-setcreneauh)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h, [Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Définie l'objet Horaire du Creneau.  |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) | **[setCreneauENS](/Files/creneau_8h.md#fonction-setcreneauens)**(char * enseignement, [Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Définie l'objet Enseignement du Creneau.  |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) | **[setCreneauF](/Files/creneau_8h.md#fonction-setcreneauf)**(char * formation, [Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Définie l'objet Formation du Creneau.  |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) | **[setCreneauS](/Files/creneau_8h.md#fonction-setcreneaus)**(char * salle, [Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Définie l'objet Salle du Creneau.  |
| bool | **[equalsCreneau](/Files/creneau_8h.md#fonction-equalscreneau)**([Creneau](/Files/creneau_8h.md#typedef-creneau) c1, [Creneau](/Files/creneau_8h.md#typedef-creneau) c2)<br>compare deux Creneau.  |
| void | **[afficheCreneau](/Files/creneau_8h.md#fonction-affichecreneau)**([Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Imprime les attributs de Creneau sur stdout, suivi d'un retour à la ligne.  |
| char * | **[toStringCreneau](/Files/creneau_8h.md#fonction-tostringcreneau)**([Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Accesseur de la représentation en chaîne de caractère JSON de Creneau.  |

## Description détaillée

En-tête de la structure de données Creneau.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef Creneau

```c
typedef struct s_creneau* Creneau;
```

Objet Creneau.

## Documentation des fonctions

### fonction creneau()

```c
Creneau creneau(
    Enseignant e,
    Horaire h,
    char * enseignement,
    char * formation,
    char * salle
)
```

Construit un nouvel objet Creneau avec un objet Enseignant, un objet Horaire, un Enseignement, une Formation et une Salle.

**Paramètres**:

* **e** Enseignant du Creneau de type Enseignant.
* **h** Horaire du Creneau de type Horaire.
* **enseignement** Enseignement du Creneau de type char*.
* **formation** Formation du Creneau de type char*.
* **salle** Salle du Creneau de type char*.

**Renvoie**: Nouvelle instance allouée du Creneau.

Constructeur par défaut de l'objet Creneau.

### fonction creneauParser()

```c
Creneau creneauParser(
    json_t * json_creneau
)
```

Construit un nouvel objet Creneau à partir de sa représentation en objet JSON.

**Paramètres**:

* **json_creneau** Objet JSON du Creneau.

**Renvoie**: Nouvelle instance allouée du Creneau.

!> **Précondition**: json_creneau doit contenir une clé "enseignant", "horaire", "enseignement", "formation", "salle".

Construit l'objet Creneau en manipulant l'API Jansson. Pour cela, à partir d'une recherche par clé (s'il existe), nous pouvons accéder aux attributs "enseignant", "horaire", "enseignement", "formation" et "salle" de Creneau, que nous construisons ensuite à l'aide du constructeur par défaut, avec les objets Enseignant et Horaire préalablement construit à partir de leur représentation JSON également.

[enseignantParser](/Files/enseignant_8c.md#fonction-enseignantparser) , [horaireParser](/Files/horaire_8c.md#fonction-horaireparser) , [json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) , [json_object_get](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_get) , [json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string)

### fonction getCreneauE()

```c
Enseignant getCreneauE(
    Creneau c
)
```

Accesseur de l'objet Enseignant du Creneau.

**Paramètres**:

* **c** Référence du Creneau.

**Renvoie**: Référence de Enseignant du Creneau.

### fonction getCreneauH()

```c
Horaire getCreneauH(
    Creneau c
)
```

Accesseur de l'objet Horaire du Creneau.

**Paramètres**:

* **c** Référence du Creneau.

**Renvoie**: Référence de Horaire du Creneau.

### fonction getCreneauENS()

```c
char * getCreneauENS(
    Creneau c
)
```

Accesseur de l'objet Enseignement du Creneau.

**Paramètres**:

* **c** Référence du Creneau.

**Renvoie**: Valeur de Enseignement de type char*.

### fonction getCreneauF()

```c
char * getCreneauF(
    Creneau c
)
```

Accesseur de l'objet Formation du Creneau.

**Paramètres**:

* **c** Référence du Creneau.

**Renvoie**: Valeur de la Formation de type char*.

### fonction getCreneauS()

```c
char * getCreneauS(
    Creneau c
)
```

Accesseur de l'objet Salle du Creneau.

**Paramètres**:

* **c** Référence du Creneau.

**Renvoie**: Valeur de la Salle de type char*.

### fonction getJsonCreneau()

```c
json_t * getJsonCreneau(
    Creneau c
)
```

Accesseur de la représentation en objet JSON du Creneau.

**Paramètres**:

* **c** Référence du Creneau.

**Renvoie**: Objet JSON de Creneau de type json_t*.

Renvoie la représentation objet JSON du Creneau en utilisant l'API Jansson. Pour cela, on construit un nouvel objet JSON pour ensuite pouvoir y attacher les attributs clé-valeurs du Creneau, défini par "enseignant" et "horaire", faisant appel à la représentation objet JSON de Enseignant et Horaire, ainsi que "formation" et "salle".

[getJsonEnseignant](/Files/enseignant_8c.md#fonction-getjsonenseignant) , [getJsonHoraire](/Files/horaire_8c.md#fonction-getjsonhoraire) , [json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) , [json_object_set_new](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_set_new)

### fonction setCreneauE()

```c
Creneau setCreneauE(
    Enseignant e,
    Creneau c
)
```

Définie l'objet Enseignant du Creneau.

**Paramètres**:

* **e** Référence de l'objet Enseignant.
* **c** Référence du Creneau à modifier.

**Renvoie**: Creneau avec la nouvelle référence de Enseignant.

### fonction setCreneauH()

```c
Creneau setCreneauH(
    Horaire h,
    Creneau c
)
```

Définie l'objet Horaire du Creneau.

**Paramètres**:

* **h** Référence de l'objet Horaire.
* **c** Référence du Creneau à modifier.

**Renvoie**: Creneau avec la nouvelle référence de Horaire.

### fonction setCreneauENS()

```c
Creneau setCreneauENS(
    char * enseignement,
    Creneau c
)
```

Définie l'objet Enseignement du Creneau.

**Paramètres**:

* **enseignement** Valeur de Enseignement de type char*.
* **c** Référence du Creneau à modifier.

**Renvoie**: Creneau avec la nouvelle valeur de Enseignement.

### fonction setCreneauF()

```c
Creneau setCreneauF(
    char * formation,
    Creneau c
)
```

Définie l'objet Formation du Creneau.

**Paramètres**:

* **formation** Valeur de Formation de type char*.
* **c** Référence du Creneau à modifier.

**Renvoie**: Creneau avec la nouvelle valeur de Formation.

### fonction setCreneauS()

```c
Creneau setCreneauS(
    char * salle,
    Creneau c
)
```

Définie l'objet Salle du Creneau.

**Paramètres**:

* **salle** Valeur de Salle de type char*.
* **c** Référence du Creneau à modifier.

**Renvoie**: Creneau avec la nouvelle valeur de Salle.

### fonction equalsCreneau()

```c
bool equalsCreneau(
    Creneau c1,
    Creneau c2
)
```

compare deux Creneau.

**Paramètres**:

* **c1** Creneau 1 à comparer.
* **c2** Creneau 2 à comparer.

**Renvoie**:

* true si Creneau 1 et Creneau 2 possèdent les mêmes attributs Enseignant, Horaire, Formation et Salle.
* false si un ou plusieurs attributs de Creneau 1 et Creneau 2 diffèrent.

### fonction afficheCreneau()

```c
void afficheCreneau(
    Creneau c
)
```

Imprime les attributs de Creneau sur stdout, suivi d'un retour à la ligne.

**Paramètres**:

* **c** Référence de Creneau à afficher.

Imprime les attributs de l'objet Creneau en réutilisant l'affichage des objets Enseignant et Horaire, respectant alors le format :

```txt

{Salle} {Formation}
{Enseignement}
{Enseignant}
{Horaire}
```

[afficheEnseignant](/Files/enseignant_8c.md#fonction-afficheenseignant) , [afficheHoraire](/Files/horaire_8c.md#fonction-affichehoraire)

### fonction toStringCreneau()

```c
char * toStringCreneau(
    Creneau c
)
```

Accesseur de la représentation en chaîne de caractère JSON de Creneau.

**Paramètres**:

* **c** Référence de Creneau.

**Renvoie**: Représentation JSON de Creneau de type char*.

Renvoie la représentation JSON en chaîne de caractères du Creneau en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

#ifndef __CRENEAU_H__
#define __CRENEAU_H__

#include <stdbool.h>
#include <jansson.h>
#include "enseignant.h"
#include "horaire.h"

typedef struct s_creneau* Creneau;

Creneau creneau(Enseignant e, Horaire h, char* enseignement, char* formation, char* salle);

Creneau creneauParser(json_t* json_creneau);

Enseignant getCreneauE(Creneau c);

Horaire getCreneauH(Creneau c);

char* getCreneauENS(Creneau c);

char* getCreneauF(Creneau c);

char* getCreneauS(Creneau c);

json_t* getJsonCreneau(Creneau c);

Creneau setCreneauE(Enseignant e, Creneau c);

Creneau setCreneauH(Horaire h, Creneau c);

Creneau setCreneauENS(char* enseignement, Creneau c);

Creneau setCreneauF(char* formation, Creneau c);

Creneau setCreneauS(char* salle, Creneau c);

bool equalsCreneau(Creneau c1, Creneau c2);

void afficheCreneau(Creneau c);

char* toStringCreneau(Creneau c);

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
