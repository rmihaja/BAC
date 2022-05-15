# Référence du fichier include/salle.h

En-tête de la structure de données Salle.  [Plus de détails...](#description-détaillée)

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| typedef struct [s_salle](/Classes/structs__salle.md) * | **[Salle](/Files/salle_8h.md#typedef-salle)** <br>Objet Salle.  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[salle](/Files/salle_8h.md#fonction-salle)**()<br>Construit un nouvel objet Salle avec un Nom vide et un tableau de Creneau vide.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[salleCopie](/Files/salle_8h.md#fonction-sallecopie)**(char * nom)<br>Construit un nouvel objet Salle avec un Nom et un tableau de Creneau vide.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[salleParser](/Files/salle_8h.md#fonction-salleparser)**([json_t](/Classes/structjson__t.md) * json_salle)<br>Construit un nouvel objet Salle à partir de sa représentation en objet JSON.  |
| char * | **[getSalleN](/Files/salle_8h.md#fonction-getsallen)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Accesseur de l'objet Nom de Salle.  |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) * | **[getSalleC](/Files/salle_8h.md#fonction-getsallec)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Accesseur du tableau de Creneau de Salle.  |
| [json_t](/Classes/structjson__t.md) * | **[getJsonSalle](/Files/salle_8h.md#fonction-getjsonsalle)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Accesseur de la représentation en objet JSON de Salle.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[setSalleN](/Files/salle_8h.md#fonction-setsallen)**([Salle](/Files/salle_8h.md#typedef-salle) s, char * nom)<br>Définie l'objet Nom de Salle.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[ajouterSalleC](/Files/salle_8h.md#fonction-ajoutersallec)**([Salle](/Files/salle_8h.md#typedef-salle) s, [Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Ajoute une référence de l'objet Creneau au tableau de Creneau de Salle.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[supprimerSalleH](/Files/salle_8h.md#fonction-supprimersalleh)**([Salle](/Files/salle_8h.md#typedef-salle) s, [Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Supprime tout Creneau réservé dans l'intervalle de Horaire.  |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[modifierSalleHC](/Files/salle_8h.md#fonction-modifiersallehc)**([Salle](/Files/salle_8h.md#typedef-salle) s, [Horaire](/Files/horaire_8h.md#typedef-horaire) horaire_modifie, [Creneau](/Files/creneau_8h.md#typedef-creneau) c)<br>Modifie le Creneau à l'Horaire horaire_modifié pour le remplacer par un nouveau Creneau.  |
| bool | **[isFreeSalle](/Files/salle_8h.md#fonction-isfreesalle)**([Salle](/Files/salle_8h.md#typedef-salle) s, [Horaire](/Files/horaire_8h.md#typedef-horaire) h)<br>Vérifie si Salle ne contient aucun créneau réservé dans l'intervalle de Horaire.  |
| bool | **[isEmptySalle](/Files/salle_8h.md#fonction-isemptysalle)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Vérifie si Salle ne contient aucun créneau réservé.  |
| void | **[afficheSalle](/Files/salle_8h.md#fonction-affichesalle)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Imprime le nom de Salle ainsi que son tableau de Creneau sur stdout, suivi d'un retour à la ligne.  |
| char * | **[toStringSalle](/Files/salle_8h.md#fonction-tostringsalle)**([Salle](/Files/salle_8h.md#typedef-salle) s)<br>Accesseur de la représentation en chaîne de caractère JSON de Salle.  |

## Description détaillée

En-tête de la structure de données Salle.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### typedef Salle

```c
typedef struct s_salle* Salle;
```

Objet Salle.

## Documentation des fonctions

### fonction salle()

```c
Salle salle()
```

Construit un nouvel objet Salle avec un Nom vide et un tableau de Creneau vide.

**Paramètres**:

* **nom** Nom de Salle de type char*.

**Renvoie**: Nouvelle instance allouée de Salle.

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

**Paramètres**:

* **json_salle** Objet JSON de Salle.

**Renvoie**: Nouvelle instance allouée de Salle.

!> **Précondition**: json_salle doit contenir une clé "nom" et "creneaux" stockant un tableau de Creneau ou null.

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

**Paramètres**:

* **s** Référence de Salle.

**Renvoie**: Objet JSON de Salle de type json_t*.

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

**Paramètres**:

* **s** Référence de Salle.
* **c** Référence de Creneau à ajouter.

**Renvoie**: Salle possédant une référence de Creneau parmi le tableau de Creneau si Salle était libre dans l'intervalle de Horaire.

!> **Précondition**: Salle ne doit contenir aucune autre référence de Creneau dans l'intervalle de Horaire indiqué par Creneau.

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

**Paramètres**:

* **s** Référence de Salle.
* **h** Référence de Horaire représentant l'intervalle de suppression.

**Renvoie**: Salle ne possédant aucun Creneau réservé dans l'intervalle de suppression.

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

**Paramètres**:

* **s** Référence de Salle.
* **horaire_modifie** Référence de Horaire du Creneau à modifier.
* **c** Référence du nouveau Creneau à ajouter.

**Renvoie**: Salle possédant une référence de Creneau parmi le tableau de Creneau.

!> **Précondition**: Salle doit avoir un Creneau réservé à l'Horaire horaire_modifié.

On supprime toute référence de Creneau instancié dans l'intervalle Horaire pour pouvoir y ajouter le nouveau Creneau.

### fonction isFreeSalle()

```c
bool isFreeSalle(
    Salle s,
    Horaire h
)
```

Vérifie si Salle ne contient aucun créneau réservé dans l'intervalle de Horaire.

**Paramètres**:

* **s** Référence de Salle.
* **h** Référence de Horaire représentant l'intervalle de vérification.

**Renvoie**:

* true si aucun Creneau n'a été réservé dans l'intervalle de Horaire.
* false si un ou plusieurs Creneau a été réservé dans l'intervalle de Horaire.

Une salle est considéré comme "libre" si dans l'intervalle Horaire indiqué en paramètre, le tableau de Creneau ne contient que des références NULL, c'est-à-dire qu'il ne contient aucune instance de Creneau.

### fonction isEmptySalle()

```c
bool isEmptySalle(
    Salle s
)
```

Vérifie si Salle ne contient aucun créneau réservé.

**Paramètres**:

* **s** Référence de Salle.

**Renvoie**:

* true si Salle ne contient aucun Creneau réservé dans son tableau de Creneau.
* false si un Creneau est réservé dans le tableau de Creneau de Salle.

Une salle est considéré comme "vide" si elle est libre toute la journée, c'est-à-dire dans l'intervalle autorisée de Horaire de $ \llbracket 8, 20 \rrbracket $.

### fonction afficheSalle()

```c
void afficheSalle(
    Salle s
)
```

Imprime le nom de Salle ainsi que son tableau de Creneau sur stdout, suivi d'un retour à la ligne.

**Paramètres**:

* **s** Salle à afficher.

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

**Paramètres**:

* **s** Référence de Salle.

**Renvoie**: Représentation JSON de Salle de type char*.

Renvoie la représentation JSON en chaîne de caractères de Salle en utilisant l'API Jansson. Pour cela, on accède d'abord à la représentation JSON objet pour pouvoir le repasser à l'API. Enfin, avant de renvoyer la chaîne de caractères, il ne faut pas oublier de libérer la mémoire allouée à l'objet JSON (à faire manuellement en décrémentant son nombre de référencement).

[json_dumps](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dumps) , [json_decref](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_decref)

## Code source

```c

#ifndef __SALLE_H__
#define __SALLE_H__

#include <stdbool.h>
#include "creneau.h"
#include <jansson.h>

typedef struct s_salle* Salle;

Salle salle();

Salle salleCopie(char* nom);

Salle salleParser(json_t* json_salle);

char* getSalleN(Salle s);

Creneau* getSalleC(Salle s);

json_t* getJsonSalle(Salle s);

Salle setSalleN(Salle s, char* nom);

Salle ajouterSalleC(Salle s, Creneau c);

Salle supprimerSalleH(Salle s, Horaire h);

Salle modifierSalleHC(Salle s, Horaire horaire_modifie, Creneau c);

bool isFreeSalle(Salle s, Horaire h);

bool isEmptySalle(Salle s);

void afficheSalle(Salle s);

char* toStringSalle(Salle s);

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0

[Voir la documentation Doxygen originale](https://rmihaja.github.io/BAC/doxygen/index.html)
