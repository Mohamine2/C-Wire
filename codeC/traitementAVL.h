#ifndef TRAITEMENTAVL_H
#define TRAITEMENTAVL_H
#include "./structure.h"
#include "./implementationAVL.h"

pArbre remplirAVL(pArbre a, FILE* stdin);
pArbre recherche(pArbre a, int id, long consommation, long capacite);
void traiter(pArbre a);
void afficher(pArbre a);

#endif
