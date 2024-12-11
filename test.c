#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(){
    char buffer[BUFFER_SIZE]; // Stocker chaque ligne lue
    int line_count = 0;       // Compteur de lignes pour illustration

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
    }

    if (line_count == 0) {
        printf("Aucune donnée reçue depuis le pipe.\n");
    } else {
        printf("Nombre total de lignes reçues : %d\n", line_count);
    }

    return 0;
}
