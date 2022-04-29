#include "creneau.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef DEBUG
#include "tests.h"
#endif

struct s_creneau{
    Enseignant enseignant;
    char * formation;
    Horaire horaire;
    char * salle;
};

Creneau creneau(Enseignant e, Horaire h, char *f, char* s){
    Creneau c=(Creneau)malloc(sizeof(struct s_creneau));
    c->enseignant=e;
    c->horaire=h;
    c->formation=f;
    c->salle=s;
    return c;
}

#ifdef JSON
Creneau creneauParser(json_t *json_creneau) {
    json_t *formation = json_object_get(json_creneau, "formation");
    json_t *salle = json_object_get(json_creneau, "salle");
    json_t *horaire = json_object_get(json_creneau, "horaire");
    json_t *enseignant = json_object_get(json_creneau, "enseignant");

    assert(json_is_string(formation)
        && json_is_string(salle)
        && json_is_object(horaire)
        && json_is_object(enseignant));

    Creneau c = creneau(enseignantParser(enseignant), horaireParser(horaire), (char*) json_string_value(formation), (char*) json_string_value(salle));

    return c;
}
#endif

Creneau setCreneauE(Enseignant e, Creneau c){
    c->enseignant=e;
    return c;
}

Creneau setCreneauF(char * f, Creneau c){
    c->formation=f;
    return c;
}

Creneau setCreneauH(Horaire h, Creneau c){
    c->horaire=h;
    return c;
}

Creneau setCreneauS(char * s, Creneau c){
    c->salle=s;
    return c;
}

char * getS(Creneau c){
    return c->salle;
}

Horaire getH(Creneau c){
    return c->horaire;
}

Enseignant getE(Creneau c){
    return c->enseignant;
}

char * getF(Creneau c){
    return c->formation;
}

void afficheCreneau(Creneau c){
    printf("%s %s \n", getS(c), getF(c));
    afficheEnseignant(getE(c));
    afficheHoraire(getH(c));
}

#ifdef JSON
json_t* getJsonCreneau(Creneau c) {

    json_t *root = json_object();

    json_object_set_new(root, "enseignant", getJsonEnseignant(getE(c)));
    json_object_set_new(root, "horaire", getJsonHoraire(getH(c)));
    json_object_set_new(root, "formation", json_string(getF(c)));
    json_object_set_new(root, "salle", json_string(getS(c)));

    return root;
}

char* toStringCreneau(Creneau c) {

    json_t *json_creneau = getJsonCreneau(c);
    char *str = json_dumps(json_creneau, 0);

    #ifdef DEBUG
    puts(str);
    #endif

    // deallocate json object memory
    json_decref(json_creneau);

    return str;
}
#endif

#ifdef TEST
#include <string.h>

int main() {

    // init

    Enseignant e1 = enseignant("TRUILLET", "Structure de données");
    Enseignant e2 = enseignant("GAILDRAT", "Programmation orientée objet");
    Horaire h1 = horaire(13, 15);
    Horaire h2 = horaire(16, 18);
    char* f1 = "L2 Informatique";
    char* f2 = "CUPGE";
    char* s1 = "108";
    char* s2 = "118";

    // testing

    Creneau c = creneau(e1, h1, f1, s1);

    test(getNom(getE(c)) == getNom(e1));
    test(getDebut(getH(c)) == getDebut(h1));
    test(getF(c) == f1);
    test(getS(c) == s1);

    info(setCreneauE(e2,c));
    info(setCreneauF(f2,c));
    info(setCreneauH(h2,c));
    info(setCreneauS(s2,c));

    test(getMatiere(getE(c)) == getMatiere(e2));
    test(getFin(getH(c)) == getFin(h2));
    test(getF(c) == f2);
    test(getS(c) == s2);

    info(afficheCreneau(c));

    #ifdef JSON
    test(strcmp(toStringCreneau(c), toStringCreneau(creneauParser(getJsonCreneau(c)))) == 0);
    #endif

    return 0;
}

#endif