#include "structure.h"

//fonction qui creer le chainon
LV* creerLV(int id, long capacite, long consommation){
  LV* lv = malloc(sizeof(LV));
  if(lv == NULL){
    printf("Mauvaise allocation mémoire du chainon");
    exit(6);
  }
  lv->id = id;
  lv->capacite = capacite;
  lv->consommation = consommation;
  lv->difference = capacite - consommation;
  return lv;
}

// Fonction de comparaison avec qsort si croissant
int comparer_croissant(const void* a, const void* b) {
    const LV* lv1 = a;
    const LV* lv2 = b;

    if (lv1->difference < lv2->difference) {
        return -1;
    } else if (lv1->difference > lv2->difference) {
        return 1;
    } else {
        return 0;
    }
}

// Fonction de comparaison avec qsort si decroissant
int comparer_decroissant(const void* a, const void* b) {
    const LV* lv1 = a;
    const LV* lv2 = b;

    if (lv1->difference > lv2->difference) {
        return -1;
    } else if (lv1->difference < lv2->difference) {
        return 1;
    } else {
        return 0;
    }
}


//même fonction que traiter mais avec une liste chainée
void traiterChainon(LV* lv){
  if(lv == NULL){
    return;
  }
  printf("%d:%ld:%ld\n", lv->id, lv->capacite, lv->consommation);
}

// Fonction pour afficher les 10 premiers des 2 sens avec n = 10

void afficher_premiers(LV* stations, int count, int n) {
    for (int i = 0; i < n && i < count; i++) {
        traiterChainon(&stations[i]);
    }
}
