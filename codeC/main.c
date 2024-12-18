#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./structure.h"
#include "./implementationAVL.h"
#include "./traitementAVL.h"


#define BUFFER_SIZE 1024
#define TAILLE_MAX_LIGNE 1024

int main(){
    pArbre a = NULL;
    char ligne[TAILLE_MAX_LIGNE];
    int h;
        
// Lire l'entrée standard ligne par ligne
while (fgets(ligne, sizeof(ligne), stdin)) {
    char *token;
    int id = -1, capacite = -1, consommation = -1; // Initialiser à des valeurs invalides
    char champ3[128] = ""; // Stocker le champ 3 s'il est rempli
    int compteur_champ = 0;

    // Supprimer le saut de ligne éventuel
    ligne[strcspn(ligne, "\n")] = 0;

    // Tokeniser la ligne
    token = strtok(ligne, ";");
    while (token != NULL) {
        compteur_champ++;

        // Traiter chaque champ selon sa position
        if (strcmp(token, "-") == 0) {
            // Si le champ est un tiret, on l'ignore ou on lui attribue une valeur par défaut
            token = strtok(NULL, ";");
            continue;
        }

        switch (compteur_champ) {
            case 2: // Champ ID
                id = atoi(token); // Convertir seulement si non vide
                break;
            case 3: // Champ 3
                strncpy(champ3, token, sizeof(champ3) - 1); // Sauvegarder le champ 3
                champ3[sizeof(champ3) - 1] = '\0'; // Sécuriser
                break;
            case 6: // Champ capacité
                capacite = atoi(token); // Convertir seulement si non vide
                break;
            case 7: // Champ consommation
                consommation = atoi(token); // Convertir seulement si non vide
                break;
        }

        token = strtok(NULL, ";");
    }

    // Si le champ 3 est rempli, mettre à jour l'ID avec la valeur du champ 3
    if (champ3[0] != '\0') {
        id = atoi(champ3); // Convertir champ 3 en entier pour l'ID
    }

    // Vérifier si les données importantes sont valides
    if (id == -1) { 
        continue; // Passer à la ligne suivante
    }

    // Si le champ capacité ou consommation est absent, utiliser une valeur par défaut ou ignorer
    if (capacite == -1) {
        capacite = 0; // Par défaut, aucune capacité
    }
    if (consommation == -1) {
        consommation = 0; // Par défaut, aucune consommation
    }

    // Si l'ID n'est pas encore présent dans l'AVL, insérer un nouveau nœud
    if (!recherche(a, id, consommation)) {
        a = insertionAVL(a, id, capacite, consommation, &h);
    }
}

    long somme = 0;
    //parcoursSomme(a,&somme);
    //printf("Somme: %ld",somme);
    //long somme = 0;
    //parcoursSomme(a,&somme);
    //printf("Somme: %ld",somme);
    afficher(a);

    return 0;
}
