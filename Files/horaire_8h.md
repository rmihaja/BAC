# Référence du fichier include/horaire.h

En-tête de la structure de données Horaire.  [Plus de détails...](#description-détaillée)

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_horaire](/Classes/structs__horaire.md) * | **[Horaire](/Files/horaire_8h.md#typedef-horaire)** <br>Objet Horaire.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Horaire](/Files/horaire_8h.md#typedef-horaire) | **[horaire](/Files/horaire_8h.md#fonction-horaire)**(int debut, int fin)<br>construit un nouvel objet Horaire avec un Début et une Fin.  |
| [Horaire](/Files/horaire_8h.md#typedef-horaire) | **[horaireParser](/Files/horaire_8h.md#fonction-horaireparser)**([json_t](/Classes/structjson__t.md) * json_horaire)<br>construit un nouvel objet Horaire à partir de sa représentation objet JSON.  |
| int | **[getDebut](/Files/horaire_8h.md#fonction-getdebut)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Accesseur de l'objet Debut de Horaire.  |
| int | **[getFin](/Files/horaire_8h.md#fonction-getfin)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Accesseur de l'objet Fin de Horaire.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonHoraire](/Files/horaire_8h.md#fonction-getjsonhoraire)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Accesseur de la représentation en objet JSON de Horaire.  |
| int | **[duree](/Files/horaire_8h.md#fonction-duree)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Calcule la durée d'une horaire.  |
| [Horaire](/Files/horaire_8h.md#typedef-horaire) | **[setDebut](/Files/horaire_8h.md#fonction-setdebut)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h, int debut)<br>Définie l'objet Debut de Horaire.  |
| [Horaire](/Files/horaire_8h.md#typedef-horaire) | **[setFin](/Files/horaire_8h.md#fonction-setfin)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h, int fin)<br>Définie l'objet Fin de Horaire.  |
| bool | **[equalsHoraire](/Files/horaire_8h.md#fonction-equalshoraire)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h1, [Horaire](/Files/horaire_8h.md#typedef-horaire) h2)<br>compare deux Horaire.  |
| void | **[afficheHoraire](/Files/horaire_8h.md#fonction-affichehoraire)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Imprime les attributs de Horaire sur stdout, suivi d'un retour à la ligne.  |
| char * | **[toStringHoraire](/Files/horaire_8h.md#fonction-tostringhoraire)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Accesseur de la représentation en chaîne de caractère JSON de Horaire.  |

## Description détaillée

En-tête de la structure de données Horaire.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef Horaire

```c
typedef struct s_horaire* Horaire;
```

Objet Horaire.

## Documentation des fonctions

### fonction horaire()

```c
Horaire horaire(
    int debut,
    int fin
)
```

construit un nouvel objet Horaire avec un Début et une Fin.

**Paramètres**:

* **debut** Heure de début de Horaire de type int.
* **fin** Heur de fin de Horaire de type int.

**Renvoie**: Nouvelle instance allouée de Horaire.

!> **Précondition**: Debut doit être dans l'intervalle $ \llbracket 8, 19 \rrbracket $ et Fin doit être dans l'intervalle $ \llbracket 9, 20 \rrbracket $. Debut et Fin ne doivent pas être égaux.

Constructeur par défaut de l'objet Horaire.

### fonction horaireParser()

```c
Horaire horaireParser(
    json_t * json_horaire
)
```

construit un nouvel objet Horaire à partir de sa représentation objet JSON.

**Paramètres**:

* **json_horaire** Objet JSON de Horaire.

**Renvoie**: Nouvelle instance allouée de Horaire .

!> **Précondition**: json_horaire doit contenir une clé "debut" et "fin".

Construit l'objet Horaire en manipulant l'API Jansson. Pour cela, à partir d'une recherche par clé (s'il existe), nous pouvons accéder aux attributs "debut" et "fin" de Horaire, que nous construisons ensuite à l'aide du constructeur par défaut.

[json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) , [json_object_get](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_get) , [json_integer_value](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_integer_value)

### fonction getDebut()

```c
int getDebut(
    Horaire h
)
```

Accesseur de l'objet Debut de Horaire.

**Paramètres**:

* **h** Référence de Horaire.

**Renvoie**: Valeur de Debut de type int.

### fonction getFin()

```c
int getFin(
    Horaire h
)
```

Accesseur de l'objet Fin de Horaire.

**Paramètres**:

* **h** Référence de Horaire.

**Renvoie**: Valeur de Fin de type int.

### fonction getJsonHoraire()

```c
json_t * getJsonHoraire(
    Horaire h
)
```

Accesseur de la représentation en objet JSON de Horaire.

**Paramètres**:

* **h** Référence de Horaire.

**Renvoie**: Objet JSON de Enseignant de type json_t*.

Renvoie la représentation objet JSON de Horaire en utilisant l'API Jansson. Pour cela, on construit un nouvel objet JSON pour ensuite pouvoir y attacher les attributs clé-valeurs de Horaire, défini par "debut" et "fin".

[json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) , [json_object_set_new](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_set_new)

### fonction duree()

```c
int duree(
    Horaire h
)
```

Calcule la durée d'une horaire.

**Paramètres**:

* **h** Référence de Horaire.

**Renvoie**: Durée de Horaire de type int.

Calcule $ \vert Fin - Debut \vert $. Mais comme $ Fin \gt Debut $ par construction, on peut alors tout simplement calculer $ Fin - Debut $

### fonction setDebut()

```c
Horaire setDebut(
    Horaire h,
    int debut
)
```

Définie l'objet Debut de Horaire.

**Paramètres**:

* **h** Référence de Horaire à modifier.
* **debut** Valeur de Debut de type int.

**Renvoie**: Horaire avec la nouvelle valeur de Debut.

### fonction setFin()

```c
Horaire setFin(
    Horaire h,
    int fin
)
```

Définie l'objet Fin de Horaire.

**Paramètres**:

* **h** Référence de Horaire à modifier.
* **fin** Valeur de Fin de type int.

**Renvoie**: Horaire avec la nouvelle valeur de Fin.

### fonction equalsHoraire()

```c
bool equalsHoraire(
    Horaire h1,
    Horaire h2
)
```

compare deux Horaire.

**Paramètres**:

* **h1** Horaire 1 à comparer.
* **h2** Horaire 2 à comparer.

**Renvoie**:

* true si Horaire 1 et Horaire 2 possèdent les mêmes attributs Debut et Fin.
* false si un ou plusieurs attributs de Horaire 1 et Horaire 2 diffèrent.

### fonction afficheHoraire()

```c
void afficheHoraire(
    Horaire h
)
```

Imprime les attributs de Horaire sur stdout, suivi d'un retour à la ligne.

**Paramètres**:

* **h** Référence de Horaire à afficher.

Imprime les attributs de l'objet Enseignant selon le format :

```txt
{Debut}h00 à {Fin}h00
```

### fonction toStringHoraire()

```c
char * toStringHoraire(
    Horaire h
)
```

Accesseur de la représentation en chaîne de caractère JSON de Horaire.

**Paramètres**:

* **h** Référence de Horaire.

**Renvoie**: Représentation JSON de Enseignant de type char*.

Renvoie la représentation JSON en chaîne de caractères de Horaire en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

#ifndef __HORAIRE_H__
#define __HORAIRE_H__

#include <stdlib.h>
#include <stdbool.h>
#include <jansson.h>

typedef struct s_horaire* Horaire;

Horaire horaire(int debut, int fin);

Horaire horaireParser(json_t* json_horaire);

int getDebut(Horaire h);

int getFin(Horaire h);

json_t* getJsonHoraire(Horaire h);

int duree(Horaire h);

Horaire setDebut(Horaire h, int debut);

Horaire setFin(Horaire h, int fin);

bool equalsHoraire(Horaire h1, Horaire h2);

void afficheHoraire(Horaire h);

char* toStringHoraire(Horaire h);

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0

[Voir la documentation Doxygen originale](https://rmihaja.github.io/BAC/doxygen/index.html)
