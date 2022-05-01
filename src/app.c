/**
 * @file app.c
 * @author Mihaja RAZAFIMAHEFA & Ambre ROUZADE
 * @brief Code du programme principal
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "controle.h"

 /**
  * @brief programme principal
  *
  * @return int
  */
int main() {
  Controle C = controle("bin/data/data.json");
  run(C);
  return 0;
}