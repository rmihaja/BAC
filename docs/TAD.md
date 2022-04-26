---
title: 'TAD'
export_on_save:
    puppeteer: true
---

# Déclaration des Types Abstraits de Données

## Types singuliers

### Enseignant

- Sorte : $E$
- Utilise : $\Sigma^\star$
- Opérateurs :
    - constructeur :
        $$
            \begin{align*}
                \operatorname{enseignant} \colon \Sigma^\star \times \Sigma^\star & \longrightarrow E \\
                (nom, matiere) & \longmapsto \operatorname{enseignant}(nom, matiere)
            \end{align*}
        $$
    - génériques :
        - $\operatorname{getNom} \colon E \longrightarrow \Sigma^\star$
        - $\operatorname{getMatiere} \colon E \longrightarrow \Sigma^\star$
        - $\operatorname{setNom} \colon E \times \Sigma^\star \longrightarrow E$
        - $\operatorname{setMatiere} \colon E \times \Sigma^\star \longrightarrow E$
        - $\operatorname{toStringEnseignant} \colon E \longrightarrow \Sigma^\star$

### Horaire

- Sorte : $H$
- Utilise : $\N$
- Opérateurs :
    - constructeur :
        $$
            \begin{align*}
                \operatorname{horaire} \colon \llbracket 0, 24 \rrbracket \times \llbracket 0, 24 \rrbracket & \longrightarrow H \\
                (debut, fin) & \longmapsto \operatorname{horaire}(debut, fin)
            \end{align*}
        $$
    - génériques :
        - $\operatorname{getDebut} \colon H \longrightarrow \Sigma^\star$
        - $\operatorname{getFin} \colon H \longrightarrow \Sigma^\star$
        - $\operatorname{setDebut} \colon H \times \llbracket 0, 24 \rrbracket \longrightarrow H$
        - $\operatorname{setFin} \colon H \times \llbracket 0, 24 \rrbracket \longrightarrow H$
        - $\operatorname{duree} \colon H \longrightarrow \llbracket 0, 24 \rrbracket $
        - $\operatorname{toStringHoraire} \colon H \longrightarrow \Sigma^\star$

### Creneau

- Sorte : $C$
- Utilise : $E, H, F, \Sigma^\star$
- Opérateurs :
    - constructeur :
        $$
            \begin{align*}
                \operatorname{creneau} \colon E \times H \times \Sigma^\star \times \Sigma^\star & \longrightarrow C \\
                (enseignant, horaire, formation, salle) & \longmapsto \operatorname{creneau}(enseignant, horaire, formation, salle)
            \end{align*}
        $$
    - génériques :
        - $\operatorname{setCreneau} \colon C \times E \times H \times \Sigma^\star \times \Sigma^\star \longrightarrow C$
        - $\operatorname{getEnseignant} \colon C \longrightarrow E$
        - $\operatorname{getHoraire} \colon C \longrightarrow H$
        - $\operatorname{getFormation} \colon C \longrightarrow \Sigma^\star$
        - $\operatorname{getSalleCreneau} \colon C \longrightarrow \Sigma^\star$
        - $\operatorname{toStringCreneau} \colon C \longrightarrow \Sigma^\star$

### Salle

- Sorte : $S$
- Utilise : $C^\N \coloneqq \text{tableau de créneau}, \mathbb{B}$
- Opérateurs :
    - constructeur :
        $$
            \begin{align*}
                \operatorname{salle} \colon \Sigma^\star & \longrightarrow S \\
                nom & \longmapsto \operatorname{salle}(nom)
            \end{align*}
        $$
    - génériques :
        - $\operatorname{ajouterCreneauSalle} \colon S \times C \longrightarrow S$
        - $\operatorname{modifierCreneauSalle} \colon S \times H \times H \longrightarrow S$
        - $\operatorname{supprimerCreneauSalle} \colon S \times H \longrightarrow S$
        - $\operatorname{isFreeSalle} \colon S \times H \longrightarrow \mathbb{B}$
        - $\operatorname{isEmptySalle} \colon S \longrightarrow \mathbb{B}$
        - $\operatorname{toStringSalle} \colon S \longrightarrow \Sigma^\star$

### Formation

- Sorte : $F$
- Utilise : $C^\N \coloneqq \text{tableau de créneau}, H, \Sigma^\star, \mathbb{B}$
- Opérateurs :
    - constructeur :
        $$
            \begin{align*}
                \operatorname{formation} \colon \Sigma^\star & \longrightarrow F \\
                nom & \longmapsto \operatorname{formation}(nom)
            \end{align*}
        $$
    - génériques :
        - $\operatorname{ajouterCreneauFormation} \colon F \times C \longrightarrow F$
        - $\operatorname{supprimerCreneauFormation} \colon F \times H \longrightarrow F$
        - $\operatorname{isFullFormation} \colon F \longrightarrow \mathbb{B}$
        - $\operatorname{toStringFormation} \colon F \longrightarrow \Sigma^\star$

## Collections

### Enseignants

- Sorte : $E^\N \coloneqq \text{liste chaînée d'enseignants}$
- Utilise : $E, \Sigma^\star$
- Opérateurs :
    - constructeur :
        $$
            \operatorname{enseignants} \colon \empty \longrightarrow E^\N
        $$
    - génériques :
        - $\operatorname{getEnseignant} \colon E^\N \times \Sigma^\star \longrightarrow E$
        - $\operatorname{ajouterEnseignant} \colon E^\N \times E \longrightarrow E^\N$
        - $\operatorname{supprimerEnseignant} \colon E^\N \times \Sigma^\star \longrightarrow E^\N$
        - $\operatorname{toStringEnseignants} \colon E^\N \longrightarrow \Sigma^\star$

### Salles

- Sorte : $S^\N \coloneqq \text{liste chaînée de salles}$
- Utilise : $S, \N$
- Opérateurs :
    - constructeur :
        $$
            \operatorname{salles} \colon \empty \longrightarrow S^\N
        $$
    - génériques :
        - $\operatorname{ajouterSalle} \colon S^\N \times S \longrightarrow S^\N$
        - $\operatorname{getSalle} \colon S^\N \times \Sigma^\star \longrightarrow S$
        - $\operatorname{toStringSalles} \colon S^\N \longrightarrow \Sigma^\star$

## Contrôle

- Sorte : $\mathcal{C}$
- Utilise : $E^\N, S^\N, F, \Sigma^\star$
- Opérateurs :
    - constructeur :
        $$
            \operatorname{controle} \colon \empty \longrightarrow \mathcal{C}
        $$
    - générique :
        - $\operatorname{reserverCreneau} \colon \mathcal{C} \times C \longrightarrow \mathcal{C}$
        - $\operatorname{annulerCreneau} \colon \mathcal{C} \times C \longrightarrow \mathcal{C}$
        - $\operatorname{modifierCreneau} \colon \mathcal{C} \times C \longrightarrow \mathcal{C}$
        - $\operatorname{afficher}$
