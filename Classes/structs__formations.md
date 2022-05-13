# Référence de la stucture s_formations

Structure représentant un tableau de Formation.  [Plus de détails...](#description-détaillée)

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| [Formation](/Files/formation_8h.md#typedef-formation) * | **[formations](/Classes/structs__formations.md#variable-formations)**  |
| int | **[taille](/Classes/structs__formations.md#variable-taille)**  |
| int | **[capacite](/Classes/structs__formations.md#variable-capacite)**  |

## Description détaillée

```c
struct s_formations;
```

Structure représentant un tableau de Formation.

Structure permettant de stocker un tableau de Formation marqué par l'adresse de sa première indice et sa taille.

## Documentation des champs

### variable formations

```c
Formation * formations;
```

Adresse du premier élément du tableau de Formation

### variable taille

```c
int taille;
```

Taille du tableau de Formation

### variable capacite

```c
int capacite;
```

Taille maximalle du tableau de Formation

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
