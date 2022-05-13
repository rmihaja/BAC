# Référence du fichier include/entree.h

En-tête des fonctions d'entrées.  [Plus de détails...](#description-détaillée)

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| bool | **[getCharInput](/Files/entree_8h.md#fonction-getcharinput)**(char * dest)<br>Teste une entrée utilisateur de format chaîne de caractères attendu.  |
| bool | **[getIntInput](/Files/entree_8h.md#fonction-getintinput)**(int * i)<br>Teste une entrée utilisateur de format entier attendu.  |
| bool | **[getUserInput](/Files/entree_8h.md#fonction-getuserinput)**(char *message, char* description, char * value)<br>Lit une entrée utilisateur de format chaîne de caractères.  |
| int | **[getChoiceInput](/Files/entree_8h.md#fonction-getchoiceinput)**(char * message, int maxValue)<br>Lit le choix entier de l'utilisateur parmi une liste à afficher. Le choix est défini entre 0 (Quitter) et maxValue.  |
| int | **[getIntervalInput](/Files/entree_8h.md#fonction-getintervalinput)**(char * message, int minValue, int maxValue)<br>Lit l'entrée d'un entier de l'utilisateur parmi une intervalle défini par minValue et maxValue.  |
| int | **[getAnyInput](/Files/entree_8h.md#fonction-getanyinput)**()<br>demande une réponse physique de l'utilisateur par un appuie sur la touche <ENTREE>  |
| int | **[getCancelInput](/Files/entree_8h.md#fonction-getcancelinput)**()<br>Renvoie au gestionnaire d'évènement une demande de revenir en arrière, marquée par l'entier -1.  |
| int | **[getRetryInput](/Files/entree_8h.md#fonction-getretryinput)**(char * description)<br>Présente une erreur à l'utilisateur le demandant de réessayer. Puis lit le choix de l'utilisateur.  |

## Macros

|                | Nom           |
| -------------- | -------------- |
|  | **[println](/Files/entree_8h.md#define-println)**(...) <br>permet d'imprimer une chaîne suivi deux retours à la ligne.  |
|  | **[display](/Files/entree_8h.md#define-display)**(format, ...) <br>permet d'imprimer une variable selon un format, suivi de deux retours à la ligne.  |
|  | **[BUFFER_SIZE](/Files/entree_8h.md#define-buffer-size)** <br>nombre de caractère maximale que le module peut lire par entrée.  |

## Description détaillée

En-tête des fonctions d'entrées.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

?> **Note**: Dû à la technicité des fonctions présentées ici, la documentation se trouvera exclusivement dans le code source.

**Copyright**: Copyright (c) 2022

## Documentation des fonctions

### fonction getCharInput()

```c
bool getCharInput(
    char * dest
)
```

Teste une entrée utilisateur de format chaîne de caractères attendu.

**Paramètres**:

* **dest** adresse où sera stocké l'entrée utilisateur

**Voir également**: [code source](https://stackoverflow.com/questions/7831755/what-is-the-simplest-way-of-getting-user-input-in-c)

**Renvoie**: true si l'entrée utilisateur a été lu entièrement (dans la limite de BUFFERSIZE)

!> **Précondition**: dest doit être une adresse allouée de taille BUFFER_SIZE

### fonction getIntInput()

```c
bool getIntInput(
    int * i
)
```

Teste une entrée utilisateur de format entier attendu.

**Paramètres**:

* **i** adresse où sera stocké l'entrée utilisateur

**Renvoie**: true si l'entrée utilisateur a été lu en entier (dans la limite de BUFFERSIZE)

!> **Précondition**: i doit être une adresse d'entier allouée

fgets et sscanf permet de renvoie true si l'entrée utilisateur rentre dans line et qu'elle respecte bien le format attendu.

### fonction getUserInput()

```c
bool getUserInput(
    char * message,
    char * description,
    char * value
)
```

Lit une entrée utilisateur de format chaîne de caractères.

**Paramètres**:

* **message** Message à afficher à l'utilisateur avant de présenter l'entrée
* **description** Donnée abstrait attendu à l'utilisateur, affiché sur la même ligne que l'entrée
* **value** adresse où sera stocké l'entrée utilisateur

**Renvoie**:

* true
* false

L'affichage sera présenté comme suit :

```c
{Message}

{Description} : _
```

### fonction getChoiceInput()

```c
int getChoiceInput(
    char * message,
    int maxValue
)
```

Lit le choix entier de l'utilisateur parmi une liste à afficher. Le choix est défini entre 0 (Quitter) et maxValue.

**Paramètres**:

* **message** Liste de choix affichée à l'utilisateur.
* **maxValue** Valeur maximale du choix utilisateur (inclus).

**Renvoie**: int représentant le choix de l'utilisateur

### fonction getIntervalInput()

```c
int getIntervalInput(
    char * message,
    int minValue,
    int maxValue
)
```

Lit l'entrée d'un entier de l'utilisateur parmi une intervalle défini par minValue et maxValue.

**Paramètres**:

* **message** Message à afficher avant de prendre l'entrée.
* **minValue** Valeur minimale du choix (inclus).
* **maxValue** Valeur maximale du choix (inclus).

**Renvoie**: int parmi l'intervalle d'entier.

### fonction getAnyInput()

```c
int getAnyInput()
```

demande une réponse physique de l'utilisateur par un appuie sur la touche <ENTREE>

**Renvoie**: 0

### fonction getCancelInput()

```c
int getCancelInput()
```

Renvoie au gestionnaire d'évènement une demande de revenir en arrière, marquée par l'entier -1.

**Renvoie**: -1

### fonction getRetryInput()

```c
int getRetryInput(
    char * description
)
```

Présente une erreur à l'utilisateur le demandant de réessayer. Puis lit le choix de l'utilisateur.

**Paramètres**:

* **description** valeur qui présente l'erreur

**Renvoie**: 0 si l'utilisateur veut quitter l'opération, 1 si il veut réessayer.

## Documentation des macros

### define println

```c
#define println(
    ...
)
printf( __VA_ARGS__ "\n\n" )
```

permet d'imprimer une chaîne suivi deux retours à la ligne.

### define display

```c
#define display(
    format,
    ...
)
printf(format "\n\n", __VA_ARGS__)
```

permet d'imprimer une variable selon un format, suivi de deux retours à la ligne.

### define BUFFER_SIZE

```c
#define BUFFER_SIZE 256
```

nombre de caractère maximale que le module peut lire par entrée.

## Code source

```c

#ifndef __ENTREE_H__
#define __ENTREE_H__

#define println(...)  printf( __VA_ARGS__ "\n\n" )

#define display(format, ...)  printf(format "\n\n", __VA_ARGS__)

#define BUFFER_SIZE 256

#include <stdbool.h>

bool getCharInput(char* dest);
bool getIntInput(int* i);
bool getUserInput(char* message, char* description, char* value);

int getChoiceInput(char* message, int maxValue);
int getIntervalInput(char* message, int minValue, int maxValue);
int getAnyInput();
int getCancelInput();
int getRetryInput(char* description);

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
