#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
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

#ifdef JSON
Enseignant enseignantParser(json_t *json_enseignant) {
    json_t *nom = json_object_get(json_enseignant, "nom");
    json_t *matiere = json_object_get(json_enseignant, "matiere");

    assert(json_is_string(nom) && json_is_string(matiere));

    Enseignant e = enseignant((char*) json_string_value(nom), (char*) json_string_value(matiere));

    return e;
}
#endif

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

    json_object_set_new(root, "nom", json_string(getNom(e)));
    json_object_set_new(root, "matiere", json_string(getMatiere(e)));

    return root;
}

char* toStringEnseignant(Enseignant e) {

    json_t *json_enseignant = getJsonEnseignant(e);
    char *str = json_dumps(json_enseignant, 0);

    #ifdef DEBUG
    puts(str);
    #endif

    // deallocate json object memory
    json_decref(json_enseignant);

    return str;
}
#endif

#ifdef TEST
#include <string.h>

int main() {

    // init

    char* e1_nom = "TRUILLET";
    char* e2_nom = "GAILDRAT";
    char* e1_matiere = "Structure de données";
    char* e2_matiere = "Programmation orientée objet";

    // testing

    Enseignant e = enseignant(e1_nom, e1_matiere);

    info(afficheEnseignant(e)); // "TRUILLET, Structure de données"

    test(getNom(e) == e1_nom);
    test(getMatiere(e) == e1_matiere);

    info(setNom(e, e2_nom));
    info(setMatiere(e, e2_matiere));

    test(getNom(e) == e2_nom);
    test(getMatiere(e) == e2_matiere);

    info(afficheEnseignant(e)); // "GAILDRAT, Programmation orientée objet"

    #ifdef JSON
    test(strcmp(toStringEnseignant(e), toStringEnseignant(enseignantParser(getJsonEnseignant(e)))) == 0);
    #endif


    return 0;
}

#endif