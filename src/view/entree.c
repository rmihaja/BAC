/**
 * @file entree.c
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief Code source des fonctions d'entrées
 *
 * @copyright Copyright (c) 2022
 *
 */
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


 /**
  * @brief Teste une entrée utilisateur de format chaîne de caractères attendu.
  *
  * @pre dest doit être une adresse allouée de taille BUFFER_SIZE
  *
  * @param dest adresse où sera stocké l'entrée utilisateur
  * @return true si l'entrée utilisateur a été lu entièrement (dans la limite de
  * BUFFERSIZE)
  *
  * @sa [code source](https://stackoverflow.com/questions/7831755/what-is-the-simplest-way-of-getting-user-input-in-c)
  */
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

/**
 * @brief Teste une entrée utilisateur de format entier attendu.
 *
 * @pre i doit être une adresse d'entier allouée
 *
 * @details
 * fgets et sscanf permet de renvoie true si l'entrée utilisateur rentre
 * dans line et qu'elle respecte bien le format attendu.
 *
 * @param i adresse où sera stocké l'entrée utilisateur
 * @return true si l'entrée utilisateur a été lu en entier (dans la limite de
 * BUFFERSIZE)
 */
bool getIntInput(int* i) {
    char line[BUFFER_SIZE];
    return fgets(line, sizeof(line), stdin) && sscanf(line, "%d", i);
}

/**
 * @brief Lit une entrée utilisateur de format chaîne de caractères.
 *
 * @details
 * L'affichage sera présenté comme suit :
 * @code
 * {Message}
 *
 * {Description} : _
 * @endcode
 *
 * @param message Message à afficher à l'utilisateur avant de présenter
 * l'entrée
 * @param description Donnée abstrait attendu à l'utilisateur, affiché
 * sur la même ligne que l'entrée
 * @param value adresse où sera stocké l'entrée utilisateur
 * @return true
 * @return false
 */
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

/**
 * @brief Lit le choix entier de l'utilisateur parmi une liste à afficher.
 * Le choix est défini entre 0 (Quitter) et maxValue.
 *
 * @param message Liste de choix affichée à l'utilisateur.
 * @param maxValue Valeur maximale du choix utilisateur (inclus).
 * @return int représentant le choix de l'utilisateur
 */
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

/**
 * @brief Lit l'entrée d'un entier de l'utilisateur parmi une intervalle
 * défini par minValue et maxValue.
 *
 * @param message Message à afficher avant de prendre l'entrée.
 * @param minValue Valeur minimale du choix (inclus).
 * @param maxValue Valeur maximale du choix (inclus).
 * @return int parmi l'intervalle d'entier.
 */
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

/**
 * @brief demande une réponse physique de l'utilisateur
 * par un appuie sur la touche <ENTREE>
 *
 * @return 0
 */
int getAnyInput() {
    char* s;
    println("Appuyer sur <ENTREE> pour continuer.");
    getCharInput(s);
    return 0;
}

/**
 * @brief Renvoie au gestionnaire d'évènement une demande de revenir en arrière,
 * marquée par l'entier -1
 *
 * @return -1
 */
int getCancelInput() {
    println("Opération annulée.");
    return -1;
}

/**
 * @brief Présente une erreur à l'utilisateur le demandant de réessayer.
 * Puis lit le choix de l'utilisateur.
 *
 * @param description valeur qui présente l'erreur
 * @return 0 si l'utilisateur veut quitter l'opération, 1 si il veut réessayer.
 */
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