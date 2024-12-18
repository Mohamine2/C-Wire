#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./structure.h"
#include "./implementationAVL.h"
#include "./traitementAVL.h"


#define BUFFER_SIZE 1024
#define TAILLE_MAX_LIGNE 1024

int main(int argc, char *argv[]){
    pArbre a = NULL;
    char ligne[TAILLE_MAX_LIGNE];
    if (argc < 2) { // Vérifier qu'il y a au moins un argument passé
        printf("Erreur : Veuillez fournir un argument.\n");
        return 1;
    }
    int chiffre = atoi(argv[1]);
    int h;  // Hauteur pour équilibrage AVL

    if(chiffre != 4){
    // Lire l'entrée ligne par ligne
    while (fgets(ligne, sizeof(ligne), stdin)) {
        char *token;
        int id = -1, capacite = -1, consommation = -1;
        char champ3[128] = "";
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
                case 6: // Champ capacité
                    capacite = atoi(token);
                    printf("%d", capacite);
                    break;
                case 7: // Champ consommation
                    consommation = atoi(token);
                    break;
            }

            token = strtok(NULL, ";");
        }

        // Mettre à jour l'ID avec le champ 3 s'il est rempli
        if (champ3[0] != '\0') {
            id = atoi(champ3);
        }
    printf("%d\n", capacite);
        // Ignorer les lignes sans ID valide
        if (id == -1) {
            continue;
        }
        printf("%d\n", capacite);
        // Appliquer des valeurs par défaut si nécessaire
        if (capacite == -1) capacite = 0;
        if (consommation == -1) consommation = 0;

        // Rechercher un nœud existant
        pArbre existant = recherche(a, id);
        if (existant != NULL) {
            // Mettre à jour la capacité si elle est absente
            if (capacite != -1) { // Ne mettre à jour que si une capacité est fournie
        mettreAJourCapacite(a, id, capacite);
    }
        } else {
            // Insérer un nouveau nœud si le nœud n'existe pas
            a = insertionAVL(a, id, capacite, consommation, &h);
        }
    }
   
    afficher(a);
    }

    else{
//code pour lv min max

    }

    return 0;
}

