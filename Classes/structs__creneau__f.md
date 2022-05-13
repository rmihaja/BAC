# Référence de la stucture s_creneau_f

Structure représentant un élément de la liste chaînée de Creneau de Formation.  [Plus de détails...](#description-détaillée)

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) | **[creneau](/Classes/structs__creneau__f.md#variable-creneau)**  |
| struct [s_creneau_f](/Classes/structs__creneau__f.md) * | **[suivant](/Classes/structs__creneau__f.md#variable-suivant)**  |

## Description détaillée

```c
struct s_creneau_f;
```

Structure représentant un élément de la liste chaînée de Creneau de Formation.

Structure permettant de stocker un élément de la liste de Creneau, en stockant la référence de Creneau puis l'élément suivant.

## Documentation des champs

### variable creneau

```c
Creneau creneau;
```

Référence de Creneau à stocker

### variable suivant

```c
struct s_creneau_f * suivant;
```

Référence de l'élément suivant de la liste de Creneau

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
