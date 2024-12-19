#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX_LIGNE 1024

typedef struct Element {
  int id_station;
  long capacite;
  long conso;
} Element;

typedef struct Arbre {
  Element elmt;
  struct Arbre *fg;
  struct Arbre *fd;
  int eq;
} Arbre;

typedef struct LV {
    int id;
    long capacite;
    long consommation;
long difference;
    struct LV* suivant;
} LV;


typedef Arbre *pArbre;
#endif // STRUCTURE_H
