# Référence de la stucture s_enseignants

Structure représentant une liste chaînée de Enseignant.  [Plus de détails...](#description-détaillée)

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| [ElementEs](/Classes/structs__element__es.md) | **[sentinelle](/Classes/structs__enseignants.md#variable-sentinelle)**  |
| int | **[taille](/Classes/structs__enseignants.md#variable-taille)**  |

## Description détaillée

```c
struct s_enseignants;
```

Structure représentant une liste chaînée de Enseignant.

Structure permettant de représenter une liste chaînée d'éléments contenant un objet Enseignant, avec un accès constant de la tête de liste, à l'aide d'une sentinelle, et de sa taille.

## Documentation des champs

### variable sentinelle

```c
ElementEs sentinelle;
```

Sentinelle de l'objet Enseignants

### variable taille

```c
int taille;
```

Taille de l'objet Enseignants excluant la Sentinelle

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
