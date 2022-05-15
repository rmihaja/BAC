# Référence du fichier src/model/salle.c

Code source de la structure de données Salle.  [Plus de détails...](#description-détaillée)

## Structures de données

|                | Nom           |
| -------------- | -------------- |
| struct | **[s_salle](/Classes/structs__salle.md)** <br>Structure représentant un objet Salle.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[salle](/Files/salle_8c.md#fonction-salle)**()<br>Construit un nouvel objet Salle avec un Nom vide et un tableau de Creneau vide.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[salleCopie](/Files/salle_8c.md#fonction-sallecopie)**(char * nom)<br>Construit un nouvel objet Salle avec un Nom et un tableau de Creneau vide.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[salleParser](/Files/salle_8c.md#fonction-salleparser)**([json_t](/Classes/structjson__t.md) * json_salle)<br>Construit un nouvel objet Salle à partir de sa représentation en objet JSON.  |
| char * | **[getSalleN](/Files/salle_8c.md#fonction-getsallen)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Accesseur de l'objet Nom de Salle.  |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) * | **[getSalleC](/Files/salle_8c.md#fonction-getsallec)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Accesseur du tableau de Creneau de Salle.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonSalle](/Files/salle_8c.md#fonction-getjsonsalle)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Accesseur de la représentation en objet JSON de Salle.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[setSalleN](/Files/salle_8c.md#fonction-setsallen)**([Salle](/Files/salle_8h.md#typedef-salle) s, char * nom)<br>Définie l'objet Nom de Salle.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[ajouterSalleC](/Files/salle_8c.md#fonction-ajoutersallec)**([Salle](/Files/salle_8h.md#typedef-salle) s, [Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Ajoute une référence de l'objet Creneau au tableau de Creneau de Salle.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[supprimerSalleH](/Files/salle_8c.md#fonction-supprimersalleh)**([Salle](/Files/salle_8h.md#typedef-salle) s, [Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Supprime tout Creneau réservé dans l'intervalle de Horaire.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[modifierSalleHC](/Files/salle_8c.md#fonction-modifiersallehc)**([Salle](/Files/salle_8h.md#typedef-salle) s, [Horaire](/Files/horaire_8h.md#typedef-horaire) horaire_modifie, [Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Modifie le Creneau à l'Horaire horaire_modifié pour le remplacer par un nouveau Creneau.  |
| bool | **[isFreeSalle](/Files/salle_8c.md#fonction-isfreesalle)**([Salle](/Files/salle_8h.md#typedef-salle) s, [Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Vérifie si Salle ne contient aucun créneau réservé dans l'intervalle de Horaire.  |
| bool | **[isEmptySalle](/Files/salle_8c.md#fonction-isemptysalle)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Vérifie si Salle ne contient aucun créneau réservé.  |
| void | **[afficheSalle](/Files/salle_8c.md#fonction-affichesalle)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Imprime le nom de Salle ainsi que son tableau de Creneau sur stdout, suivi d'un retour à la ligne.  |
| char * | **[toStringSalle](/Files/salle_8c.md#fonction-tostringsalle)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Accesseur de la représentation en chaîne de caractère JSON de Salle.  |

## Description détaillée

Code source de la structure de données Salle.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des fonctions

### fonction salle()

```c
Salle salle()
```

Construit un nouvel objet Salle avec un Nom vide et un tableau de Creneau vide.

Constructeur par défaut de l'objet Salle.

### fonction salleCopie()

```c
Salle salleCopie(
    char * nom
)
```

Construit un nouvel objet Salle avec un Nom et un tableau de Creneau vide.

**Paramètres**:

* **nom** Nom de Salle de type char*.

**Renvoie**: Nouvelle instance allouée de Salle.

### fonction salleParser()

```c
Salle salleParser(
    json_t * json_salle
)
```

Construit un nouvel objet Salle à partir de sa représentation en objet JSON.

Construit l'objet Salle en manipulant l'API Jansson. Pour cela, à partir d'une recherche par clé (s'il existe), nous pouvons accéder à l'attribut "nom" de Salle que nous construisons à l'aide du constructeur par défaut. Nous accédons ensuite à la clé "creneaux" qui est un tableau de Creneau. On itère le tableau pour pouvoir ajouter chaque Creneau au tableau de l'objet Salle, en faisant chaque fois appel à son constructeur lorsque la valeur renvoyé par l'API n'est pas nulle.

[creneauParser](/Files/creneau_8c.md#fonction-creneauparser) , [json_array_foreach](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_foreach)

### fonction getSalleN()

```c
char * getSalleN(
    Salle s
)
```

Accesseur de l'objet Nom de Salle.

**Paramètres**:

* **s** Référence de Salle.

**Renvoie**: Valeur du Nom de Salle de type char*.

### fonction getSalleC()

```c
Creneau * getSalleC(
    Salle s
)
```

Accesseur du tableau de Creneau de Salle.

**Paramètres**:

* **s** Référence de Salle.

**Renvoie**: Adresse de la première case du tableau de Creneau, de type Creneau*.

### fonction getJsonSalle()

```c
json_t * getJsonSalle(
    Salle s
)
```

Accesseur de la représentation en objet JSON de Salle.

Renvoie la représentation objet JSON de Salle en utilisant l'API Jansson. Pour cela, on construit un nouvel objet JSON et on y attache les clés "nom" qui stocke la valeur Nom de Salle et "enseignants" qui est un tableau. En itérant ensuite le tableau de Creneau de Salle, on ajoute à ce tableau la représentation objet JSON de chaque Creneau ou null si aucun Creneau n'est instancié à l'indice itérée.

[getJsonCreneau](/Files/creneau_8c.md#fonction-getjsoncreneau) , [json_array](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array) , [json_array_append](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_array_append)

### fonction setSalleN()

```c
Salle setSalleN(
    Salle s,
    char * nom
)
```

Définie l'objet Nom de Salle.

**Paramètres**:

* **s** Référence de Salle à modifier.
* **nom** Valeur du Nom de type char*.

**Renvoie**: Salle avec la nouvelle valeur de Nom.

### fonction ajouterSalleC()

```c
Salle ajouterSalleC(
    Salle s,
    Creneau c
)
```

Ajoute une référence de l'objet Creneau au tableau de Creneau de Salle.

Si Salle est libre dans l'intervalle de Horaire, on fixe sur chaque indice de l'intervalle une référence de Creneau afin de la "réserver".

[isFreeSalle](/Files/salle_8c.md#fonction-isfreesalle)

### fonction supprimerSalleH()

```c
Salle supprimerSalleH(
    Salle s,
    Horaire h
)
```

Supprime tout Creneau réservé dans l'intervalle de Horaire.

Si un Creneau a été instancié dans l'intervalle Horaire de suppression, on réinitialise le tableau dans l'intervalle par NULL pour marquer Horaire comme "libre" ou "non réservé".

[isEmptySalle](/Files/salle_8c.md#fonction-isemptysalle)

### fonction modifierSalleHC()

```c
Salle modifierSalleHC(
    Salle s,
    Horaire horaire_modifie,
    Creneau c
)
```

Modifie le Creneau à l'Horaire horaire_modifié pour le remplacer par un nouveau Creneau.

On supprime toute référence de Creneau instancié dans l'intervalle Horaire pour pouvoir y ajouter le nouveau Creneau.

### fonction isFreeSalle()

```c
bool isFreeSalle(
    Salle s,
    Horaire h
)
```

Vérifie si Salle ne contient aucun créneau réservé dans l'intervalle de Horaire.

Une salle est considéré comme "libre" si dans l'intervalle Horaire indiqué en paramètre, le tableau de Creneau ne contient que des références NULL, c'est-à-dire qu'il ne contient aucune instance de Creneau.

### fonction isEmptySalle()

```c
bool isEmptySalle(
    Salle s
)
```

Vérifie si Salle ne contient aucun créneau réservé.

Une salle est considéré comme "vide" si elle est libre toute la journée, c'est-à-dire dans l'intervalle autorisée de Horaire de $ \llbracket 8, 20 \rrbracket $.

### fonction afficheSalle()

```c
void afficheSalle(
    Salle s
)
```

Imprime le nom de Salle ainsi que son tableau de Creneau sur stdout, suivi d'un retour à la ligne.

Imprime le Nom de l'objet Salle suivi par une représentation de son tableau de Creneau qu'on itère à partir de 8 jusqu'à 20 pour symboliser une journée de cours. L'impression suit alors le format :

```txt
-----------------
EDT de la Salle : {Nom de Salle}
-----------------

de 8h00 à 9h00
VIDE                             //< si la référence à l'indice itéré est NULL

de 9h00 à 10h00
{Enseignant de Creneau}          //< si la référence à l'indice itéré
{Formation de Creneau}               est un Creneau

...
```

[afficheHoraire](/Files/horaire_8c.md#fonction-affichehoraire) , [afficheEnseignant](/Files/enseignant_8c.md#fonction-afficheenseignant) , [getCreneauE](/Files/creneau_8c.md#fonction-getcreneaue) , [getCreneauF](/Files/creneau_8c.md#fonction-getcreneauf) , [Creneau](/Files/creneau_8h.md#typedef-creneau)

### fonction toStringSalle()

```c
char * toStringSalle(
    Salle s
)
```

Accesseur de la représentation en chaîne de caractère JSON de Salle.

Renvoie la représentation JSON en chaîne de caractères de Salle en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "salle.h"

#ifdef DEBUG
#include "tests.h"
#endif

 /************************************************************\
 *                     Structure de Salle                     *
 \************************************************************/

struct s_salle {
    char nom[BUFSIZ];
    Creneau creneaux[24];
};


/************************************************************\
*                   Constructeurs de Salle                   *
\************************************************************/

Salle salle() {
    Salle s = (Salle)malloc(sizeof(struct s_salle));
    for (int i = 0; i < 24; i++) {
        s->creneaux[i] = NULL;
    }
    return s;
}

Salle salleCopie(char* nom) {
    Salle s = salle();
    setSalleN(s, nom);
    return s;
}

Salle salleParser(json_t* json_salle) {
    json_t* nom = json_object_get(json_salle, "nom");
    json_t* json_arr_c = json_object_get(json_salle, "creneaux");
    assert(json_is_string(nom) && json_is_array(json_arr_c));
    Salle s = salleCopie((char*)json_string_value(nom));
    size_t index;
    json_t* value;
    json_array_foreach(json_arr_c, index, value) {
        if (!json_is_null(value)) {
            ajouterSalleC(s, creneauParser(value));
        }
    }
    return s;
}


/************************************************************\
*              Getters, setters et opérateurs                *
\************************************************************/

char* getSalleN(Salle s) {
    return s->nom;
}

Creneau* getSalleC(Salle s) {
    return s->creneaux;
}

json_t* getJsonSalle(Salle s) {
    json_t* root = json_object();
    json_t* json_arr = json_array();
    json_object_set_new(root, "nom", json_string(s->nom));
    json_object_set_new(root, "creneaux", json_arr);
    for (int i = 0; i < 24; i++) {
        if (s->creneaux[i] == NULL) {
            json_array_append(json_arr, json_null());
        }
        else {
            json_array_append(json_arr, getJsonCreneau(s->creneaux[i]));
        }
    }
    return root;
}

Salle setSalleN(Salle s, char* nom) {
    strcpy(s->nom, nom);
    return s;
}

Salle ajouterSalleC(Salle s, Creneau c) {
    if (isFreeSalle(s, getCreneauH(c))) {
        for (int i = getDebut(getCreneauH(c)); i < getFin(getCreneauH(c));i++) {
            s->creneaux[i] = c;
        }
    }
    return s;
}

Salle supprimerSalleH(Salle s, Horaire h) {
    if (isEmptySalle(s)) {
        return s;
    }
    for (int i = getDebut(h); i <= getFin(h); i++) {
        s->creneaux[i] = NULL;
    }
    return s;
}

Salle modifierSalleHC(Salle s, Horaire horaire_modifie, Creneau c) {
    supprimerSalleH(s, horaire_modifie);
    ajouterSalleC(s, c);
    return s;
}

bool isFreeSalle(Salle s, Horaire h) {
    bool isFree = true;
    for (int i = getDebut(h); i < getFin(h) && isFree; i++) {
        isFree = s->creneaux[i] == NULL;
    }
    return isFree;
}

bool isEmptySalle(Salle s) {
    return isFreeSalle(s, horaire(8, 20));
}


/************************************************************\
*                 Représentations externes                   *
\************************************************************/

void afficheSalle(Salle s) {
    printf("-----------------\n");
    printf("EDT de la Salle : %s\n", getSalleN(s));
    printf("-----------------\n\n");
    for (int i = 8;i < 20;i++) {
        printf("de ");
        afficheHoraire(horaire(i, i + 1));
        if (s->creneaux[i] == NULL) {
            printf("VIDE");
        }
        else {
            afficheEnseignant(getCreneauE(s->creneaux[i]));
            printf("%s\n%s", getCreneauENS(s->creneaux[i]), getCreneauF(s->creneaux[i]));
        }
        printf("\n\n");
    }
}

char* toStringSalle(Salle s) {
    json_t* json_salle = getJsonSalle(s);
    char* str = json_dumps(json_salle, 0);
#ifdef DEBUG
    puts(str);
#endif
    // deallocation json object memory
    json_decref(json_salle);

    return str;
}


/************************************************************\
*                  Tests unitaires de Salle                  *
\************************************************************/

#ifdef TEST

int main() {

    // init

    char* s1_nom = "103";
    char* s2_nom = "118";

    Horaire h1 = horaire(8, 9);
    Horaire h2 = horaire(15, 17);

    Creneau c1 = creneau(enseignantCopie("TRUILLET", "Philippe"), h1, "Structure de données", "CUPGE", s1_nom);
    Creneau c2 = creneau(enseignantCopie("GAILDRAT", "Véronique"), h2, "Programmation orientée objet", "CUPGE", s2_nom);

    // testing

    Salle s = salleCopie(s1_nom);

    info(ajouterSalleC(s, c2));
    test(isFreeSalle(s, h1) == true);

    info(ajouterSalleC(s, c1));
    test(isFreeSalle(s, h1) == false);

    info(afficheSalle(s));

    info(modifierSalleHC(s, h1, c2));

    test(isFreeSalle(s, h1) == true);
    test(isFreeSalle(s, h2) == false);

    test(isEmptySalle(s) == false);

    info(supprimerSalleH(s, h2));

    test(isFreeSalle(s, h2) == true);

    test(isEmptySalle(s) == true);

    info(afficheSalle(s));

    info(ajouterSalleC(s, c2));
    test(strcmp(toStringSalle(s), toStringSalle(salleParser(getJsonSalle(s)))) == 0);

    return 0;
}

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
