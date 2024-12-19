#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "./implementationAVL.h"
#include "./traitementAVL.h"
#include "./traitementChainon.h"

#define BUFFER_SIZE 1024
//#define TAILLE_MAX_LIGNE 1024
#define MAXX 100000000

int main(int argc, char *argv[]){

    if (argc < 2) { // Vérifier qu'il y a au moins un argument passé
        printf("Erreur : Veuillez fournir un argument.\n");
        return 1;
    }
    int chiffre = atoi(argv[1]);
    char ligne[TAILLE_MAX_LIGNE];

     if(chiffre == 6){
        //code pour lv min max
        //faudrait le faire avec une liste chainée pour insérer les noeuds 
         LV* lv = NULL;
        int station;
        long capacite, conso;
         
         
        fgets(ligne, sizeof(ligne), stdin); //ignorer la première ligne

        while (fgets(ligne, sizeof(ligne), stdin) != NULL) {
            if(sscanf(ligne, "%d:%ld:%ld", &station,&capacite,&conso)==3){
                insererLV(&lv, station, capacite, conso);
            }
        }
         LV** tab = malloc(MAXX * sizeof(LV*));
            if (tab == NULL) {
            printf("Erreur d'allocation mémoire de tab\n");
                libererLV(lv);
            return 1;
            }

         int count = listerLV(lv, tab);

         qsort(tab, count, sizeof(LV*), comparer_croissant);
         afficher_premiers(tab, count, 10);

         
         qsort(tab, count, sizeof(LV*), comparer_decroissant);
         afficher_premiers(tab, count, 10);

         // on libère tout
         libererLV(lv);


        return 0;
     }

    pArbre a = NULL;
    //stdin en paramètre pour envoyer l'entrée standard dans la fonction
    a = remplirAVL(a, stdin);

    // Affichage final de l'arbre
    afficher(a);


    return 0;
}
