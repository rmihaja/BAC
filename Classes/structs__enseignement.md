# Référence de la stucture s_enseignement

Structure représentant un élément de la liste chaînée Enseignements.  [Plus de détails...](#description-détaillée)

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| char | **[nom](/Classes/structs__enseignement.md#variable-nom)**  |
| struct [s_enseignement](/Classes/structs__enseignement.md) * | **[suivant](/Classes/structs__enseignement.md#variable-suivant)**  |

## Description détaillée

```c
struct s_enseignement;
```

Structure représentant un élément de la liste chaînée Enseignements.

Structure permettant de stocker un élément de la liste des Enseignements, en stockant la référence de Enseignement puis l'élément suivant.

## Documentation des champs

### variable nom

```c
char nom;
```

Référence du nom de Enseignement à stocker

### variable suivant

```c
struct s_enseignement * suivant;
```

Référence de l'élément suivant de la liste des Enseignements

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
