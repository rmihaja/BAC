# Référence du fichier src/control/controle.c

Code source de la structure de données Controle.  [Plus de détails...](#description-détaillée)

## Structures de données

|                | Nom           |
| -------------- | -------------- |
| struct | **[s_controle](/Classes/structs__controle.md)** <br>Objet Controle.  |

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| enum| **[liste_etat_affichage](/Files/controle_8c.md#enum-liste_etat_affichage)** { BIENVENUE, CLIENT, EDT, AUTH, ADMIN, ENSEIGNANT, ENSEIGNEMENT, SALLE, BOOK, WRITE} |
| typedef enum [liste_etat_affichage](/Files/controle_8c.md#enum-liste-etat-affichage) | **[EtatAffichage](/Files/controle_8c.md#typedef-etataffichage)**  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| char * | **[decodeMDP](/Files/controle_8c.md#fonction-decodemdp)**(const char * mdp, char * dest)<br>Décrypte le mot de passe passé en paramètre.  |
| char * | **[encodeMDP](/Files/controle_8c.md#fonction-encodemdp)**(char * mdp)<br>Encrypte le mot de passe passé en paramètre.  |
| void | **[controleSerializer](/Files/controle_8c.md#fonction-controleserializer)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>imprime sur un fichier du disque (spécifié par Controle) les données courants de l'application sour format JSON  |
| [Controle](/Files/controle_8h.md#typedef-controle) | **[controleParser](/Files/controle_8c.md#fonction-controleparser)**([Controle](/Files/controle_8h.md#typedef-controle) C, [json_t](/Classes/structjson__t.md) * json_controle)<br>Construit un objet Controle avec les données JSON renvoyé par l'API Jansson.  |
| [Formations](/Files/formations_8h.md#typedef-formations) | **[populateFormations](/Files/controle_8c.md#fonction-populateformations)**([Formations](/Files/formations_8h.md#typedef-formations) fs)<br>Ajoute les formations par défaut à la liste des Formations.  |
| [Controle](/Files/controle_8h.md#typedef-controle) | **[controleClean](/Files/controle_8c.md#fonction-controleclean)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Construit un objet Controle avec des listes vides et les formations par défaut.  |
| [Controle](/Files/controle_8h.md#typedef-controle) | **[controle](/Files/controle_8c.md#fonction-controle)**(char * cheminData)<br>Construit un nouvelle objet Controle à partir des données JSON s'il existe.  |
| char * | **[getUserProfile](/Files/controle_8c.md#fonction-getuserprofile)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Accesseur de la représentation en chaîne de caractère du Profil courant.  |
| int | **[afficherProfil](/Files/controle_8c.md#fonction-afficherprofil)**(char * profil)<br>Imprime sur stdout le profil de l'utilisateur connecté  |
| int | **[afficherPanneauBienvenue](/Files/controle_8c.md#fonction-afficherpanneaubienvenue)**()<br>Affiche l'interface de présentation de l'application.  |
| int | **[afficherPanneauSortie](/Files/controle_8c.md#fonction-afficherpanneausortie)**()<br>Affiche l'interface de sortie de l'application.  |
| int | **[afficherPanneauClient](/Files/controle_8c.md#fonction-afficherpanneauclient)**()<br>Affiche l'interface de sélection d'emploi du temps.  |
| void | **[afficherEDTEnseignant](/Files/controle_8c.md#fonction-afficheredtenseignant)**([Controle](/Files/controle_8h.md#typedef-controle) C, [Enseignant](/Files/enseignant_8h.md#typedef-enseignant) e)<br>Affiche l'emploi du temps pour un enseignant.  |
| void | **[afficherEDTFormation](/Files/controle_8c.md#fonction-afficheredtformation)**([Controle](/Files/controle_8h.md#typedef-controle) C, char * formation)<br>Affiche l'emploi du temps pour une formation.  |
| int | **[afficherPanneauEDTEnseignants](/Files/controle_8c.md#fonction-afficherpanneauedtenseignants)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'emploi du temps par enseignant.  |
| int | **[afficherPanneauEDTFormations](/Files/controle_8c.md#fonction-afficherpanneauedtformations)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'emploi du temps par formation.  |
| int | **[afficherPanneauEDTSalles](/Files/controle_8c.md#fonction-afficherpanneauedtsalles)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'emploi du temps par salle.  |
| int | **[afficherPanneauAdmin](/Files/controle_8c.md#fonction-afficherpanneauadmin)**()<br>Affiche l'interface de gestion général.  |
| int | **[afficherPanneauGestionEnseignants](/Files/controle_8c.md#fonction-afficherpanneaugestionenseignants)**()<br>Affiche l'interface de gestion des enseignants.  |
| int | **[afficherPanneauAjouterEnseignants](/Files/controle_8c.md#fonction-afficherpanneauajouterenseignants)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface d'ajout d'un enseignant.  |
| int | **[afficherPanneauModifierEnseignants](/Files/controle_8c.md#fonction-afficherpanneaumodifierenseignants)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface de modification d'un enseignant.  |
| int | **[afficherPanneauSupprimerEnseignants](/Files/controle_8c.md#fonction-afficherpanneausupprimerenseignants)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface de modification d'un enseignant.  |
| int | **[afficherPanneauListeEnseignants](/Files/controle_8c.md#fonction-afficherpanneaulisteenseignants)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche la liste des enseignants.  |
| int | **[afficherPanneauGestionEnseignements](/Files/controle_8c.md#fonction-afficherpanneaugestionenseignements)**()<br>Affiche l'interface de gestion d'un enseignement.  |
| int | **[afficherPanneauAjouterEnseignements](/Files/controle_8c.md#fonction-afficherpanneauajouterenseignements)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface d'ajout d'un enseignement.  |
| int | **[afficherPanneauModifierEnseignements](/Files/controle_8c.md#fonction-afficherpanneaumodifierenseignements)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface de modification d'un enseignement.  |
| int | **[afficherPanneauSupprimerEnseignements](/Files/controle_8c.md#fonction-afficherpanneausupprimerenseignements)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface de suppression d'un enseignement.  |
| int | **[afficherPanneauListeEnseignements](/Files/controle_8c.md#fonction-afficherpanneaulisteenseignements)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche la liste des enseignements.  |
| int | **[afficherPanneauGestionSalles](/Files/controle_8c.md#fonction-afficherpanneaugestionsalles)**()<br>Affiche l'interface de gestion d'une salle.  |
| int | **[afficherPanneauAjouterSalles](/Files/controle_8c.md#fonction-afficherpanneauajoutersalles)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface d'ajout d'une salle.  |
| int | **[afficherPanneauModifierSalles](/Files/controle_8c.md#fonction-afficherpanneaumodifiersalles)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface de modification d'une salle.  |
| int | **[afficherPanneauListeSalles](/Files/controle_8c.md#fonction-afficherpanneaulistesalles)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche la liste des salles.  |
| int | **[afficherPanneauGestionCreneaux](/Files/controle_8c.md#fonction-afficherpanneaugestioncreneaux)**()<br>Affiche l'interface de gestion d'un créneau ou réservation.  |
| int | **[afficherPanneauAjouterCreneaux](/Files/controle_8c.md#fonction-afficherpanneauajoutercreneaux)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface d'ajout d'un créneau ou réservation.  |
| int | **[afficherPanneauSupprimerCreneaux](/Files/controle_8c.md#fonction-afficherpanneausupprimercreneaux)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface de suppression d'un créneau ou réservation.  |
| int | **[afficherPanneauModifierCreneaux](/Files/controle_8c.md#fonction-afficherpanneaumodifiercreneaux)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface de modification d'un créneau ou réservation.  |
| int | **[afficherPanneauListeCreneaux](/Files/controle_8c.md#fonction-afficherpanneaulistecreneaux)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche la liste des créneaux, par formation.  |
| int | **[afficherPanneauAuthentificationMDP](/Files/controle_8c.md#fonction-afficherpanneauauthentificationmdp)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface de vérification de mot de passe ou authentification.  |
| int | **[afficherPanneauModifierMDP](/Files/controle_8c.md#fonction-afficherpanneaumodifiermdp)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Affiche l'interface de modification d'un mot de passe.  |
| int | **[afficherProchainPanneau](/Files/controle_8c.md#fonction-afficherprochainpanneau)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Gère les panneaux à afficher en fonction du choix de l'utilisateur et du panneau courant.  |
| int | **[run](/Files/controle_8c.md#fonction-run)**([Controle](/Files/controle_8h.md#typedef-controle) C)<br>Boucle principale de l'interface de Controle.  |

## Description détaillée

Code source de la structure de données Controle.

**Auteur**: Mihaja RAZAFIMAHEFA & Ambre ROUZADE

**Copyright**: Copyright (c) 2022

## Documentation des types

### enum liste_etat_affichage

| Enumeration | Valeur | Description |
| ----------- | ------ | ----------- |
| BIENVENUE | |  Écran de démarrage  |
| CLIENT | |  Panneau client  |
| EDT | |  Panneau des emplois du temps  |
| AUTH | |  Panneau de connexion administrateur  |
| ADMIN | |  Panneau administrateur  |
| ENSEIGNANT | |  Panneau de gestion des Enseignants  |
| ENSEIGNEMENT | |  Panneau de gestion des Enseignements  |
| SALLE | |  Panneau de gestion des Salles  |
| BOOK | |  Panneau de gestion des Creneau (réservations)  |
| WRITE | |  Panneau de manipulation des données (ajout, suppression, modification, affichage, ... )  |

Enumération qui permet de coder l'affichage (état) courant de l'interface utilisateur ou sa "position".

### typedef EtatAffichage

```c
typedef enum liste_etat_affichage EtatAffichage;
```

## Documentation des fonctions

### fonction decodeMDP()

```c
char * decodeMDP(
    const char * mdp,
    char * dest
)
```

Décrypte le mot de passe passé en paramètre.

**Paramètres**:

* **mdp** Mot de passe crypté.
* **dest** Adresse où sera stocké le mot de passe décrypté.

**Renvoie**: Mot de passe décrypté de type char*.

!> **Précondition**: dest doit être alloué.

?> **Note**: On utilise l'algorithme ROT13 pour l'encodage de nos caractères.

### fonction encodeMDP()

```c
char * encodeMDP(
    char * mdp
)
```

Encrypte le mot de passe passé en paramètre.

**Paramètres**:

* **mdp** Mot de passe.

**Renvoie**: Mot de passe crypté de type char*.

?> **Note**: On utilise l'algorithme ROT13 pour l'encodage de nos caractères.

### fonction controleSerializer()

```c
void controleSerializer(
    Controle C
)
```

imprime sur un fichier du disque (spécifié par Controle) les données courants de l'application sour format JSON

**Paramètres**:

* **C** Référence de Controle

**Voir également**: [json_dump_file](https://jansson.readthedocs.io/en/latest/apiref.html#c.json_dump_file)

### fonction controleParser()

```c
Controle controleParser(
    Controle C,
    json_t * json_controle
)
```

Construit un objet Controle avec les données JSON renvoyé par l'API Jansson.

**Paramètres**:

* **C** Référence de Controle.
* **json_controle** Objet JSON de Controle.

**Renvoie**: Controle avec les données JSON comme attributs.

On accède aux clé-valeurs de "enseignants", "enseignements", "formations", "salles" qui sont tous des tableaux puis on contruit les attributs de Controle en faisant à chaque fois appel aux constructeurs avec les données JSON en paramètres.

### fonction populateFormations()

```c
Formations populateFormations(
    Formations fs
)
```

Ajoute les formations par défaut à la liste des Formations.

**Paramètres**:

* **fs** Référence de Formations.

**Renvoie**: Formations rempli avec les parcours de CUPGE.

### fonction controleClean()

```c
Controle controleClean(
    Controle C
)
```

Construit un objet Controle avec des listes vides et les formations par défaut.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: Controle

### fonction controle()

```c
Controle controle(
    char * cheminData
)
```

Construit un nouvelle objet Controle à partir des données JSON s'il existe.

Constructeur par défaut de l'objet Controle.

### fonction getUserProfile()

```c
char * getUserProfile(
    Controle C
)
```

Accesseur de la représentation en chaîne de caractère du Profil courant.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: Profil de l'utilisateur courant de type char*.

### fonction afficherProfil()

```c
int afficherProfil(
    char * profil
)
```

Imprime sur stdout le profil de l'utilisateur connecté

**Paramètres**:

* **profil** Profile de l'utilisateur.

**Renvoie**: 1

### fonction afficherPanneauBienvenue()

```c
int afficherPanneauBienvenue()
```

Affiche l'interface de présentation de l'application.

**Renvoie**: int

### fonction afficherPanneauSortie()

```c
int afficherPanneauSortie()
```

Affiche l'interface de sortie de l'application.

**Renvoie**: int

### fonction afficherPanneauClient()

```c
int afficherPanneauClient()
```

Affiche l'interface de sélection d'emploi du temps.

**Renvoie**: int

### fonction afficherEDTEnseignant()

```c
void afficherEDTEnseignant(
    Controle C,
    Enseignant e
)
```

Affiche l'emploi du temps pour un enseignant.

**Paramètres**:

* **C** Référence de Controle.
* **e** Enseignant à afficher.

### fonction afficherEDTFormation()

```c
void afficherEDTFormation(
    Controle C,
    char * formation
)
```

Affiche l'emploi du temps pour une formation.

**Paramètres**:

* **C** Référence de Controle.
* **formation** Formation à afficher.

### fonction afficherPanneauEDTEnseignants()

```c
int afficherPanneauEDTEnseignants(
    Controle C
)
```

Affiche l'emploi du temps par enseignant.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: -1 pour revenir en arrière.

### fonction afficherPanneauEDTFormations()

```c
int afficherPanneauEDTFormations(
    Controle C
)
```

Affiche l'emploi du temps par formation.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: -1 pour revenir en arrière.

### fonction afficherPanneauEDTSalles()

```c
int afficherPanneauEDTSalles(
    Controle C
)
```

Affiche l'emploi du temps par salle.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: -1 pour revenir en arrière.

### fonction afficherPanneauAdmin()

```c
int afficherPanneauAdmin()
```

Affiche l'interface de gestion général.

**Renvoie**: 0 pour quitter, 1 à 5 sinon.

### fonction afficherPanneauGestionEnseignants()

```c
int afficherPanneauGestionEnseignants()
```

Affiche l'interface de gestion des enseignants.

**Renvoie**: 0 pour quitter, 1 à 4 sinon.

### fonction afficherPanneauAjouterEnseignants()

```c
int afficherPanneauAjouterEnseignants(
    Controle C
)
```

Affiche l'interface d'ajout d'un enseignant.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière.

### fonction afficherPanneauModifierEnseignants()

```c
int afficherPanneauModifierEnseignants(
    Controle C
)
```

Affiche l'interface de modification d'un enseignant.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière

### fonction afficherPanneauSupprimerEnseignants()

```c
int afficherPanneauSupprimerEnseignants(
    Controle C
)
```

Affiche l'interface de modification d'un enseignant.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière

### fonction afficherPanneauListeEnseignants()

```c
int afficherPanneauListeEnseignants(
    Controle C
)
```

Affiche la liste des enseignants.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: -1 pour revenir en arrière.

### fonction afficherPanneauGestionEnseignements()

```c
int afficherPanneauGestionEnseignements()
```

Affiche l'interface de gestion d'un enseignement.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 à 4 sinon.

### fonction afficherPanneauAjouterEnseignements()

```c
int afficherPanneauAjouterEnseignements(
    Controle C
)
```

Affiche l'interface d'ajout d'un enseignement.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière

### fonction afficherPanneauModifierEnseignements()

```c
int afficherPanneauModifierEnseignements(
    Controle C
)
```

Affiche l'interface de modification d'un enseignement.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière

### fonction afficherPanneauSupprimerEnseignements()

```c
int afficherPanneauSupprimerEnseignements(
    Controle C
)
```

Affiche l'interface de suppression d'un enseignement.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière

### fonction afficherPanneauListeEnseignements()

```c
int afficherPanneauListeEnseignements(
    Controle C
)
```

Affiche la liste des enseignements.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: -1 pour revenir en arrière.

### fonction afficherPanneauGestionSalles()

```c
int afficherPanneauGestionSalles()
```

Affiche l'interface de gestion d'une salle.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 à 3 sinon.

### fonction afficherPanneauAjouterSalles()

```c
int afficherPanneauAjouterSalles(
    Controle C
)
```

Affiche l'interface d'ajout d'une salle.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière

### fonction afficherPanneauModifierSalles()

```c
int afficherPanneauModifierSalles(
    Controle C
)
```

Affiche l'interface de modification d'une salle.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière

### fonction afficherPanneauListeSalles()

```c
int afficherPanneauListeSalles(
    Controle C
)
```

Affiche la liste des salles.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: -1 pour revenir en arrière.

### fonction afficherPanneauGestionCreneaux()

```c
int afficherPanneauGestionCreneaux()
```

Affiche l'interface de gestion d'un créneau ou réservation.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 à 4 sinon.

### fonction afficherPanneauAjouterCreneaux()

```c
int afficherPanneauAjouterCreneaux(
    Controle C
)
```

Affiche l'interface d'ajout d'un créneau ou réservation.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière

### fonction afficherPanneauSupprimerCreneaux()

```c
int afficherPanneauSupprimerCreneaux(
    Controle C
)
```

Affiche l'interface de suppression d'un créneau ou réservation.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière

### fonction afficherPanneauModifierCreneaux()

```c
int afficherPanneauModifierCreneaux(
    Controle C
)
```

Affiche l'interface de modification d'un créneau ou réservation.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière

### fonction afficherPanneauListeCreneaux()

```c
int afficherPanneauListeCreneaux(
    Controle C
)
```

Affiche la liste des créneaux, par formation.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: -1 pour revenir en arrière.

### fonction afficherPanneauAuthentificationMDP()

```c
int afficherPanneauAuthentificationMDP(
    Controle C
)
```

Affiche l'interface de vérification de mot de passe ou authentification.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 sinon.

### fonction afficherPanneauModifierMDP()

```c
int afficherPanneauModifierMDP(
    Controle C
)
```

Affiche l'interface de modification d'un mot de passe.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, 1 ou -1 pour revenir en arrière

### fonction afficherProchainPanneau()

```c
int afficherProchainPanneau(
    Controle C
)
```

Gère les panneaux à afficher en fonction du choix de l'utilisateur et du panneau courant.

**Paramètres**:

* **C** Référence de Controle.

**Renvoie**: 0 pour quitter, >0 pour passer à un autre panneau.

### fonction run()

```c
int run(
    Controle C
)
```

Boucle principale de l'interface de Controle.

Affiche d'abord le panneau Bienvenue à l'initialisation puis exécute la boucle.

[afficherProchainPanneau](/Files/controle_8c.md#fonction-afficherprochainpanneau)

## Code source

```c

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "controle.h"

#ifdef DEBUG
#include "tests.h"
#endif

typedef enum liste_etat_affichage
{
    BIENVENUE,
    CLIENT,
    EDT,
    AUTH,
    ADMIN,
    ENSEIGNANT,
    ENSEIGNEMENT,
    SALLE,
    BOOK,
    WRITE,
} EtatAffichage;

struct s_controle {
    bool isAdmin;
    char MDP[BUFFER_SIZE];
    Enseignants enseignants;
    Enseignements enseignements;
    Salles salles;
    Formations formations;
    EtatAffichage* panneauCourant;
    char* cheminData;
    int panneauSuivant;
};

/************************************************************\
*                Opérateurs du Mot De Passe                  *
\************************************************************/

char* decodeMDP(const char* mdp, char* dest) {
    strcpy(dest, mdp);
    char* courant = dest;
    while (*courant != '\0') {
        // on fait l'inverse de encodeMDP
        if ('a' <= *courant && *courant <= 'z') {
            if ('a' <= *courant && *courant <= 'm') {
                *courant += 13;
            }
            else {
                *courant -= 13;
            }
        }
        else if ('A' <= *courant && *courant <= 'Z') {
            if ('A' <= *courant && *courant <= 'M') {
                *courant += 13;
            }
            else {
                *courant -= 13;
            }
        }
        courant++;
    }
    return dest;
}

char* encodeMDP(char* mdp) {
    char* courant = mdp;
    while (*courant != '\0') {
        // On incrémente seulement les lettres de l'alphabet
        if ('a' <= *courant && *courant <= 'z') {
            *courant = (((*courant - 'a') + 13) % 26) + 'a';
        }
        else if ('A' <= *courant && *courant <= 'Z') {
            *courant = (((*courant - 'A') + 13) % 26) + 'A';
        }
        courant++;
    }
    return mdp;
}

/************************************************************\
*               Manipulation du fichier JSON                 *
\************************************************************/

void controleSerializer(Controle C) {
    json_t* root = json_object();
    json_object_set_new(root, "enseignants", getJsonEnseignants(C->enseignants));
    json_object_set_new(root, "enseignements", getJsonEnseignements(C->enseignements));
    json_object_set_new(root, "salles", getJsonSalles(C->salles));
    json_object_set_new(root, "formations", getJsonFormations(C->formations));
    json_object_set_new(root, "password", json_string(encodeMDP(C->MDP)));
    println("Enregistrement des données utilisateurs...");
    json_dump_file(root, C->cheminData, 1);
}

Controle controleParser(Controle C, json_t* json_controle) {
    json_t* enseignants = json_object_get(json_controle, "enseignants");
    json_t* enseignements = json_object_get(json_controle, "enseignements");
    json_t* formations = json_object_get(json_controle, "formations");
    json_t* salles = json_object_get(json_controle, "salles");
    json_t* password = json_object_get(json_controle, "password");
    assert(json_is_array(enseignements)
        && json_is_array(formations)
        && json_is_array(salles)
        && json_is_array(formations)
        && json_is_array(enseignants)
        && json_is_string(password));
    C->enseignants = enseignantsParser(enseignants);
    C->enseignements = enseignementsParser(enseignements);
    C->salles = sallesParser(salles);
    C->formations = formationsParser(formations);
    decodeMDP(json_string_value(password), C->MDP);
    return C;
}


/************************************************************\
*                Constructeurs de Controle                   *
\************************************************************/

Formations populateFormations(Formations fs) {
    ajouterFs(fs, formation("CUPGE Chimie"));
    ajouterFs(fs, formation("CUPGE Informatique"));
    ajouterFs(fs, formation("CUPGE Physique"));
}

Controle controleClean(Controle C) {
    C->enseignants = enseignants();
    C->enseignements = enseignements();
    C->salles = salles();
    C->formations = formations(3);
    strcpy(C->MDP, "mdp");
    populateFormations(C->formations);
    return C;
}

Controle controle(char* cheminData) {
    Controle C = (Controle)malloc(sizeof(struct s_controle));
    json_t* json;
    json_error_t error;
    json = json_load_file(cheminData, 0, &error);
    if (!json) {
        display(
            "%s non trouvé ou inaccessible\n"
            "Initialisation de l'application avec les données par défaut",
            cheminData
        );
        controleClean(C);
    }
    else {
        display(
            "Initialisation de l'application avec les données de %s\n"
            "Note: Si les données contenues dans %s ne respectent pas les clés-valeurs\n"
            "attendues, l'application se fermera automatiquement avec une erreur.",
            cheminData, cheminData
        );
        controleParser(C, json);
    }
    C->cheminData = cheminData;
    C->isAdmin = false;
    C->panneauCourant = (EtatAffichage*)malloc(sizeof(EtatAffichage));
    *(C->panneauCourant) = BIENVENUE;

    return C;
}


/************************************************************\
*             Opérateurs du profil utilisateur               *
\************************************************************/

char* getUserProfile(Controle C) {
    if (C->isAdmin) {
        return "Administrateur";
    }
    return "Client";
}

int afficherProfil(char* profil) {
    display("Vous êtes connecté en tant que : %s", profil);
    return 1;
}


/************************************************************\
*                  Panneaux Entrée/Sortie                    *
\************************************************************/

int afficherPanneauBienvenue() {
    puts("");
    println(
        "******************************\n"
        "*     Bienvenue dans BAC     *\n"
        "******************************"
    );
    return getChoiceInput(
        "1) Se connecter en tant que client\n"
        "2) Se connecter en tant qu'administrateur",
        2
    );
}

int afficherPanneauSortie() {
    println(
        "Merci d'avoir visité BAC\n"
        "A Bientôt !"
    );
    return getAnyInput();
}


/************************************************************\
*                     Panneaux Clients                       *
\************************************************************/

int afficherPanneauClient() {
    println(
        "************ Menu des clients "
        "************"
    );
    return getChoiceInput(
        "1) Consulter l'emploi du temps par enseignant\n"
        "2) Consulter l'emploi du temps par formation\n"
        "3) Consulter l'emploi du temps par salle",
        3
    );
}

/************************************************************\
*                 Panneaux Emploi Du Temps                   *
\************************************************************/

void afficherEDTEnseignant(Controle C, Enseignant e) {
    printf("---------------------\n");
    printf("EDT de l'Enseignant : ");
    afficheEnseignant(e);
    println("---------------------");
    for (int i = 0; i < sizeSalles(C->salles); i++) {
        Salle courant = getSalleByIndice(C->salles, i);
        for (int j = 8; j < 20; j++) {
            Creneau c = getSalleC(courant)[j];
            if (c != NULL) {
                if (equalsEnseignant(getCreneauE(c), e)
                    && getDebut(getCreneauH(c)) == j) {
                    // ? on affiche seulement la première occurrence
                    // ? du Creneau (marqué par le début de Horaire)
                    printf(
                        "Salle %s\n"
                        "De ",
                        getCreneauS(c)
                    );
                    afficheHoraire(getCreneauH(c));
                    display("%s, %s", getCreneauENS(c), getCreneauF(c));
                }
            }
        }
    }
}

void afficherEDTFormation(Controle C, char* formation) {
    display(
        "---------------------\n"
        "EDT de la Formation : %s\n"
        "---------------------",
        formation
    );
    for (int i = 0; i < sizeSalles(C->salles); i++) {
        Salle courant = getSalleByIndice(C->salles, i);
        for (int j = 8; j < 20; j++) {
            Creneau c = getSalleC(courant)[j];
            if (c != NULL) {
                if (strcmp(getCreneauF(c), formation) == 0
                    && getDebut(getCreneauH(c)) == j) {
                    // ? on affiche seulement la première occurrence
                    // ? du Creneau (marqué par le début de Horaire)
                    printf(
                        "Salle %s\n"
                        "De ",
                        getCreneauS(c)
                    );
                    afficheHoraire(getCreneauH(c));
                    printf("%s\n", getCreneauENS(c));
                    afficheEnseignant(getCreneauE(c));
                }
            }
        }
    }
}

int afficherPanneauEDTEnseignants(Controle C) {
    println(
        "************ EDT par enseignant "
        "************"
    );
    for (int i = 0; i < sizeEnseignants(C->enseignants); i++) {
        afficherEDTEnseignant(C, getEnseignantByIndice(C->enseignants, i));
    }
    return -1;
}

int afficherPanneauEDTFormations(Controle C) {
    println(
        "************ EDT par formation "
        "************"
    );
    for (int i = 0; i < 3; i++) {
        afficherEDTFormation(C, getFormationN(getFormationByIndice(C->formations, i)));
    }
    return -1;
}

int afficherPanneauEDTSalles(Controle C) {
    println(
        "************ EDT par salle "
        "************"
    );
    afficherSalles(C->salles);
    return -1;
}


/************************************************************\
*                 Panneaux Administrateurs                   *
\************************************************************/

int afficherPanneauAdmin() {
    println(
        "************ Menu "
        "************"
    );
    return getChoiceInput(
        "1) Gestion des enseignants\n"
        "2) Gestion des enseignements\n"
        "3) Gestion des salles\n"
        "4) Gestion des réservations\n"
        "5) Changer le mot de passe",
        5
    );
}


/************************************************************\
*                   Panneaux Enseignants                     *
\************************************************************/

int afficherPanneauGestionEnseignants() {
    println(
        "************ Gestion des enseignants "
        "************"
    );
    return getChoiceInput(
        "1) Ajouter un enseignant\n"
        "2) Modifier un enseignant\n"
        "3) Supprimer un enseignant\n"
        "4) Afficher la liste des enseignants",
        4
    );
}

int afficherPanneauAjouterEnseignants(Controle C) {
    int userChoice = 1;
    Enseignant e = enseignant();
    bool isIn = true;
    while (userChoice == 1 && isIn) {
        getUserInput("Saisissez les informations pour créer un enseignant", "Nom", getNom(e));
        getUserInput("", "Prenom", getPrenom(e));
        isIn = appartientEnseignants(C->enseignants, e);
        if (isIn) {
            userChoice = getRetryInput("un enseignant");
        }
        else {
            ajouterEs(C->enseignants, e);
            printf("Ajout de l'enseignant ");
            afficheEnseignant(e);
            println("Terminé.");
        }
    }
    return userChoice;
}

int afficherPanneauModifierEnseignants(Controle C) {
    int userChoice = 1;
    bool isIn = true;
    Enseignant e;
    char newValeur[BUFFER_SIZE];
    while (userChoice == 1 && isIn) {
        println("Sélectionnez l'enseignant à modifier par son numéro");
        afficherEnseignants(C->enseignants, true);
        // offset from 1 based input count to 0 based list access
        userChoice = getChoiceInput("", sizeEnseignants(C->enseignants)) - 1;
        if (userChoice >= 0) {
            e = getEnseignantByIndice(C->enseignants, userChoice);
            userChoice = getChoiceInput(
                "Sélectionnez la valeur à modifier\n\n"
                "1) Nom\n"
                "2) Prénom",
                2
            );
            if (userChoice > 0) {
                getUserInput("", "Nouvelle valeur", newValeur);
                if (userChoice == 1) {
                    isIn = appartientEnseignants(C->enseignants, enseignantCopie(newValeur, getPrenom(e)));
                    if (isIn) {
                        userChoice = getRetryInput("un enseignant");
                    }
                    else {
                        setNom(e, newValeur);
                        printf("Modification de l'enseignant par ");
                        afficheEnseignant(e);
                        println("Terminé.");
                    }
                }
                else if (userChoice == 2) {
                    isIn = appartientEnseignants(C->enseignants, enseignantCopie(getNom(e), newValeur));
                    if (isIn) {
                        userChoice = getRetryInput("un enseignant");
                    }
                    else {
                        setPrenom(e, newValeur);
                        printf("Modification de l'enseignant par ");
                        afficheEnseignant(e);
                        println("Terminé.");
                    }
                }
            }
            else {
                userChoice = getCancelInput();
            }
        }
    }
    return userChoice;
}

int afficherPanneauSupprimerEnseignants(Controle C) {
    int userChoice = 1;
    println("Sélectionnez l'enseignant à supprimer par son numéro");
    afficherEnseignants(C->enseignants, true);
    // offset from 1 based input count to 0 based list access
    int i = getChoiceInput("", sizeEnseignants(C->enseignants)) - 1;
    if (i >= 0) {
        printf("Suppression de l'enseignant ");
        afficheEnseignant(getEnseignantByIndice(C->enseignants, i));
        supprimerEs(C->enseignants, getEnseignantByIndice(C->enseignants, i));
        println("Terminé");
    }
    return userChoice;
}

int afficherPanneauListeEnseignants(Controle C) {
    println(
        "************ Liste des enseignants "
        "************"
    );
    afficherEnseignants(C->enseignants, false);
    puts("");
    return -1;
}


/************************************************************\
*                  Panneaux Enseignements                    *
\************************************************************/

int afficherPanneauGestionEnseignements() {
    println(
        "************ Gestion des enseignements "
        "************"
    );
    return getChoiceInput(
        "1) Ajouter un enseignement\n"
        "2) Modifier un enseignement\n"
        "3) Supprimer un enseignement\n"
        "4) Afficher la liste des enseignements",
        4
    );
}

int afficherPanneauAjouterEnseignements(Controle C) {
    int userChoice = 1;
    bool isIn = true;
    char nom[BUFFER_SIZE];
    while (userChoice == 1 && isIn) {
        getUserInput("Saisissez les informations pour créer un enseignement", "Nom", nom);
        isIn = appartientEnseignements(C->enseignements, nom);
        if (isIn) {
            userChoice = getRetryInput("un enseignement");
        }
        else {
            ajouterEns(C->enseignements, nom);
            display("Ajout de l'enseignement %s\n"
                "Terminé.",
                nom);
        }
    }
    return userChoice;
}

int afficherPanneauModifierEnseignements(Controle C) {
    int userChoice = 1;
    bool isIn = true;
    int i;
    char newValeur[BUFFER_SIZE];
    while (userChoice == 1 && isIn) {
        println("Sélectionnez le nom de l'enseignement à modifier par son numéro");
        afficherEnseignements(C->enseignements, true);
        // offset from 1 based input count to 0 based list access
        i = getChoiceInput("", sizeEnseignements(C->enseignements)) - 1;
        if (i >= 0) {
            getUserInput("", "Nouvelle valeur", newValeur);
            isIn = appartientEnseignements(C->enseignements, newValeur);
            if (isIn) {
                userChoice = getRetryInput("un enseignement");
            }
            else {
                supprimerEns(C->enseignements, getEnseignementByIndice(C->enseignements, i));
                ajouterEns(C->enseignements, newValeur);
                display("Modification de l'enseignement par %s\n"
                    "Terminé.",
                    getEnseignementByIndice(C->enseignements, 0));
            }
        }
        else {
            userChoice = getCancelInput();
        }
    }
    return userChoice;
}

int afficherPanneauSupprimerEnseignements(Controle C) {
    int userChoice = 1;
    println("Sélectionnez l'enseignement à supprimer par son numéro");
    afficherEnseignements(C->enseignements, true);
    // offset from 1 based input count to 0 based list access
    int i = getChoiceInput("", sizeEnseignements(C->enseignements)) - 1;
    if (i >= 0) {
        display("Suppression de l'enseignement %s\n"
            "Terminé.",
            getEnseignementByIndice(C->enseignements, i));
        supprimerEns(C->enseignements, getEnseignementByIndice(C->enseignements, i));
    }
    return userChoice;
}

int afficherPanneauListeEnseignements(Controle C) {
    println(
        "************ Liste des enseignements "
        "************"
    );
    afficherEnseignements(C->enseignements, false);
    puts("");
    return -1;
}


/************************************************************\
*                      Panneaux Salles                       *
\************************************************************/

int afficherPanneauGestionSalles() {
    println(
        "************ Gestion des salles "
        "************"
    );
    return getChoiceInput(
        "1) Ajouter une salle\n"
        "2) Modifier une salle\n"
        "3) Afficher la liste des salles",
        3
    );
}

int afficherPanneauAjouterSalles(Controle C) {
    int userChoice = 1;
    bool isIn = true;
    Salle s = salle();
    while (userChoice == 1 && isIn) {
        char nom[BUFFER_SIZE];
        getUserInput("Saisissez les informations pour créer une salle", "Nom", getSalleN(s));
        isIn = appartientSalles(C->salles, s);
        if (isIn) {
            userChoice = getRetryInput("une salle");
        }
        else {
            ajouterSs(C->salles, s);
            display("Ajout de la salle %s\n"
                "Terminé.",
                getSalleN(s));
        }
    }
    return userChoice;
}

int afficherPanneauModifierSalles(Controle C) {
    int userChoice = 1;
    bool isIn = true;
    int i;
    char newValeur[BUFFER_SIZE];
    while (userChoice == 1 && isIn) {
        println("Sélectionnez le nom de la salle à modifier par son numéro");
        afficherSallesN(C->salles, true);
        // offset from 1 based input count to 0 based list access
        i = getChoiceInput("", sizeSalles(C->salles)) - 1;
        if (i >= 0) {
            getUserInput("", "Nouvelle valeur", newValeur);
            isIn = appartientSalles(C->salles, salleCopie(newValeur));
            if (isIn) {
                userChoice = getRetryInput("une salle");
            }
            else {
                setSalleN(getSalleByIndice(C->salles, i), newValeur);
                display("Modification de la salle par %s\n"
                    "Terminé.",
                    getSalleN(getSalleByIndice(C->salles, i)));
            }
        }
        else {
            userChoice = getCancelInput();
        }
    }
    return userChoice;
}

int afficherPanneauListeSalles(Controle C) {
    println("************ Liste des salles "
        "************");
    afficherSallesN(C->salles, false);
    puts("");
    return 1;

}


/************************************************************\
*                   Panneaux Réservations                    *
\************************************************************/

int afficherPanneauGestionCreneaux() {
    println(
        "************ Gestion des réservations "
        "************"
    );
    return getChoiceInput(
        "1) Réserver un créneau\n"
        "2) Annuler une réservation\n"
        "3) Modifier une réservation\n"
        "4) Afficher la liste des salles réservées par créneaux",
        4
    );
}

int afficherPanneauAjouterCreneaux(Controle C) {
    int userChoice = 1;
    char* ens;
    Enseignant e;
    Formation f;
    Salle s;
    Horaire h;
    Creneau c;
    bool isValid = false;
    while (userChoice == 1 && !isValid) {
        println("Sélectionnez un enseignement :");
        afficherEnseignements(C->enseignements, true);
        // offset from 1 based input count to 0 based list access
        userChoice = getChoiceInput("", sizeEnseignements(C->enseignements)) - 1;
        if (userChoice >= 0) {
            ens = getEnseignementByIndice(C->enseignements, userChoice);
            println("Sélectionnez l'enseignant intervenant :");
            afficherEnseignants(C->enseignants, true);
            userChoice = getChoiceInput("", sizeEnseignants(C->enseignants)) - 1;
            if (userChoice >= 0) {
                e = getEnseignantByIndice(C->enseignants, userChoice);
                println("Sélectionnez la formation concernée :");
                afficherFormationsN(C->formations, true);
                userChoice = getChoiceInput("", sizeFormations(C->formations)) - 1;
                if (userChoice >= 0) {
                    f = getFormationByIndice(C->formations, userChoice);
                    println("Sélectionnez la salle à reserver :");
                    afficherSallesN(C->salles, true);
                    userChoice = getChoiceInput("", sizeSalles(C->salles)) - 1;
                    if (userChoice >= 0) {
                        s = getSalleByIndice(C->salles, userChoice);
                        afficherEDTFormation(C, getFormationN(f));
                        afficheSalle(s);
                        println(
                            "Sélectionnez un horaire de réservation\n"
                            "L'emploi du temps de la formation et les créneaux\n"
                            "de la salle vous sont affichés pour vous aider à choisir\n"
                            "un créneau valide"
                        );
                        int debut = getIntervalInput("Indiquez l'heure de début de votre enseignement \n"
                            "(qui doit être comprise entre 8 et 19)", 8, 19);
                        printf("Indiquez l'heure de fin de votre enseignement \n"
                            "(qui doit être comprise entre %d et 20)", debut + 1
                        );
                        int fin = getIntervalInput(
                            "", debut + 1, 20);
                        h = horaire(debut, fin);
                        isValid = isFreeFormation(f, h) && isFreeSalle(s, h);
                        if (!isValid) {
                            if (!isFreeFormation(f, h)) {
                                println("Désolé, la formation assiste déjà à un autre créneau à cette horaire");
                                userChoice = getChoiceInput("1) Réessayer", 1);
                                if (userChoice == 0) {
                                    userChoice = getCancelInput();
                                }
                            }
                            if (!isFreeSalle(s, h)) {
                                println("Désolé, la salle est déjà réservé pour un autre créneau à cette horaire");
                                userChoice = getChoiceInput("1) Réessayer", 1);
                                if (userChoice == 0) {
                                    userChoice = getCancelInput();
                                }
                            }
                        }
                        else {
                            Creneau c = creneau(e, h, ens, getFormationN(f), getSalleN(s));
                            ajouterSalleC(s, c);
                            ajouterFormationC(f, c);
                            printf("Ajout du créneau\n");
                            afficheCreneau(c);
                            println("Terminé.");
                            userChoice = 1;
                        }
                    }
                }
            }
        }
        if (userChoice < 0) {
            userChoice = getCancelInput();
        }
    }
    return userChoice;

}

int afficherPanneauSupprimerCreneaux(Controle C) {
    int userChoice = 1;
    Formation f;
    Creneau c;
    println("Sélectionnez une formation :");
    afficherFormationsN(C->formations, true);
    int i = getChoiceInput("", sizeFormations(C->formations)) - 1;
    if (i >= 0) {
        f = getFormationByIndice(C->formations, i);
        println("Sélectionnez le créneau à supprimer par son numéro");
        afficheFormation(f, true);
        i = getChoiceInput("", sizeFormationC(f)) - 1;
        if (i >= 0) {
            c = getFormationCByIndice(f, i);
            printf("Suppression du creneau\n");
            afficheCreneau(c);
            supprimerSalleH(getSalleByNom(C->salles, getCreneauS(c)), getCreneauH(c));
            supprimerFormationH(f, getCreneauH(c));
            println("Terminé.");
        }
    }
    return userChoice;
}

int afficherPanneauModifierCreneaux(Controle C) {
    int userChoice = 1;
    Formation f;
    Horaire h;
    Enseignant e;
    Creneau c;
    char* newValeur[BUFFER_SIZE];
    bool isValid = false;
    println("Sélectionnez une formation :");
    afficherFormationsN(C->formations, true);
    int i = getChoiceInput("", sizeFormations(C->formations)) - 1;
    if (i >= 0) {
        f = getFormationByIndice(C->formations, i);
        println("Sélectionnez le créneau à modifier par son numéro");
        afficheFormation(f, true);
        i = getChoiceInput("", sizeFormationC(f)) - 1;
        if (i >= 0) {
            c = getFormationCByIndice(f, i);
            userChoice = getChoiceInput(
                "Sélectionnez la valeur à modifier\n\n"
                "1) Enseignement\n"
                "2) Enseignant\n",
                2
            );
            if (userChoice > 0) {
                if (userChoice == 1) {
                    println("Sélectionnez un enseignement :");
                    afficherEnseignements(C->enseignements, true);
                    // offset from 1 based input count to 0 based list access
                    userChoice = getChoiceInput("", sizeEnseignements(C->enseignements)) - 1;
                    if (userChoice >= 0) {
                        setCreneauENS(getEnseignementByIndice(C->enseignements, userChoice), c);
                        printf("Modification du créneau par ");
                        afficheCreneau(c);
                        println("Terminé.");
                        userChoice = 1;
                    }
                }
                else if (userChoice == 2) {
                    println("Sélectionnez un enseignant :");
                    afficherEnseignants(C->enseignants, true);
                    userChoice = getChoiceInput("", sizeEnseignants(C->enseignants)) - 1;
                    if (userChoice >= 0) {
                        setCreneauE(getEnseignantByIndice(C->enseignants, userChoice), c);
                        printf("Modification du créneau par ");
                        afficheCreneau(c);
                        println("Terminé.");
                        userChoice = 1;
                    }
                }
            }
            else {
                userChoice = getCancelInput();
            }
        }
    }
    return userChoice;
}

int afficherPanneauListeCreneaux(Controle C) {
    println("************ Liste des salles réservées "
        "************");
    afficherFormations(C->formations);
    return 1;
}


/************************************************************\
*                   Panneaux Mot De Passe                    *
\************************************************************/

int afficherPanneauAuthentificationMDP(Controle C) {
    println(
        "************ Panneau de contrôle administrateur "
        "************"
    );
    int userChoice = 1;
    char mdpInput[BUFFER_SIZE];
    while (userChoice == 1 && !C->isAdmin) {
        getUserInput("Veuillez vous connecter pour continuer", "Mot de passe (\"mdp\" par défaut)", mdpInput);
        if (strcmp(mdpInput, C->MDP) == 0) {
            C->isAdmin = true;
        }
        else {
            println("Mot de passe incorrect.");
            userChoice = getChoiceInput("1) Réessayer", 1);
        }
    }
    return userChoice;
}

int afficherPanneauModifierMDP(Controle C) {
    int userChoice = 1;
    getUserInput("", "Nouvelle valeur", C->MDP);
    println("Modification du mot de passe terminé.");
    return userChoice;

}


/************************************************************\
*             Gestionnaire de choix utilisateur              *
\************************************************************/

int afficherProchainPanneau(Controle C) {
    switch (*(C->panneauCourant))
    {
    case BIENVENUE:
        switch (C->panneauSuivant)
        {
        case 1:
            *(C->panneauCourant) = CLIENT;
            afficherProfil(getUserProfile(C));
            return afficherPanneauClient();
        case 2:
            *(C->panneauCourant) = AUTH;
            return afficherPanneauAuthentificationMDP(C);
        default:
            break;
        }
        break;
    case CLIENT:
        *(C->panneauCourant) = EDT;
        switch (C->panneauSuivant)
        {
        case 1:
            return afficherPanneauEDTEnseignants(C);
        case 2:
            return afficherPanneauEDTFormations(C);
        case 3:
            return afficherPanneauEDTSalles(C);
        default:
            break;
        }
        break;
    case EDT:
        *(C->panneauCourant) = CLIENT;
        return afficherPanneauClient();
    case AUTH:
        *(C->panneauCourant) = ADMIN;
        switch (C->panneauSuivant)
        {
        case 1:
            afficherProfil(getUserProfile(C));
            return afficherPanneauAdmin();
        default:
            break;
        }
        break;
    case ADMIN:
        switch (C->panneauSuivant)
        {
        case 1:
            *(C->panneauCourant) = ENSEIGNANT;
            return afficherPanneauGestionEnseignants();
        case 2:
            *(C->panneauCourant) = ENSEIGNEMENT;
            return afficherPanneauGestionEnseignements();
        case 3:
            *(C->panneauCourant) = SALLE;
            return afficherPanneauGestionSalles();
        case 4:
            *(C->panneauCourant) = BOOK;
            return afficherPanneauGestionCreneaux();
        case 5:
            *(C->panneauCourant) = WRITE;
            return afficherPanneauModifierMDP(C);
        default:
            break;
        }
        break;
    case ENSEIGNANT:
        *(C->panneauCourant) = WRITE;
        switch (C->panneauSuivant)
        {
        case 1:
            return afficherPanneauAjouterEnseignants(C);
        case 2:
            return afficherPanneauModifierEnseignants(C);
        case 3:
            return afficherPanneauSupprimerEnseignants(C);
        case 4:
            return afficherPanneauListeEnseignants(C);
        default:
            break;
        }
        break;
    case ENSEIGNEMENT:
        *(C->panneauCourant) = WRITE;
        switch (C->panneauSuivant)
        {
        case 1:
            return afficherPanneauAjouterEnseignements(C);
        case 2:
            return afficherPanneauModifierEnseignements(C);
        case 3:
            return afficherPanneauSupprimerEnseignements(C);
        case 4:
            return afficherPanneauListeEnseignements(C);
        default:
            break;
        }
        break;
    case SALLE:
        *(C->panneauCourant) = WRITE;
        switch (C->panneauSuivant)
        {
        case 1:
            return afficherPanneauAjouterSalles(C);
        case 2:
            return afficherPanneauModifierSalles(C);
        case 3:
            return afficherPanneauListeSalles(C);
        default:
            break;
        }
        break;
    case BOOK:
        *(C->panneauCourant) = WRITE;
        switch (C->panneauSuivant)
        {
        case 1:
            return afficherPanneauAjouterCreneaux(C);
        case 2:
            return afficherPanneauSupprimerCreneaux(C);
        case 3:
            return afficherPanneauModifierCreneaux(C);
        case 4:
            return afficherPanneauListeCreneaux(C);
        default:
            break;
        }
        break;
    case WRITE:
        *(C->panneauCourant) = ADMIN;
        return afficherPanneauAdmin();
    default:
        break;
    }
    return 0;
}


/************************************************************\
*                      Control loop                          *
\************************************************************/

int run(Controle C) {
    C->panneauSuivant = afficherPanneauBienvenue();
    while (C->panneauSuivant != 0) {
        C->panneauSuivant = afficherProchainPanneau(C);
    }
    controleSerializer(C);
    return afficherPanneauSortie();
}

#ifdef TEST

int main() {

    // init

    // testing

    return 0;
}

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
