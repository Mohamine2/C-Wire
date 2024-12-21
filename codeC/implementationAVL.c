#include "structure.h"
#include "implementationAVL.h"

//fonction qui crée un noeud avec notre structure
pArbre CreerArbre(int id, long capacite, long consommation) {
  pArbre a = malloc(sizeof(Arbre)); 
  if (a == NULL) {                        
      exit(1);
  }
  a->elmt.id_station = id;
  a->elmt.capacite = capacite;
  a->elmt.conso = consommation;
  a->fg = NULL;     
  a->fd = NULL;         
  a->eq = 0;
  return a;
}

//le max en fonction de 2 valeurs
int max(int a,int b){
  if(a<b){
      return b;
  }else {
      return a;
  }
}

//le min en fonction de 2 valeurs
int min(int a, int b){
  if(a<b){
      return a;
  }else{
      return b;
  }
}

//le min en fonction de 3 valeurs
int min2(int a,int b,int c){
  return min(min(a,b),c);
}


//fonction rotation à gauche
pArbre rotationGauche(pArbre a) {
    if (a == NULL || a->fd == NULL) return a;

    pArbre pivot = a->fd;
    int eq_a = a->eq;
    int eq_p = pivot->eq;

    a->fd = pivot->fg;   
    pivot->fg = a;

    a->eq = eq_a - max(eq_p, 0) - 1;
    pivot->eq = min2(eq_a - 2, eq_a + eq_p - 2, eq_p - 1);

    return pivot;  
}


//fonction rotation à droite
pArbre rotationDroite(pArbre a){
    if(a==NULL || a->fg==NULL) return a;

    pArbre pivot = a->fg;
    int eq_a = a->eq;
    int eq_p = pivot->eq;

    a->fg = pivot->fd;
    pivot->fd = a;

    a->eq =eq_a - max(eq_p,0) - 1;
    pivot->eq = min2(eq_a-2,eq_a+eq_p-2,eq_p-1);

    return pivot;

}

//fonction double rotation à gauche
pArbre DoubleRotationGauche(pArbre a) {
  if (a == NULL) return a;
  a->fd = rotationDroite(a->fd);
  return rotationGauche(a);
}


//fonction double rotation à droite
pArbre DoubleRotationDroite(pArbre a) {
  if (a == NULL) return a;
  a->fg = rotationGauche(a->fg);
  return rotationDroite(a);
}

//fonction qui permet d'équilibrer avec la rotation nécessaire en fonction de l'équilibre 
pArbre equilibreAVL(pArbre a) {
  if (a->eq >= 2) {
      if (a->fd != NULL && a->fd->eq >= 0) {
          return rotationGauche(a);
      } else {
          return DoubleRotationGauche(a);
      }
  } else if (a->eq <= -2) {
      if (a->fg != NULL && a->fg->eq <= 0) {
          return rotationDroite(a);
      } else {
          return DoubleRotationDroite(a);
      }
  }
  return a;
}



//fonction qui insere un nouveau noeud en fonction de notre structure et en mettant à jour l'equilibre
pArbre insertionAVL(pArbre a, int id, long capacite, long consommation, int* h) { 
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
a->eq = a->eq + *h;
a = equilibreAVL(a);
if(a->eq == 0){
  *h = 0;
}else{
  *h=1;
}
  }
return a;
}
