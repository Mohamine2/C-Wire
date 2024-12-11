#ifndef STRUCTURE_H
#define STRUCTURE_H

//On inclut les bibliothèque qu'on connait
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct Element{
    int station;
    int capacite;
    int consommation;
}Element;

typedef struct Arbre{
    Element elmt;
    struct Arbre* fg;
    struct Arbre* fd;
    int equilibre;
}Arbre;

typedef Arbre* pArbre;

#endif //STRUCTURE_H
