# Référence du fichier include/controle.h

En-tête de la structure de données Controle.  [Plus de détails...](#description-détaillée)

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_controle](/Classes/structs__controle.md) * | **[Controle](/Files/controle_8h.md#typedef-controle)** <br>Objet Controle.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Controle](/Files/controle_8h.md#typedef-controle) | **[controle](/Files/controle_8h.md#fonction-controle)**(char * cheminData)<br>Construit un nouvelle objet Controle à partir des données JSON s'il existe.  |
| int | **[run](/Files/controle_8h.md#fonction-run)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Boucle principale de l'interface de Controle.  |

## Description détaillée

En-tête de la structure de données Controle.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef Controle

```c
typedef struct s_controle* Controle;
```

Objet Controle.

## Documentation des fonctions

### fonction controle()

```c
Controle controle(
    char * cheminData
)
```

Construit un nouvelle objet Controle à partir des données JSON s'il existe.

**Paramètres**:

* **cheminData** chemin du fichier JSON contenant les données

**Renvoie**: Nouvelle instance alloué de Controle

!> **Précondition**: le fichier JSON doit respecter les clés-valeurs de chaque structure.

Constructeur par défaut de l'objet Controle.

### fonction run()

```c
int run(
    Controle C
)
```

Boucle principale de l'interface de Controle.

**Paramètres**:

* **C** Référence de Controle

**Renvoie**: 0 pour quitter.

Affiche d'abord le panneau Bienvenue à l'initialisation puis exécute la boucle.

[afficherProchainPanneau](/Files/controle_8c.md#fonction-afficherprochainpanneau)

## Code source

```c

#ifndef __CONTROLE_H__
#define __CONTROLE_H__

#include "formations.h"
#include "enseignants.h"
#include "enseignements.h"
#include "salles.h"
#include "entree.h"

typedef struct s_controle* Controle;

Controle controle(char* cheminData);

int run(Controle C);

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0

[Voir la documentation Doxygen originale](https://rmihaja.github.io/BAC/doxygen/index.html)
