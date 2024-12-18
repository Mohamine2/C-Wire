#ifndef IMPLEMENTATIONAVL_H
#define IMPLEMENTATIONAVL_H
#include "./structure.h"

pArbre CreerArbre(int id, int cap, int consommation);
int max(int a,int b);
int min(int a,int b);
int min2(int a,int b,int c);
pArbre rotationGauche(pArbre a);
pArbre rotationDroite(pArbre a);
pArbre DoubleRotationGauche(pArbre a);
pArbre DoubleRotationDroite(pArbre a);
pArbre equilibreAVL(pArbre a);
pArbre insertionAVL(pArbre a, int id, int capacite, int consommation, int* h);
void afficherInfixe(pArbre a);
pArbre recherche(pArbre a, int id);
void mettreAJourCapacite(pArbre a, int id, int nouvelleCapacite);
#endif
