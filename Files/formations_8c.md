# Référence du fichier src/model/formations.c

Code source de la structure de données Formations.  [Plus de détails...](#description-détaillée)

## Structures de données

|                | Nom           |
| -------------- | -------------- |
| struct | **[s_formations](/Classes/structs__formations.md)** <br>Structure représentant un tableau de Formation.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Formations](/Files/formations_8h.md#typedef-formations) | **[formations](/Files/formations_8c.md#fonction-formations)**(int taille_max)<br>Construit un nouvel objet Formations avec un tableau de Formation.  |
| [Formations](/Files/formations_8h.md#typedef-formations) | **[formationsParser](/Files/formations_8c.md#fonction-formationsparser)**([json_t](/Classes/structjson__t.md) * json_formations)<br>Construit un nouvel objet Formation à partir de sa représentation en objet JSON.  |
| [Formation](/Files/formation_8h.md#typedef-formation) | **[getFormationByIndice](/Files/formations_8c.md#fonction-getformationbyindice)**([Formations](/Files/formations_8h.md#typedef-formations) fs, int indice)<br>Accesseur de l'objet Formation à partir de son Indice dans Formations.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonFormations](/Files/formations_8c.md#fonction-getjsonformations)**([Formations](/Files/formations_8h.md#typedef-formations) fs)<br>Accesseur de la représentation en objet JSON de Formations.  |
| int | **[sizeFormations](/Files/formations_8c.md#fonction-sizeformations)**([Formations](/Files/formations_8h.md#typedef-formations) fs)<br>Accesseur de la taille de Formations.  |
| bool | **[appartientFormations](/Files/formations_8c.md#fonction-appartientformations)**([Formations](/Files/formations_8h.md#typedef-formations) fs, char * nom) |
| [Formations](/Files/formations_8h.md#typedef-formations) | **[ajouterFs](/Files/formations_8c.md#fonction-ajouterfs)**([Formations](/Files/formations_8h.md#typedef-formations) fs, [Formation](/Files/formation_8h.md#typedef-formation) f)<br>Ajoute une référence de l'objet Formation à Formations.  |
| void | **[afficherFormations](/Files/formations_8c.md#fonction-afficherformations)**([Formations](/Files/formations_8h.md#typedef-formations) fs) |
| void | **[afficherFormationsN](/Files/formations_8c.md#fonction-afficherformationsn)**([Formations](/Files/formations_8h.md#typedef-formations) fs, bool isOrdered)<br>Imprime le nom de toute Formation de Formations sur stdout, précédé de son indice dans la liste si ordonné, d'un tiret sinon et suivi d'un retour à la ligne.  |

## Description détaillée

Code source de la structure de données Formations.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des fonctions

### fonction formations()

```c
Formations formations(
    int taille_max
)
```

Construit un nouvel objet Formations avec un tableau de Formation.

Constructeur par défaut de l'objet Formations.

### fonction formationsParser()

```c
Formations formationsParser(
    json_t * json_formations
)
```

Construit un nouvel objet Formation à partir de sa représentation en objet JSON.

Construit l'objet Formations en manipulant l'API Jansson. Pour cela, à partir d'une recherche par clé (s'il existe) de "formations", nous pouvons obtenir un tableau de Formation. Ensuite, on itère le tableau pour pouvoir ajouter chaque Formation à l'objet Formations, en faisant chaque fois appel à son constructeur à partir de la valeur renvoyée par l'API.

[json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string) , [json_array_foreach](https://jansson.readthedocs.pio/en/latest/apiref.html#c.json_array_foreach)

### fonction getFormationByIndice()

```c
Formation getFormationByIndice(
    Formations fs,
    int indice
)
```

Accesseur de l'objet Formation à partir de son Indice dans Formations.

**Paramètres**:

* **fs** Référence de Formations.
* **indice** Indice à laquelle se trouve la Formation recherchée.

**Renvoie**: Formation à l'indice indiquée

!> **Précondition**: Indice doit être positif et strictement inférieur à la taille de la liste. Formations ne doit pas être vide.

### fonction getJsonFormations()

```c
json_t * getJsonFormations(
    Formations fs
)
```

Accesseur de la représentation en objet JSON de Formations.

Renvoie la représentation objet JSON de Formations en utilisant l'API Jansson. Pour cela, on construit un nouvel tableau JSON et en itérant la liste des Formations, on ajoute à ce tableau l'attribut Nom de chaque Formation.

[json_string](https://jansson.readthedocs.io/en/latest/apiref.html#string) , [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) , [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)

### fonction sizeFormations()

```c
int sizeFormations(
    Formations fs
)
```

Accesseur de la taille de Formations.

**Paramètres**:

* **fs** Référence de Formations.

**Renvoie**: Taille de Formations de type int.

### fonction appartientFormations()

```c
bool appartientFormations(
    Formations fs,
    char * nom
)
```

Vérifie par itération si un Nom de Formation de Formations est égale au Nom de Formation passé en paramètre.

### fonction ajouterFs()

```c
Formations ajouterFs(
    Formations fs,
    Formation f
)
```

Ajoute une référence de l'objet Formation à Formations.

Ajoute Formations à la tête de la liste des Formations si Formation n'en fait pas encore parti. Si non, on renvoie une erreur.

[appartientFormations](/Files/formations_8c.md#fonction-appartientformations)

### fonction afficherFormations()

```c
void afficherFormations(
    Formations fs
)
```

Imprime tout Formation de Formations sur stdout, suivi d'un retour à la ligne.

Itère la liste des Formations pour pouvoir afficher chaque Formation à partir de sa représentation externe sur stdout. L'impression suit alors le format :

```txt
{Formation}

{Formation}

...
```

[afficheFormation](/Files/formation_8c.md#fonction-afficheformation)

### fonction afficherFormationsN()

```c
void afficherFormationsN(
    Formations fs,
    bool isOrdered
)
```

Imprime le nom de toute Formation de Formations sur stdout, précédé de son indice dans la liste si ordonné, d'un tiret sinon et suivi d'un retour à la ligne.

Itère la liste des Formations pour pouvoir afficher le Nom de chaque Formation sur stdout, précédé de son indice dans la liste si l'ordre est paramétré à True, ou d'un tiret sinon. L'impression suit alors le format :

```txt
- {Nom de Formation}
- {Nom de Formation}
...
```

ou :

```txt
1) {Nom de Formation}
2) {Nom de Formation}
...
```

[getFormationN](/Files/formation_8c.md#fonction-getformationn)

## Code source

```c

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "formations.h"

#ifdef DEBUG
#include "tests.h"
#endif

 /************************************************************\
 *                  Structure de Formations                   *
 \************************************************************/

struct s_formations {
    Formation* formations;
    int taille;
    int capacite;
};


/************************************************************\
*                Constructeurs de Formations                 *
\************************************************************/

Formations formations(int taille_max) {
    Formations fs = (Formations)malloc(sizeof(struct s_formations));
    fs->formations = (Formation*)malloc(taille_max * sizeof(Formation));
    fs->taille = 0;
    fs->capacite = taille_max;
    return fs;
}

Formations formationsParser(json_t* json_formations) {
    assert(json_is_array(json_formations));
    Formations fs = formations((int)json_array_size(json_formations));
    size_t index;
    json_t* value;
    json_array_foreach(json_formations, index, value) {
        ajouterFs(fs, formationParser(value));
    }
    return fs;
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

Formation getFormationByIndice(Formations fs, int indice) {
    assert(0 <= indice && indice < sizeFormations(fs));
    return fs->formations[indice];
}

json_t* getJsonFormations(Formations fs) {
    json_t* root = json_array();
    for (int i = 0; i < sizeFormations(fs); i++) {
        json_array_append(root, getJsonFormation(fs->formations[i]));
    }
    return root;
}

int sizeFormations(Formations fs) {
    return fs->taille;
}

bool appartientFormations(Formations fs, char* nom) {
    bool isEqual = false;
    for (int i = 0; i < sizeFormations(fs) && !isEqual; i++) {
        isEqual = strcmp(getFormationN(fs->formations[i]), nom) == 0;
    }
    return isEqual;
}

Formations ajouterFs(Formations fs, Formation f) {
    assert(!appartientFormations(fs, getFormationN(f)));
    assert(fs->taille + 1 <= fs->capacite);
    fs->formations[sizeFormations(fs)] = f;
    fs->taille++;
    return fs;
}

/************************************************************\
*                 Représentations externes                   *
\************************************************************/

void afficherFormations(Formations fs) {
    for (int i = 0; i < sizeFormations(fs); i++) {
        afficheFormation(fs->formations[i], false);
    }
}

void afficherFormationsN(Formations fs, bool isOrdered) {
    for (int i = 0; i < sizeFormations(fs); i++) {
        if (isOrdered) {
            printf("%d) %s\n", i + 1, getFormationN(fs->formations[i]));
        }
        else {
            printf("- %s\n", getFormationN(fs->formations[i]));
        }
    }
}

/************************************************************\
*               Tests unitaires de Formations                *
\************************************************************/

#ifdef TEST

int main() {

    // init

    char* f1_nom = "CUPGE";
    char* f2_nom = "L2 Informatique";

    Formation f1 = formation(f1_nom);
    Formation f2 = formation(f2_nom);

    // testing

    Formations F = formations(2);

    info(ajouterFs(F, f1));
    test(appartientFormations(F, getFormationN(f1)));
    test(getFormationByIndice(F, 0) == f1);
    // info(ajouterFs(F, f1)); // devrait produire une erreur

    info(ajouterFs(F, f2));
    test(getFormationByIndice(F, 1) == f2);
    test(getFormationByIndice(F, 0) == f1);

    info(afficherFormations(F));
    return 0;
}

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
