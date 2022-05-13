# Référence de la stucture s_element_ss

Structure représentant un élément de la liste chaînée Salles.  [Plus de détails...](#description-détaillée)

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| [Salle](/Files/salle_8h.md#typedef-salle) | **[s](/Classes/structs__element__ss.md#variable-s)**  |
| struct [s_element_ss](/Classes/structs__element__ss.md) * | **[suivant](/Classes/structs__element__ss.md#variable-suivant)**  |

## Description détaillée

```c
struct s_element_ss;
```

Structure représentant un élément de la liste chaînée Salles.

Structure permettant de stocker un élément de la liste des Salles, en stockant la référence de Salle puis l'élément suivant.

## Documentation des champs

### variable s

```c
Salle s;
```

Référence de Salle à stocker

### variable suivant

```c
struct s_element_ss * suivant;
```

Référence de l'élément suivant de la liste des Salles

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
