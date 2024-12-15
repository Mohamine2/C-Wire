#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    int station;       // Identifiant de la station
    int capacite;      // Capacité de la station
    long consommation; // Consommation de la station (changé en long)
} Element;

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
        if (sscanf(buffer, "%d;-;%d;-;%ld;-;-;%*d", &station.station, &station.capacite, &station.consommation) == 3) {
            // Afficher les données au format souhaité
            printf("%d:%d:%ld\n", station.station, station.capacite, station.consommation);
        } else {
            fprintf(stderr, "Erreur : ligne ignorée car elle ne correspond pas au format attendu : %s\n", buffer);
        }
    }

    return 0;
}

//CODE DE CHATGPT QUI FONCTIONNE AVEC HVA COMP NORMALEMENT