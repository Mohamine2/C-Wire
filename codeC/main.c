#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "./implementationAVL.h"
#include "./traitementAVL.h"
#include "./traitementChainon.h"


int main(int argc, char *argv[]){

    if (argc < 2) { // Vérifier qu'il y a au moins un argument passé
        printf("Erreur : Veuillez fournir un argument.\n");
        return 1;
    }
    int chiffre = atoi(argv[1]);
    //char ligne[TAILLE_MAX_LIGNE];

    if(chiffre == 6){
        //code pour lv min max
        MinMax(stdin);
        return 0;
    }

    pArbre a = NULL;
    //stdin en paramètre pour envoyer l'entrée standard dans la fonction
    a = remplirAVL(a, stdin);

    // Affichage final de l'arbre
    afficher(a);


    return 0;
}
