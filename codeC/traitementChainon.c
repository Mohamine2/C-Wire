#include "structure.h"
#include "./traitementchainon.h"

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
  lv->suivant = NULL; //pour que ce soit chainon
  return lv;
}

void insererLV(LV** tete, int id, long capacite, long consommation){
  LV* lv = creerLV(id, capacite, consommation);
  if(lv == NULL){ //pense pas c'est nécessaire car on vérifie déjà dans CreerLV
    printf("Erreur dans l'allocation mémoire du chainon d'insertion");
    exit(6);
  }
  lv->suivant = *tete;
  *tete = lv;
}


// Fonction de comparaison avec qsort si croissant
int comparer_croissant(const void* a, const void* b) {
    const LV* lv1 = *(const LV**)a;
    const LV* lv2 = *(const LV**)b;

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
    const LV* lv1 = *(const LV**)a;
    const LV* lv2 = *(const LV**)b;

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
  if(lv != NULL){
    printf("%d:%ld:%ld\n", lv->id, lv->capacite, lv->consommation);
  }
}

// Fonction pour afficher les 10 premiers des 2 sens avec n = 10

void afficher_premiers(LV* tableau, int count, int n) {
    //verification pour un cas si on a - de 20 stations
    int max = n;
    if (count < n) {
        max = count;
    }

    LV* courant = tableau;
    for (int i = 0; i < max && courant !=NULL ; i++) {
        traiterChainon(courant);
        courant = courant -> suivant;
    }
}

int listerLV(LV* tete,LV** tableau){
  int count = 0;
  LV* courant = tete;
  while(courant != NULL){
    tableau[count] = courant;
    courant = courant->suivant;
    count++;
  }
  return count;
}


void libererLV(LV* lv){
  if(lv == NULL){
    return;
  }
  
  LV* a = lv;
  while(a != NULL){
    LV* b = a->suivant;
    free(a);
    a = b;
  }
}
