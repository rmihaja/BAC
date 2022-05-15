# Référence du fichier src/model/horaire.c

Code source de la structure de données Horaire.  [Plus de détails...](#description-détaillée)

## Structures de données

|                | Nom           |
| -------------- | -------------- |
| struct | **[s_horaire](/Classes/structs__horaire.md)** <br>Structure représentant un objet Horaire.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Horaire](/Files/horaire_8h.md#typedef-horaire) | **[horaire](/Files/horaire_8c.md#fonction-horaire)**(int debut, int fin)<br>construit un nouvel objet Horaire avec un Début et une Fin.  |
| [Horaire](/Files/horaire_8h.md#typedef-horaire) | **[horaireParser](/Files/horaire_8c.md#fonction-horaireparser)**([json_t](/Classes/structjson__t.md) * json_horaire)<br>construit un nouvel objet Horaire à partir de sa représentation objet JSON.  |
| int | **[getDebut](/Files/horaire_8c.md#fonction-getdebut)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Accesseur de l'objet Debut de Horaire.  |
| int | **[getFin](/Files/horaire_8c.md#fonction-getfin)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Accesseur de l'objet Fin de Horaire.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonHoraire](/Files/horaire_8c.md#fonction-getjsonhoraire)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Accesseur de la représentation en objet JSON de Horaire.  |
| int | **[duree](/Files/horaire_8c.md#fonction-duree)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Calcule la durée d'une horaire.  |
| [Horaire](/Files/horaire_8h.md#typedef-horaire) | **[setDebut](/Files/horaire_8c.md#fonction-setdebut)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h, int debut)<br>Définie l'objet Debut de Horaire.  |
| [Horaire](/Files/horaire_8h.md#typedef-horaire) | **[setFin](/Files/horaire_8c.md#fonction-setfin)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h, int fin)<br>Définie l'objet Fin de Horaire.  |
| bool | **[equalsHoraire](/Files/horaire_8c.md#fonction-equalshoraire)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h1, [Horaire](/Files/horaire_8h.md#typedef-horaire) h2)<br>compare deux Horaire.  |
| void | **[afficheHoraire](/Files/horaire_8c.md#fonction-affichehoraire)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Imprime les attributs de Horaire sur stdout, suivi d'un retour à la ligne.  |
| char * | **[toStringHoraire](/Files/horaire_8c.md#fonction-tostringhoraire)**([Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Accesseur de la représentation en chaîne de caractère JSON de Horaire.  |

## Description détaillée

Code source de la structure de données Horaire.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des fonctions

### fonction horaire()

```c
Horaire horaire(
    int debut,
    int fin
)
```

construit un nouvel objet Horaire avec un Début et une Fin.

Constructeur par défaut de l'objet Horaire.

### fonction horaireParser()

```c
Horaire horaireParser(
    json_t * json_horaire
)
```

construit un nouvel objet Horaire à partir de sa représentation objet JSON.

Construit l'objet Horaire en manipulant l'API Jansson. Pour cela, à partir d'une recherche par clé (s'il existe), nous pouvons accéder aux attributs "debut" et "fin" de Horaire, que nous construisons ensuite à l'aide du constructeur par défaut.

[json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) , [json_object_get](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_get) , [json_integer_value](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_integer_value)

### fonction getDebut()

```c
int getDebut(
    Horaire h
)
```

Accesseur de l'objet Debut de Horaire.

**Paramètres**:

* **h** Référence de Horaire.

**Renvoie**: Valeur de Debut de type int.

### fonction getFin()

```c
int getFin(
    Horaire h
)
```

Accesseur de l'objet Fin de Horaire.

**Paramètres**:

* **h** Référence de Horaire.

**Renvoie**: Valeur de Fin de type int.

### fonction getJsonHoraire()

```c
json_t * getJsonHoraire(
    Horaire h
)
```

Accesseur de la représentation en objet JSON de Horaire.

Renvoie la représentation objet JSON de Horaire en utilisant l'API Jansson. Pour cela, on construit un nouvel objet JSON pour ensuite pouvoir y attacher les attributs clé-valeurs de Horaire, défini par "debut" et "fin".

[json_object](https://jansson.readthedocs.io/en/latest/apiref.html#object) , [json_object_set_new](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_object_set_new)

### fonction duree()

```c
int duree(
    Horaire h
)
```

Calcule la durée d'une horaire.

Calcule $ \vert Fin - Debut \vert $. Mais comme $ Fin \gt Debut $ par construction, on peut alors tout simplement calculer $ Fin - Debut $

### fonction setDebut()

```c
Horaire setDebut(
    Horaire h,
    int debut
)
```

Définie l'objet Debut de Horaire.

**Paramètres**:

* **h** Référence de Horaire à modifier.
* **debut** Valeur de Debut de type int.

**Renvoie**: Horaire avec la nouvelle valeur de Debut.

### fonction setFin()

```c
Horaire setFin(
    Horaire h,
    int fin
)
```

Définie l'objet Fin de Horaire.

**Paramètres**:

* **h** Référence de Horaire à modifier.
* **fin** Valeur de Fin de type int.

**Renvoie**: Horaire avec la nouvelle valeur de Fin.

### fonction equalsHoraire()

```c
bool equalsHoraire(
    Horaire h1,
    Horaire h2
)
```

compare deux Horaire.

**Paramètres**:

* **h1** Horaire 1 à comparer.
* **h2** Horaire 2 à comparer.

**Renvoie**:

* true si Horaire 1 et Horaire 2 possèdent les mêmes attributs Debut et Fin.
* false si un ou plusieurs attributs de Horaire 1 et Horaire 2 diffèrent.

### fonction afficheHoraire()

```c
void afficheHoraire(
    Horaire h
)
```

Imprime les attributs de Horaire sur stdout, suivi d'un retour à la ligne.

Imprime les attributs de l'objet Enseignant selon le format :

```txt
{Debut}h00 à {Fin}h00
```

### fonction toStringHoraire()

```c
char * toStringHoraire(
    Horaire h
)
```

Accesseur de la représentation en chaîne de caractère JSON de Horaire.

Renvoie la représentation JSON en chaîne de caractères de Horaire en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "horaire.h"

#ifdef DEBUG
#include "tests.h"
#endif

struct s_horaire {
    int debut;
    int fin;
};


/************************************************************\
*                  Constructeurs de Horaire                  *
\************************************************************/

Horaire horaire(int debut, int fin) {
    assert(8 <= debut && debut <= 19 && 9 <= fin && fin <= 20 && debut != fin);
    Horaire h = (Horaire)malloc(sizeof(struct s_horaire));
    h->debut = debut;
    h->fin = fin;
    return h;
}

Horaire horaireParser(json_t* json_horaire) {
    json_t* debut = json_object_get(json_horaire, "debut");
    json_t* fin = json_object_get(json_horaire, "fin");
    assert(json_is_integer(debut) && json_is_integer(fin));
    return horaire((int)json_integer_value(debut), (int)json_integer_value(fin));
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

int getDebut(Horaire h) {
    return h->debut;
}

int getFin(Horaire h) {
    return h->fin;
}

json_t* getJsonHoraire(Horaire h) {
    json_t* root = json_object();
    json_object_set_new(root, "debut", json_integer(getDebut(h)));
    json_object_set_new(root, "fin", json_integer(getFin(h)));
    return root;
}

int duree(Horaire h) {
    return (h->fin - h->debut);
}

Horaire setDebut(Horaire h, int debut) {
    h->debut = debut;
    return h;
}

Horaire setFin(Horaire h, int fin) {
    h->fin = fin;
    return h;
}

bool equalsHoraire(Horaire h1, Horaire h2) {
    return h1->debut == h2->debut
        && h1->fin == h2->fin;
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

void afficheHoraire(Horaire h) {
    printf("%dh00 à %dh00\n", getDebut(h), getFin(h));
}

char* toStringHoraire(Horaire h) {
    json_t* json_horaire = getJsonHoraire(h);
    char* str = json_dumps(json_horaire, 0);
#ifdef DEBUG
    puts(str);
#endif
    // deallocate json object memory
    json_decref(json_horaire);
    return str;
}


/************************************************************\
*                Tests unitaires de Horaire                  *
\************************************************************/

#ifdef TEST
#include <string.h>

int main() {

    // init

    int h1_debut = 8;
    int h2_debut = 15;
    int h1_fin = 10;
    int h2_fin = 18;

    // testing

    Horaire h = horaire(h1_debut, h1_fin);

    test(duree(h) > 0);

    test(getDebut(h) == h1_debut);
    test(getFin(h) == h1_fin);

    info(setDebut(h, h2_debut));
    info(setFin(h, h2_fin));

    test(getDebut(h) == h2_debut);
    test(getFin(h) == h2_fin);

    test(duree(h) == h2_fin - h2_debut);

    test(equalsHoraire(h, h));
    test(!equalsHoraire(h, horaire(h1_debut, h1_fin)));

    info(afficheHoraire(h));

    test(strcmp(toStringHoraire(h), toStringHoraire(horaireParser(getJsonHoraire(h)))) == 0);

    return 0;
}

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0

[Voir la documentation Doxygen originale](https://rmihaja.github.io/BAC/doxygen/index.html)
