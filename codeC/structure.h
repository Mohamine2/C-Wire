#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Element{
    int id_station;
    int capacite;
    int conso;
}Element;

typedef struct Arbre{
    Element elmt;
    struct Arbre* fg;
    struct Arbre* fd;
    int eq;
    long s_conso;
}Arbre;

typedef Arbre* pArbre;

#endif //STRUCTURE_H
