# Référence de la stucture s_controle

Objet Controle.

## Champs de données

|                | Nom           |
| -------------- | -------------- |
| bool | **[isAdmin](/Classes/structs__controle.md#variable-isadmin)**  |
| char | **[MDP](/Classes/structs__controle.md#variable-mdp)**  |
| [Enseignants](/Files/enseignants_8h.md#typedef-enseignants) | **[enseignants](/Classes/structs__controle.md#variable-enseignants)**  |
| [Enseignements](/Files/enseignements_8h.md#typedef-enseignements) | **[enseignements](/Classes/structs__controle.md#variable-enseignements)**  |
| [Salles](/Files/salles_8h.md#typedef-salles) | **[salles](/Classes/structs__controle.md#variable-salles)**  |
| [Formations](/Files/formations_8h.md#typedef-formations) | **[formations](/Classes/structs__controle.md#variable-formations)**  |
| EtatAffichage * | **[panneauCourant](/Classes/structs__controle.md#variable-panneaucourant)**  |
| char * | **[cheminData](/Classes/structs__controle.md#variable-chemindata)**  |
| int | **[panneauSuivant](/Classes/structs__controle.md#variable-panneausuivant)**  |

## Documentation des champs

### variable isAdmin

```c
bool isAdmin;
```

Permet de savoir si l'utilisateur courant est connecté en tant qu'administrateur

### variable MDP

```c
char MDP;
```

Chaîne de caractère décodé du mot de passe

### variable enseignants

```c
Enseignants enseignants;
```

Référence des Enseignants

### variable enseignements

```c
Enseignements enseignements;
```

Référence des Enseignements

### variable salles

```c
Salles salles;
```

Référence des Salles

### variable formations

```c
Formations formations;
```

Référence des Formations

### variable panneauCourant

```c
EtatAffichage * panneauCourant;
```

Référence du panneau courant affiché à l'utilisateur

### variable cheminData

```c
char * cheminData;
```

Référence du chemin de stockage des données sous formation JSON

### variable panneauSuivant

```c
int panneauSuivant;
```

Panneau suivant choisi par l'utilisateur

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
