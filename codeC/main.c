#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./structure.h"
#include "./implementationAVL.h"
#include "./traitementAVL.h"


#define BUFFER_SIZE 1024

int main(){
    char buffer[BUFFER_SIZE]; // Stocker chaque ligne lue

    // Lire ligne par ligne depuis l'entrée standard (stdin)
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Suppression du caractère de nouvelle ligne si présent
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Structure pour stocker les données extraites
        Element station;

        // Extraire les données au format attendu : IDENTIFIANT;CAPACITE;CONSOMMATION
        if (sscanf(buffer, "%d;-;%d;-;%ld;-;-;%*d", &station.id_station, &station.capacite, &station.conso) == 3) {
            // Afficher les données au format souhaité
            printf("%d:%d:%ld\n", station.id_station, station.capacite, station.conso);
        } else {
            fprintf(stderr, "Erreur : ligne ignorée car elle ne correspond pas au format attendu : %s\n", buffer);
        }
    }

    return 0;
}
