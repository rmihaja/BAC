#include <stdlib.h>
#include "enseignant.h"


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

void afficheEnseignant (Enseignant e){
    printf("%s, %s\n",getNom(e), getMatiere(e));
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

#ifdef JSON
json_t* getJsonEnseignant(Enseignant e) {

    json_t *root = json_object();

    json_object_set_new(root, "nom", json_string(e->nom));
    json_object_set_new(root, "matiere", json_string(e->matiere));

    return root;
}*/

char* toStringEnseignant(Enseignant e) {

    json_t *root = getJsonEnseignant(e);
    char *str = json_dumps(root, 0);

    #ifdef DEBUG
    puts(str);
    #endif

    // deallocate json object memory
    json_decref(root);

    return str;
}
#endif

#ifdef TEST

int main() {

    // init

    char* e1_nom = "TRUILLET";
    char* e2_nom = "GAILDRAT";
    char* e1_matiere = "Structure de données";
    char* e2_matiere = "Programmation orientée objet";

    // testing

    Enseignant e = enseignant(e1_nom, e1_matiere);

    afficheEnseignant(e); // "TRUILLET, Structure de données"

    test(getNom(e) == e1_nom);
    test(getMatiere(e) == e1_matiere);

    setNom(e, e2_nom);
    setMatiere(e, e2_matiere);

    test(getNom(e) == e2_nom);
    test(getMatiere(e) == e2_matiere);

    afficheEnseignant(e); // "GAILDRAT, Programmation orientée objet"

    #ifdef JSON
    toStringEnseignant(e);
    #endif


    return 0;
}

#endif