# Référence de la stucture s_formation

Structure représentant un objet Formation.  [Plus de détails...](#description-détaillée)

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| char * | **[nom](/Classes/structs__formation.md#variable-nom)**  |
| [CreneauF](/Classes/structs__creneau__f.md) | **[sentinelle](/Classes/structs__formation.md#variable-sentinelle)**  |
| int | **[taille](/Classes/structs__formation.md#variable-taille)**  |

## Description détaillée

```c
struct s_formation;
```

Structure représentant un objet Formation.

Structure permettant de stocker l'attribut nom d'une formation sous forme de chaîne de caractères, ainsi qu'une liste chaînée d'éléments contenant un objet Creneau, avec un accès constant de la tête de liste à l'aide d'une sentinelle, et de sa taille.

## Documentation des champs

### variable nom

```c
char * nom;
```

Nom de l'objet Formation

### variable sentinelle

```c
CreneauF sentinelle;
```

Sentinelle de la liste de Creneau

### variable taille

```c
int taille;
```

Taille de la liste de Creneau excluant la Sentinelle

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
