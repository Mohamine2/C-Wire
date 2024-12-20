#ifndef TRAITEMENTAVL_H
#define TRAITEMENTAVL_H
#include "./structure.h"
#include "./implementationAVL.h"

pArbre recherche(pArbre a, int id, long consommation, long capacite);
pArbre remplirAVL(pArbre a, FILE* stdin);
void traiter(pArbre a);
void afficher(pArbre a);
void libererAVL(pArbre a);

#endif
