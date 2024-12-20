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

    //Cas où l'utilisateur choisi "lv all"
    if(chiffre == 6){
        //code pour lv min max
        MinMax(stdin); //stdin en paramètre pour envoyer l'entrée standard dans la fonction
        return 0;
    }

    pArbre a = NULL;
    //stdin en paramètre pour envoyer l'entrée standard dans la fonction
    a = remplirAVL(a, stdin);

    // Affichage final de l'arbre
    afficher(a);
    //liberer l'arbre
    libererAVL(a);


    return 0;
}
