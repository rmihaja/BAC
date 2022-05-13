# Référence de la stucture s_salle

Structure représentant un objet Salle.  [Plus de détails...](#description-détaillée)

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| char | **[nom](/Classes/structs__salle.md#variable-nom)**  |
| [Creneau](/Files/creneau_8h.md#typedef-creneau) | **[creneaux](/Classes/structs__salle.md#variable-creneaux)**  |

## Description détaillée

```c
struct s_salle;
```

Structure représentant un objet Salle.

Structure permettant de stocker l'attribut nom d'une salle, ainsi qu'un tableau de Creneau pour pouvoir stocker les créneaux réservés aux indices de l'intervalle indiqué par chaque Creneau.

## Documentation des champs

### variable nom

```c
char nom;
```

Nom de l'objet Salle.

### variable creneaux

```c
Creneau creneaux;
```

Tableau de Créneau de l'objet Salle. Chaque intervalle d'heure est délimitée par ses indices, d'où la taille de 24 pour marquer un jour.

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
