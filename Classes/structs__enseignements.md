# Référence de la stucture s_enseignements

Structure représentant une liste chaînée de Enseignement.  [Plus de détails...](#description-détaillée)

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| [Enseignement](/Classes/structs__enseignement.md) | **[sentinelle](/Classes/structs__enseignements.md#variable-sentinelle)**  |
| int | **[taille](/Classes/structs__enseignements.md#variable-taille)**  |

## Description détaillée

```c
struct s_enseignements;
```

Structure représentant une liste chaînée de Enseignement.

Structure permettant de représenter une liste chaînée d'éléments contenant un objet Enseignement, avec un accès constant de la tête de liste, à l'aide d'une sentinelle, et de sa taille.

## Documentation des champs

### variable sentinelle

```c
Enseignement sentinelle;
```

Sentinelle de l'objet Enseignements

### variable taille

```c
int taille;
```

Taille de l'objet Enseignements excluant la Sentinelle

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0

[Voir la documentation Doxygen originale](https://rmihaja.github.io/BAC/doxygen/index.html)
