#include "../../include/collections/enseignant.h"

#ifdef DEBUG
#include "tests.h"
#endif

struct s_enseignant{
    char* nom;
    char* matiere;
};

Enseignant enseignant (char* n, char* m){
    Enseignant e= (Enseignant) malloc (sizeof(struct s_enseignant));
    e->nom =n;
    e->matiere=m;
    return e;
}

char* toStringEnseignant (Enseignant e){
    return "e->nom, e->matiere\n";
}

Enseignant setMatiere(Enseignant e, char* m){
    e->matiere=m;
    return e;
}

Enseignant setNom(Enseignant e, char* n){
    e->nom=n;
    return e;
}

char* getMatiere(Enseignant e){
    return e->matiere;
}

char* getNom(Enseignant e){
    return e->nom;
}

#ifdef TEST

int main() {

    // init

    char* e1_nom = "TRUILLET";
    char* e2_nom = "GAILDRAT";
    char* e1_matiere = "Structure de données";
    char* e2_matiere = "Programmation orientée objet";

    // testing

    Enseignant e = enseignant(e1_nom, e1_matiere);

    // TODO discuter du format final attendu
    test(toStringEnseignant(e) == "TRUILLET, Structure de données");

    test(getNom(e) == e1_nom);
    test(getMatiere(e) == e1_matiere);

    setNom(e, e2_nom);
    setMatiere(e, e2_matiere);

    test(getNom(e) == e2_nom);
    test(getMatiere(e) == e2_matiere);

    test(toStringEnseignant(e) == "GAILDRAT, Programmation orientée objet");

    return 0;
}

#endif