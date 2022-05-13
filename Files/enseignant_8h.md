# Référence du fichier include/enseignant.h

En-tête de la structure de données Enseignant.  [Plus de détails...](#description-détaillée)

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_enseignant](/Classes/structs__enseignant.md) * | **[Enseignant](/Files/enseignant_8h.md#typedef-enseignant)** <br>Objet Enseignant.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[enseignant](/Files/enseignant_8h.md#fonction-enseignant)**()<br>Construit un nouvel objet Enseignant avec un Nom et un Prenom vide.  |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[enseignantCopie](/Files/enseignant_8h.md#fonction-enseignantcopie)**(char *nom, char* prenom)<br>Construit un nouvel objet Enseignant avec un Nom et un Prenom.  |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[enseignantParser](/Files/enseignant_8h.md#fonction-enseignantparser)**([json_t](/Classes/structjson__t.md) * json_enseignant)<br>Construit un nouvel objet Enseignant à partir de sa représentation en objet JSON.  |
| char * | **[getNom](/Files/enseignant_8h.md#fonction-getnom)**([Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>Accesseur de l'objet Nom de Enseignant.  |
| char * | **[getPrenom](/Files/enseignant_8h.md#fonction-getprenom)**([Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>Accesseur de l'objet Prenom de Enseignant.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonEnseignant](/Files/enseignant_8h.md#fonction-getjsonenseignant)**([Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>Accesseur de la représentation en objet JSON de Enseignant.  |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[setNom](/Files/enseignant_8h.md#fonction-setnom)**([Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e, char * nom)<br>Définie l'objet Nom de Enseignant.  |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[setPrenom](/Files/enseignant_8h.md#fonction-setprenom)**([Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e, char * prenom)<br>Définie l'objet Prenom de Enseignant.  |
| bool | **[equalsEnseignant](/Files/enseignant_8h.md#fonction-equalsenseignant)**([Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e1, [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e2)<br>compare deux Enseignant.  |
| void | **[afficheEnseignant](/Files/enseignant_8h.md#fonction-afficheenseignant)**([Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>Imprime les attributs de Enseignant sur stdout, suivi d'un retour à la ligne.  |
| char * | **[toStringEnseignant](/Files/enseignant_8h.md#fonction-tostringenseignant)**([Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>Accesseur de la représentation en chaîne de caractère JSON de Enseignant.  |

## Description détaillée

En-tête de la structure de données Enseignant.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef Enseignant

```c
typedef struct s_enseignant* Enseignant;
```

Objet Enseignant.

## Documentation des fonctions

### fonction enseignant()

```c
Enseignant enseignant()
```

Construit un nouvel objet Enseignant avec un Nom et un Prenom vide.

**Renvoie**: Nouvelle instance allouée de Enseignant.

Constructeur par défaut de l'objet Enseignant.

### fonction enseignantCopie()

```c
Enseignant enseignantCopie(
    char * nom,
    char * prenom
)
```

Construit un nouvel objet Enseignant avec un Nom et un Prenom.

**Paramètres**:

* **nom** Nom de Enseignant de type char*.
* **prenom** Prenom de Enseignant de type char*.

**Renvoie**: Nouvelle instance allouée de Enseignant.

### fonction enseignantParser()

```c
Enseignant enseignantParser(
    json_t * json_enseignant
)
```

Construit un nouvel objet Enseignant à partir de sa représentation en objet JSON.

**Paramètres**:

* **json_enseignant** Objet JSON de Enseignant.

**Renvoie**: Nouvelle instance allouée de Enseignant.

!> **Précondition**: json_enseignant doit contenir une clé "nom" et "prenom".

Construit l'objet Enseignant en manipulant l'API Jansson. Pour cela, à partir d'une recherche par clé (s'il existe), nous pouvons accéder aux attributs "nom" et "prenom" de Enseignant, que nous construisons ensuite à l'aide du constructeur par défaut.

[json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) , [json_object_get](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_get) , [json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string)

### fonction getNom()

```c
char * getNom(
    Enseignant e
)
```

Accesseur de l'objet Nom de Enseignant.

**Paramètres**:

* **e** Référence de Enseignant.

**Renvoie**: Valeur du Nom de type char*.

### fonction getPrenom()

```c
char * getPrenom(
    Enseignant e
)
```

Accesseur de l'objet Prenom de Enseignant.

**Paramètres**:

* **e** Référence de Enseignant.

**Renvoie**: Valeur de la Prenom de type char*.

### fonction getJsonEnseignant()

```c
json_t * getJsonEnseignant(
    Enseignant e
)
```

Accesseur de la représentation en objet JSON de Enseignant.

**Paramètres**:

* **e** Référence de Enseignant.

**Renvoie**: Objet JSON de Enseignant de type json_t*.

Renvoie la représentation objet JSON de Enseignant en utilisant l'API Jansson. Pour cela, on construit un nouvel objet JSON pour ensuite pouvoir y attacher les attributs clé-valeurs de Enseignant, défini par "nom" et "prenom".

[json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) , [json_object_set_new](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_set_new)

### fonction setNom()

```c
Enseignant setNom(
    Enseignant e,
    char * nom
)
```

Définie l'objet Nom de Enseignant.

**Paramètres**:

* **e** Référence de Enseignant à modifier.
* **nom** Valeur du Nom de type char*.

**Renvoie**: Enseignant avec la nouvelle valeur de Nom.

### fonction setPrenom()

```c
Enseignant setPrenom(
    Enseignant e,
    char * prenom
)
```

Définie l'objet Prenom de Enseignant.

**Paramètres**:

* **e** Référence de Enseignant à modifier.
* **prenom** Valeur de Matière de type char*.

**Renvoie**: Enseignant avec la nouvelle valeur de Prenom.

### fonction equalsEnseignant()

```c
bool equalsEnseignant(
    Enseignant e1,
    Enseignant e2
)
```

compare deux Enseignant.

**Paramètres**:

* **e1** Enseignant 1 à comparer.
* **e2** Enseignant 2 à comparer.

**Renvoie**:

* true si Enseignant 1 et Enseignant 2 possèdent les mêmes attributs Nom et Prenom.
* false si un ou plusieurs attributs de Enseignant 1 et Enseignant 2 diffèrent.

### fonction afficheEnseignant()

```c
void afficheEnseignant(
    Enseignant e
)
```

Imprime les attributs de Enseignant sur stdout, suivi d'un retour à la ligne.

**Paramètres**:

* **e** Référence de Enseignant à afficher.

Imprime les attributs de l'objet Enseignant selon le format :

```txt

{Nom} {Prenom}
```

### fonction toStringEnseignant()

```c
char * toStringEnseignant(
    Enseignant e
)
```

Accesseur de la représentation en chaîne de caractère JSON de Enseignant.

**Paramètres**:

* **e** Référence de Enseignant.

**Renvoie**: Représentation JSON de Enseignant de type char*.

Renvoie la représentation JSON en chaîne de caractères de Enseignant en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

#ifndef __ENSEIGNANT_H__
#define __ENSEIGNANT_H__

#include <stdbool.h>
#include <jansson.h>

typedef struct s_enseignant* Enseignant;

Enseignant enseignant();

Enseignant enseignantCopie(char* nom, char* prenom);

Enseignant enseignantParser(json_t* json_enseignant);

char* getNom(Enseignant e);

char* getPrenom(Enseignant e);

json_t* getJsonEnseignant(Enseignant e);

Enseignant setNom(Enseignant e, char* nom);

Enseignant setPrenom(Enseignant e, char* prenom);

bool equalsEnseignant(Enseignant e1, Enseignant e2);

void afficheEnseignant(Enseignant e);

char* toStringEnseignant(Enseignant e);

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
