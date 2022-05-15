# Référence de la stucture s_salles

Structure représentant une liste chaînée de Salle.  [Plus de détails...](#description-détaillée)

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| [ElementSs](/Classes/structs__element__ss.md) | **[sentinelle](/Classes/structs__salles.md#variable-sentinelle)**  |
| int | **[taille](/Classes/structs__salles.md#variable-taille)**  |

## Description détaillée

```c
struct s_salles;
```

Structure représentant une liste chaînée de Salle.

Structure permettant de représenter une liste chaînée d'éléments contenant un objet Salle, avec un accès constant de la tête de liste, à l'aide d'une sentinelle, et de sa taille.

## Documentation des champs

### variable sentinelle

```c
ElementSs sentinelle;
```

Sentinelle de l'objet Salles

### variable taille

```c
int taille;
```

Taille de l'objet Salles excluant la Sentinelle

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0

[Voir la documentation Doxygen originale](https://rmihaja.github.io/BAC/doxygen/index.html)
