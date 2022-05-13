# Référence de la stucture s_element_es

Structure représentant un élément de la liste chaînée Enseignants.  [Plus de détails...](#description-détaillée)

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[e](/Classes/structs__element__es.md#variable-e)**  |
| struct [s_element_es](/Classes/structs__element__es.md) * | **[suivant](/Classes/structs__element__es.md#variable-suivant)**  |

## Description détaillée

```c
struct s_element_es;
```

Structure représentant un élément de la liste chaînée Enseignants.

Structure permettant de stocker un élément de la liste des Enseignants, en stockant la référence de Enseignant puis l'élément suivant.

## Documentation des champs

### variable e

```c
Enseignant e;
```

Référence de Enseignant à stocker

### variable suivant

```c
struct s_element_es * suivant;
```

Référence de l'élément suivant de la liste des Enseignants

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
