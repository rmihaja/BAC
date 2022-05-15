# Référence du fichier src/view/entree.c

Code source des fonctions d'entrées.  [Plus de détails...](#description-détaillée)

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| bool | **[getCharInput](/Files/entree_8c.md#fonction-getcharinput)**(char * dest)<br>Teste une entrée utilisateur de format chaîne de caractères attendu.  |
| bool | **[getIntInput](/Files/entree_8c.md#fonction-getintinput)**(int * i)<br>Teste une entrée utilisateur de format entier attendu.  |
| bool | **[getUserInput](/Files/entree_8c.md#fonction-getuserinput)**(char *message, char* description, char * value)<br>Lit une entrée utilisateur de format chaîne de caractères.  |
| int | **[getChoiceInput](/Files/entree_8c.md#fonction-getchoiceinput)**(char * message, int maxValue)<br>Lit le choix entier de l'utilisateur parmi une liste à afficher. Le choix est défini entre 0 (Quitter) et maxValue.  |
| int | **[getIntervalInput](/Files/entree_8c.md#fonction-getintervalinput)**(char * message, int minValue, int maxValue)<br>Lit l'entrée d'un entier de l'utilisateur parmi une intervalle défini par minValue et maxValue.  |
| int | **[getAnyInput](/Files/entree_8c.md#fonction-getanyinput)**()<br>demande une réponse physique de l'utilisateur par un appuie sur la touche <ENTREE>  |
| int | **[getCancelInput](/Files/entree_8c.md#fonction-getcancelinput)**()<br>Renvoie au gestionnaire d'évènement une demande de revenir en arrière, marquée par l'entier -1.  |
| int | **[getRetryInput](/Files/entree_8c.md#fonction-getretryinput)**(char * description)<br>Présente une erreur à l'utilisateur le demandant de réessayer. Puis lit le choix de l'utilisateur.  |

## Description détaillée

Code source des fonctions d'entrées.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

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

## Code source

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entree.h"

#ifdef DEBUG
#include "tests.h"
#endif

 /************************************************************\
 *                   Fonctions d'affichage                    *
 \************************************************************/


bool getCharInput(char* dest) {
    bool isWholeInputRead = true;
    int total_len = BUFFER_SIZE - 1; // ? la dernière ligne est le caractère '\0' ou EOF
    char* line = (char*)malloc(total_len * sizeof(char));

    fgets(line, total_len, stdin);

    /* if the whole line wasn't read, we'll return FALSE but still copy temp into dest */
    if (line[strlen(line) - 1] != '\n') {
        isWholeInputRead = false;
    }
    else {
        /* overwrite the '\n' if it does infact exist */
        line[strlen(line) - 1] = '\0';
    }

    strcpy(dest, line);
    free(line);

    return isWholeInputRead;
}

bool getIntInput(int* i) {
    char line[BUFFER_SIZE];
    return fgets(line, sizeof(line), stdin) && sscanf(line, "%d", i);
}

bool getUserInput(char* message, char* description, char* value) {
    if (*message != '\0') {
        display("%s", message);
    }
    printf("%s : ", description);
    while (!getCharInput(value)) {
        display("Entrée \"%s\" invalide. Veuillez réessayer", value);
        printf("%s : ", description);
    }
    return true;
}

int getChoiceInput(char* message, int maxValue) {
    int choice = -1;
    display("%s", message);
    println("0) Quitter");
    printf("Votre choix : ");
    bool isInputValid = getIntInput(&choice);
    bool isChoiceValid = 0 <= choice && choice <= maxValue;
    while (!isInputValid || !isChoiceValid) {
        println("Choix invalide. Veuillez réessayer");
        printf("Votre choix : ");
        isInputValid = getIntInput(&choice);
        isChoiceValid = 0 <= choice && choice <= maxValue;
    }
    puts("");
    return choice;
}

int getIntervalInput(char* message, int minValue, int maxValue) {
    int choice;
    display("%s", message);
    printf("Votre choix : ");
    bool isInputValid = getIntInput(&choice);
    bool isChoiceValid = minValue <= choice && choice <= maxValue;
    while (!isInputValid || !isChoiceValid) {
        println("Choix invalide. Veuillez réessayer");
        printf("Votre choix : ");
        isInputValid = getIntInput(&choice);
        isChoiceValid = minValue <= choice && choice <= maxValue;
    }
    puts("");
    return choice;
}

int getAnyInput() {
    char* s;
    println("Appuyer sur <ENTREE> pour continuer.");
    getCharInput(s);
    return 0;
}

int getCancelInput() {
    println("Opération annulée.");
    return -1;
}

int getRetryInput(char* description) {
    display("Désolé, %s avec les informations renseignées existe déjà.", description);
    if (getChoiceInput("1) Réessayer", 1) == 0) {
        return getCancelInput();
    }
    return 1;
}

#ifdef TEST

int main() {

    // init

    // testing

    return 0;
}

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0

[Voir la documentation Doxygen originale](https://rmihaja.github.io/BAC/doxygen/index.html)
