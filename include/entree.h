/**
 * @file entree.h
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief En-tête des fonctions d'entrées
 *
 * @note
 * Dû à la technicité des fonctions présentées ici,
 * la documentation se trouvera exclusivement dans le code source.
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __ENTREE_H__
#define __ENTREE_H__

 /**
  * @brief permet d'imprimer une chaîne suivi deux retours à la ligne.
  *
  */
#define println(...)  printf( __VA_ARGS__ "\n\n" )

  /**
   * @brief permet d'imprimer une variable selon un format, suivi de
   * deux retours à la ligne.
   *
  */
#define display(format, ...)  printf(format "\n\n", __VA_ARGS__)

  /**
  * @brief nombre de caractère maximale que le module peut lire par
  * entrée.
  *
  */
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