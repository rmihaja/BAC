# Déclaration des Types Abstrait de Données

## Controle

- sorte : `controle`
- utilise : `Enseignant`, `Salle`, `Formation`

## Salle

- sorte : `Salle`
- utilise : `Creneau`
- opérateurs :
    - constructeurs :
        - `salle`$\colon$ ` ` $\to$ `Salle`

## Creneau

- sorte : `Creneau`
- utilise : `int`, `string`, `Enseignant`
- opérateurs :
  - constructeurs :
    - `creneau`$\colon$ `int` $\times$ `int` $\times$ `string` $\times$ `string` $\times$ `Enseignant` $\to$ `Creneau`

## Enseignant

- sorte : `Enseignant`
- utilise : `string`
- opérateurs :
    - constructeurs :
        - `enseignant`$\colon$`string` $\times$ `string` $\to$ `Enseignant`

## Formation

- sorte : `Formation`
- utilise : `Salles`, `Creneaux`
- opérateurs :
  - constructeurs :
    - `formation`$\colon$ `Creneaux` $\to$ `Formation`
