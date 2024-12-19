#ifndef TRAITEMENTCHAINON_H
#define TRAITEMENTCHAINON_H
#include "./structure.h"

LV* creerLV(int id, long capacite, long consommation);
int comparer_croissant(const void* a, const void* b);
int comparer_decroissant(const void* a, const void* b);
void traiterChainon(LV* lv);
void afficher_premiers(LV* stations, int count, int n);

#endif
