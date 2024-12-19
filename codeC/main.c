#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "./implementationAVL.h"
#include "./traitementAVL.h"
#include "./traitementChainon.h"

#define BUFFER_SIZE 1024
#define TAILLE_MAX_LIGNE 1024

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
         
         LV* tab[100000000];//on donne un max qui ne peut pas être dépassé
         int count = listerLV(lv, tab);
         
        fgets(ligne, sizeof(ligne), stdin); //ignorer la première ligne

        while (fgets(ligne, sizeof(ligne), stdin) != NULL) {
            if(sscanf(ligne, "%d:%ld:%ld", &station,&capacite,&conso)==3){
                insererLV(&lv, station, capacite, conso);
            }
        }
         qsort(lv, count, sizeof(LV*), comparer_croissant);
         afficher_premiers(tab, count, 10);

         
         qsort(lv, count, sizeof(LV*), comparer_decroissant);
         afficher_premiers(&lv, count, 10);

         // on libère tout
         libererLV(lv);


        return 0;
     }

    pArbre a = NULL;
    int h = 0; // Hauteur pour équilibrage AVL
    // Lire l'entrée ligne par ligne
    while (fgets(ligne, sizeof(ligne), stdin)) {
        char *token;
        int id = -1;
        long capacite = -1; long consommation = -1; // test pour voir si la dernière valeur négative dans les fichiers est encore là
        char champ3[128] = "";
        char champ4[128] = "";
        int compteur_champ = 0;

        // Supprimer le saut de ligne éventuel
        ligne[strcspn(ligne, "\n")] = 0;

        // Découper la ligne en champs séparés par ";"
        token = strtok(ligne, ";");
        while (token != NULL) {
            compteur_champ++;

            // Ignorer les champs "-"
            if (strcmp(token, "-") == 0) {
                token = strtok(NULL, ";");
                continue;
            }

            switch (compteur_champ) {
                case 2: // Champ ID
                    id = atoi(token);
                    break;
                case 3: // Champ 3
                    strncpy(champ3, token, sizeof(champ3) - 1);
                    champ3[sizeof(champ3) - 1] = '\0';
                    break;
                case 4 : //champ 4
                    strncpy(champ4, token, sizeof(champ3) - 1);
                    champ3[sizeof(champ4) - 1] = '\0';
                    break;
                case 7: // Champ capacité
                    capacite = atoi(token);
                    break;
                case 8: // Champ consommation
                    consommation = atoi(token);
                    break;
            }

            token = strtok(NULL, ";");
        }

        // Mettre à jour l'ID avec le champ 3 s'il est rempli
        if (champ3[0] != '\0') {
            id = atoi(champ3);
        }
        if (champ4[0] != '\0') {
            id = atoi(champ4);
        }

        // Ignorer les lignes sans ID valide
        if (id == -1) {
            continue;
        }

        // Appliquer des valeurs par défaut si nécessaire
        if (capacite == -1) capacite = 0;
        if (consommation == -1) consommation = 0;

        // Rechercher un nœud existant
        pArbre existant = recherche(a, id, consommation);
        if (existant != NULL) {
            // Mettre à jour la capacité si elle est absente
            if (capacite == -1) {
                capacite = existant->elmt.capacite;
            }
        } else {
            // Insérer un nouveau nœud si le nœud n'existe pas
            a = insertionAVL(a, id, capacite, consommation, &h);
        }
    }

    // Affichage final de l'arbre
    afficher(a);


    return 0;
}
