# Référence du fichier src/model/salles.c

Code source de la structure de données Salles.  [Plus de détails...](#description-détaillée)

## Structures de données

|                | Nom           |
| -------------- | -------------- |
| struct | **[s_element_ss](/Classes/structs__element__ss.md)** <br>Structure représentant un élément de la liste chaînée Salles.  |
| struct | **[s_salles](/Classes/structs__salles.md)** <br>Structure représentant une liste chaînée de Salle.  |

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_element_ss](/Classes/structs__element__ss.md) * | **[ElementSs](/Files/salles_8c.md#typedef-elementss)**  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Salles](/Files/salles_8h.md#typedef-salles) | **[salles](/Files/salles_8c.md#fonction-salles)**()<br>Construit un nouvel objet Salles.  |
| [ElementSs](/Classes/structs__element__ss.md) | **[elementSs](/Files/salles_8c.md#fonction-elementss)**([Salle](/Files/salle_8h.md#typedef-salle) s) |
| [Salles](/Files/salles_8h.md#typedef-salles) | **[sallesParser](/Files/salles_8c.md#fonction-sallesparser)**([json_t](/Classes/structjson__t.md) * json_salles)<br>Construit un nouvel objet Salles à partir de sa représentation en objet JSON.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[getSalleByNom](/Files/salles_8c.md#fonction-getsallebynom)**([Salles](/Files/salles_8h.md#typedef-salles) ss, char * nom)<br>Accesseur de l'objet Salle à partir de son Nom parmi la liste des Salles.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[getSalleByIndice](/Files/salles_8c.md#fonction-getsallebyindice)**([Salles](/Files/salles_8h.md#typedef-salles) ss, int indice)<br>Accesseur de l'objet Salle à partir de son Indice dans la liste des Salles.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonSalles](/Files/salles_8c.md#fonction-getjsonsalles)**([Salles](/Files/salles_8h.md#typedef-salles) ss)<br>Accesseur de la représentation en objet JSON de Salles.  |
| int | **[sizeSalles](/Files/salles_8c.md#fonction-sizesalles)**([Salles](/Files/salles_8h.md#typedef-salles) ss)<br>Accesseur de la taille de la liste des Salles.  |
| bool | **[appartientSalles](/Files/salles_8c.md#fonction-appartientsalles)**([Salles](/Files/salles_8h.md#typedef-salles) ss, [Salle](/Files/salle_8h.md#typedef-salle) s)<br>vérifie si Salles possède une référence de l'objet Salle avec le même nom.  |
| [Salles](/Files/salles_8h.md#typedef-salles) | **[ajouterSs](/Files/salles_8c.md#fonction-ajouterss)**([Salles](/Files/salles_8h.md#typedef-salles) ss, [Salle](/Files/salle_8h.md#typedef-salle) s)<br>Ajoute une référence de l'objet Salle à la liste des Salles.  |
| void | **[afficherSalles](/Files/salles_8c.md#fonction-affichersalles)**([Salles](/Files/salles_8h.md#typedef-salles) ss)<br>Imprime toute Salle de la liste des Salles sur stdout, suivi d'un retour à la ligne.  |
| void | **[afficherSallesN](/Files/salles_8c.md#fonction-affichersallesn)**([Salles](/Files/salles_8h.md#typedef-salles) ss, bool isOrdered)<br>Imprime le nom de toute Salle de la liste des Salles sur stdout, précédé de son indice dans la liste si ordonné, d'un tiret sinon et suivi d'un retour à la ligne.  |
| char * | **[toStringSalles](/Files/salles_8c.md#fonction-tostringsalles)**([Salles](/Files/salles_8h.md#typedef-salles) ss)<br>Accesseur de la représentation en chaîne de caractère JSON de Salles.  |

## Description détaillée

Code source de la structure de données Salles.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef ElementSs

```c
typedef struct s_element_ss* ElementSs;
```

## Documentation des fonctions

### fonction salles()

```c
Salles salles()
```

Construit un nouvel objet Salles.

Constructeur par défaut de l'objet Salles.

### fonction elementSs()

```c
ElementSs elementSs(
    Salle s
)
```

Constructeur par défaut de l'objet ElementSs, élément de la liste Salles, stockant l'objet Salle passé en paramètre.

### fonction sallesParser()

```c
Salles sallesParser(
    json_t * json_salles
)
```

Construit un nouvel objet Salles à partir de sa représentation en objet JSON.

Construit l'objet Salles en manipulant l'API Jansson. Pour cela, à partir d'une recherche par clé (s'il existe) de "salles", nous pouvons obtenir un tableau de Salle. Ensuite, on itère le tableau pour pouvoir ajouter chaque Salle à l'objet Salles, en faisant chaque fois appel à son constructeur à partir de la valeur renvoyée par l'API.

[salleParser](/Files/salle_8c.md#fonction-salleparser) , [json_array_foreach](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_foreach)

### fonction getSalleByNom()

```c
Salle getSalleByNom(
    Salles ss,
    char * nom
)
```

Accesseur de l'objet Salle à partir de son Nom parmi la liste des Salles.

Itère parmi la liste des Salles jusqu'à trouver une Salle dont l'attribut Nom correspond au paramètre. Sinon, renvoie une erreur.

### fonction getSalleByIndice()

```c
Salle getSalleByIndice(
    Salles ss,
    int indice
)
```

Accesseur de l'objet Salle à partir de son Indice dans la liste des Salles.

Itère parmi la liste des Salles Indice fois puis renvoie la référence de Salle stockée par l'élément courant.

### fonction getJsonSalles()

```c
json_t * getJsonSalles(
    Salles ss
)
```

Accesseur de la représentation en objet JSON de Salles.

Renvoie la représentation objet JSON de Salles en utilisant l'API Jansson. Pour cela, on construit un nouvel objet JSON et on y attache la clé "salles" qui est un tableau. En itérant ensuite la liste des Salles, on ajoute à ce tableau la représentation objet JSON de chaque Salle.

[getJsonSalle](/Files/salle_8c.md#fonction-getjsonsalle) , [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) , [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)

### fonction sizeSalles()

```c
int sizeSalles(
    Salles ss
)
```

Accesseur de la taille de la liste des Salles.

**Paramètres**:

* **ss** Référence de Salles.

**Renvoie**: Taille de la liste des Salles de type int.

### fonction appartientSalles()

```c
bool appartientSalles(
    Salles ss,
    Salle s
)
```

vérifie si Salles possède une référence de l'objet Salle avec le même nom.

Vérifie par itération si un élément Salle de la liste des Salles est égale à l'objet Salle passé en paramètre. Deux Salle sont considérés égaux s'ils ont le même nom.

### fonction ajouterSs()

```c
Salles ajouterSs(
    Salles ss,
    Salle s
)
```

Ajoute une référence de l'objet Salle à la liste des Salles.

Ajoute Salle à la tête de la liste des Salles si Salle n'en fait pas encore parti. Si non, on renvoie une erreur.

[appartientSalles](/Files/salles_8c.md#fonction-appartientsalles)

### fonction afficherSalles()

```c
void afficherSalles(
    Salles ss
)
```

Imprime toute Salle de la liste des Salles sur stdout, suivi d'un retour à la ligne.

Itère la liste des Salles pour pouvoir afficher chaque Salle à partir de sa représentation externe sur stdout. L'impression suit alors le format :

```txt
{Salle}

{Salle}

...
```

[afficheSalle](/Files/salle_8c.md#fonction-affichesalle)

### fonction afficherSallesN()

```c
void afficherSallesN(
    Salles ss,
    bool isOrdered
)
```

Imprime le nom de toute Salle de la liste des Salles sur stdout, précédé de son indice dans la liste si ordonné, d'un tiret sinon et suivi d'un retour à la ligne.

**Paramètres**:

* **ss** Salles à afficher.
* **isOrdered** indique si la liste doit être ordonnée par son indice.

### fonction toStringSalles()

```c
char * toStringSalles(
    Salles ss
)
```

Accesseur de la représentation en chaîne de caractère JSON de Salles.

Renvoie la représentation JSON en chaîne de caractères de Salles en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "salles.h"

#ifdef DEBUG
#include "tests.h"
#endif


 /************************************************************\
 *                    Structures de Salles                    *
 \************************************************************/

typedef struct s_element_ss {
    Salle s;
    struct s_element_ss* suivant;
}*ElementSs;

struct s_salles {
    ElementSs sentinelle;
    int taille;
};


/************************************************************\
*                 Constructeurs de Salles                    *
\************************************************************/

Salles salles() {
    Salles ss = (Salles)malloc(sizeof(struct s_salles));
    ss->sentinelle = (ElementSs)malloc(sizeof(struct s_element_ss));
    ss->sentinelle->suivant = ss->sentinelle;
    ss->taille = 0;
    return ss;
}

ElementSs elementSs(Salle s) {
    ElementSs e_ss = (ElementSs)malloc(sizeof(struct s_element_ss));
    e_ss->s = s;
    return e_ss;
}

Salles sallesParser(json_t* json_salles) {
    assert(json_is_array(json_salles));
    Salles ss = salles();
    size_t index;
    json_t* value;
    json_array_foreach(json_salles, index, value) {
        ajouterSs(ss, salleParser(value));
    }
    return ss;
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

Salle getSalleByNom(Salles ss, char* nom) {
    bool isFound = false;
    ElementSs courant = ss->sentinelle;
    for (int i = 0;i < sizeSalles(ss) && !isFound; i++) {
        courant = courant->suivant;
        isFound = strcmp(nom, getSalleN(courant->s)) == 0;
    }
    assert(isFound);
    return courant->s;
}

Salle getSalleByIndice(Salles ss, int indice) {
    assert(0 <= indice && indice < sizeSalles(ss));
    ElementSs courant = ss->sentinelle->suivant;
    for (int i = 0;i < indice;i++) {
        courant = courant->suivant;
    }
    return courant->s;
}

json_t* getJsonSalles(Salles ss) {
    json_t* root = json_array();
    ElementSs courant = ss->sentinelle->suivant;
    for (int i = 0; i < sizeSalles(ss); i++) {
        json_array_append(root, getJsonSalle(courant->s));
        courant = courant->suivant;
    }
    return root;
}

int sizeSalles(Salles ss) {
    return ss->taille;
}

bool appartientSalles(Salles ss, Salle s) {
    bool isEqual = false;
    ElementSs courant = ss->sentinelle->suivant;
    for (int i = 0; i < sizeSalles(ss) && !isEqual; i++) {
        isEqual = strcmp(getSalleN(courant->s), getSalleN(s)) == 0;
        courant = courant->suivant;
    }
    return isEqual;
}

Salles ajouterSs(Salles ss, Salle s) {
    assert(!appartientSalles(ss, s));
    ElementSs e_ss = elementSs(s);
    e_ss->suivant = ss->sentinelle->suivant;
    ss->sentinelle->suivant = e_ss;
    ss->taille++;
    return ss;
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

void afficherSalles(Salles ss) {
    ElementSs courant = ss->sentinelle->suivant;
    for (int i = 0;i < sizeSalles(ss);i++) {
        afficheSalle(courant->s);
        courant = courant->suivant;
    }
}

void afficherSallesN(Salles ss, bool isOrdered) {
    ElementSs courant = ss->sentinelle->suivant;
    for (int i = 0;i < sizeSalles(ss);i++) {
        if (isOrdered) {
            printf("%d) %s\n", i + 1, getSalleN(courant->s));
        }
        else {
            printf("- %s\n", getSalleN(courant->s));
        }
        courant = courant->suivant;
    }
}

char* toStringSalles(Salles ss) {
    json_t* json_salles = getJsonSalles(ss);
    char* str = json_dumps(json_salles, 0);
#ifdef DEBUG
    puts(str);
#endif
    // deallocation json object memory
    json_decref(json_salles);
    return str;
}


/************************************************************\
*                 Tests unitaires de Salles                  *
\************************************************************/

#ifdef TEST

int main() {

    // init

    char* s1_nom = "118";
    char* s2_nom = "103";

    Salle s1 = salleCopie(s1_nom);
    Salle s2 = salleCopie(s2_nom);

    // testing

    Salles S = salles();

    // info(getSalleByNom(S, s1_nom)); // devrait produire une erreur

    info(ajouterSs(S, s1));
    test(appartientSalles(S, s1));
    test(getSalleByNom(S, s1_nom) == s1);
    // info(ajouterSs(S, s1)); // devrait produire une erreur

    info(ajouterSs(S, s2));
    test(getSalleByNom(S, s2_nom) == s2);
    test(getSalleByNom(S, s1_nom) == s1);

    info(afficherSalles(S));

    info(toStringSalles(sallesParser(getJsonSalles(S))));

    return 0;
}

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0

[Voir la documentation Doxygen originale](https://rmihaja.github.io/BAC/doxygen/index.html)
