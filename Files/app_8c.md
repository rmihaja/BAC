# Référence du fichier src/app.c

Code du programme principal.  [Plus de détails...](#description-détaillée)

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| int | **[main](/Files/app_8c.md#fonction-main)**()<br>programme principal  |

## Description détaillée

Code du programme principal.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des fonctions

### fonction main()

```c
int main()
```

programme principal

**Renvoie**: int

## Code source

```c

#include "controle.h"

int main() {
  Controle C = controle("bin/data/data.json");
  run(C);
  return 0;
}
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
