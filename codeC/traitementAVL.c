#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./structure.h"
#include "./implementationAVL.h"

pArbre recherche(pArbre a, int id, long consommation, long capacite) {
    if (a == NULL) {
        return NULL; // Non trouvé
    } else if (a->elmt.id_station == id) {
        a->elmt.conso += consommation; // Mettre à jour la consommation
        if (capacite != -1) {
                a->elmt.capacite = capacite;
        }
        return a;
    } else if (id < a->elmt.id_station) {
        return recherche(a->fg, id, consommation, capacite);
    } else {
        return recherche(a->fd, id, consommation, capacite);
    }
}

void traiter(pArbre a){
    if(a == NULL){
        return;
    }
    printf("%d:%ld:%ld\n", a->elmt.id_station, a->elmt.capacite, a->elmt.conso);
}

void afficher(pArbre a) {
    if (a == NULL) {
        return;
    }
    afficher(a->fg);
    traiter(a);
    afficher(a->fd);
}
