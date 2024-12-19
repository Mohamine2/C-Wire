#ifndef IMPLEMENTATIONAVL_H
#define IMPLEMENTATIONAVL_H
#include "./structure.h"

pArbre CreerArbre(int id, long cap, long consommation);
int max(int a,int b);
int min(int a,int b);
int min2(int a,int b,int c);
pArbre rotationGauche(pArbre a);
pArbre rotationDroite(pArbre a);
pArbre DoubleRotationGauche(pArbre a);
pArbre DoubleRotationDroite(pArbre a);
pArbre equilibreAVL(pArbre a);
pArbre insertionAVL(pArbre a, int id, long capacite, long consommation, int* h);
pArbre recherche(pArbre a, int id, long capacite, long consommation);

#endif
