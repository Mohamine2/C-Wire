#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./structure.h"

pArbre CreerArbre(int id, int cap, int consommation) {
  pArbre a = malloc(sizeof(Arbre)); 
  if (a == NULL) {                        
      exit(1);
  }
  a->elmt.id_station = id;
  a->elmt.capacite = cap;
  a->elmt.conso = consommation;
  a->fg = NULL;     
  a->fd = NULL;         
  a->equilibre = 0;
  return a;
}

int max3(int a,int b){
  if(a<b){
      return b;
  }else {
      return a;
  }
}

int min(int a, int b){
  if(a<b){
      return a;
  }else{
      return b;
  }
}

int min3(int a,int b,int c){
  return min(min(a,b),c);
}



pArbre rotationGauche(pArbre a){
    int eq_a;
    int eq_p;
    pArbre pivot=a->fd;
    a->fd=pivot->fg;
    pivot->fg=a;
    eq_a=a->eq;
    eq_p=pivot->eq;
    int max=max(eq_p,0);
    a->eq=eq_a-max-1;
    pivot->eq=min3(eq_a-2,eq_p-2,eq_p-1);
    a=pivot;
    return a;
}

pArbre rotationDroite(pArbre a){
    int eq_a;
    int eq_p;
    pArbre pivot=a->fg;
    a->fg=pivot->fd;
    pivot->fd=a;
    int min=min(eq_p,0);
    a->eq=eq_a-min+1;
    pivot->eq=max3(eq_a+2,eq_a+eq_p+2,eq_p+1);
    a=pivot;
    return a;
}

pArbre DoubleRotationGauche(pArbre a) {
  if (a == NULL) return a;
  a->fd = rotationDroite(a->fd);
  return rotationGauche(a);
}

pArbre DoubleRotationDroite(pArbre a) {
  if (a == NULL) return a;
  a->fg = rotationGauche(a->fg);
  return rotationDroite(a);
}

pArbre equilibreAVL(pArbre a) {
  if (a->equilibre >= 2) {
      if (a->fd != NULL && a->fd->equilibre >= 0) {
          return rotationGauche(a);
      } else {
          return DoubleRotationGauche(a);
      }
  } else if (a->equilibre <= -2) {
      if (a->fg != NULL && a->fg->equilibre <= 0) {
          return rotationDroite(a);
      } else {
          return DoubleRotationDroite(a);
      }
  }
  return a;
}




pArbre insertionAVL(pArbre a, int id, int capacite, int consommation, int* h) { 
  if (a == NULL) {
      *h = 1;
      return CreerArbre(id, capacite, consommation);
  }

  if (id < a->elmt.id_station) {
      a->fg = insertionAVL(a->fg, id, capacite, consommation, h);
      *h = -*h;
  } else if (id > a->elmt.id_station) {
      a->fd = insertionAVL(a->fd,id, capacite, consommation, h);
  } else {
      *h = 0;
      return a;
  }

  if(*h != 0){
a->equilibre = a->equilibre + *h;
a = equilibrageAVL(a);
if(a->equilibre == a){
  *h = 0;
}else{
  *h=1;
}
  }
return a;
}

void afficherInfixe(pArbre a) {
  if (a != NULL) {
      afficherInfixe(a->fg);
      printf("Station %d : Capacite = %d, Consommation = %d\n", a->elmt.station, a->elmt.capacite, a->elmt.consommation);
      afficherInfixe(a->fd);
  }
}
    
int recherche(pArbre a, int id, int consommation) {
    if (a == NULL) {
        return 0; // Non trouvé
    } else if (a->elmt.id_station == id) {
        a->elmt.consommation += consommation; // Mettre à jour la consommation
        return 1;
    } else if (id < a->elmt.id_station) {
        return recherche(a->fg, id, consommation);
    } else {
        return recherche(a->fd, id, consommation);
    }
}
