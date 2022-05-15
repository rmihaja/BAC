# Référence de la stucture s_creneau

Structure représentant un objet Creneau.  [Plus de détails...](#description-détaillée)

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) | **[enseignant](/Classes/structs__creneau.md#variable-enseignant)**  |
| [Horaire](/Files/horaire_8h.md#typedef-horaire) | **[horaire](/Classes/structs__creneau.md#variable-horaire)**  |
| char * | **[enseignement](/Classes/structs__creneau.md#variable-enseignement)**  |
| char * | **[formation](/Classes/structs__creneau.md#variable-formation)**  |
| char * | **[salle](/Classes/structs__creneau.md#variable-salle)**  |

## Description détaillée

```c
struct s_creneau;
```

Structure représentant un objet Creneau.

Structure permettant de stocker les attributs (Enseignant, Horaire, Formation et Salle) d'un créneau.

## Documentation des champs

### variable enseignant

```c
Enseignant enseignant;
```

Référence de Enseignant de l'objet Creneau

### variable horaire

```c
Horaire horaire;
```

Référence de Horaire de l'objet Creneau

### variable enseignement

```c
char * enseignement;
```

Enseignement de l'objet Creneau

### variable formation

```c
char * formation;
```

Formation de l'objet Creneau

### variable salle

```c
char * salle;
```

Salle de l'objet Creneau

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0

[Voir la documentation Doxygen originale](https://rmihaja.github.io/BAC/doxygen/index.html)
