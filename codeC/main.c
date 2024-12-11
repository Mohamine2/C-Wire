#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(){
    char buffer[BUFFER_SIZE]; // Stocker chaque ligne lue
    int line_count = 0;       // Compteur de lignes pour illustration
    pArbre racine = NULL;
    int h = 0;

    printf("Lecture des données depuis le pipe...\n");

    // Lire ligne par ligne depuis l'entrée standard (stdin)
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        line_count++;

        // Suppression du caractère de nouvelle ligne si présent
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Afficher la ligne reçue pour vérification
        printf("Ligne %d : %s\n", line_count, buffer);

        // Ajouter ici le traitement des données, comme l'insertion dans un arbre AVL
        Element station;
        if (sscanf(buffer, "%d;%d;%d", &station.station, &station.capacite, &station.consommation) == 3) { //inserer chaque valeur dans l'élément
            racine = insertionAVL(racine, station,&h); // inserer la station dans l'AVL
        }
    }

    if (line_count == 0) {
        printf("Aucune donnée reçue depuis le pipe.\n");
    } else {
        printf("Nombre total de lignes reçues : %d\n", line_count);
    }
    Infixe(pArbre racine); // Liste dans l'ordre croissant
    return 0;
}
