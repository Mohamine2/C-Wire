#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./structure.h"
#include "./implementationAVL.h"

//fonction qui permet de rechercher et mettre à jour
pArbre recherche(pArbre a, int id, long consommation, long capacite) {

    if (a == NULL) {
        return NULL; // Non trouvé
    } else if (a->elmt.id_station == id) {
        a->elmt.conso += consommation; // Mettre à jour la consommation
        if (capacite != -1) {
                a->elmt.capacite = capacite;
        }
        return a;
    } else if (id < a->elmt.id_station) {
        return recherche(a->fg, id, consommation, capacite);
    } else {
        return recherche(a->fd, id, consommation, capacite);
    }
}

//fonction du main qui reprend tout les fonctions traitementAVL et implementationAVL
pArbre remplirAVL(pArbre a, FILE* stdin){
    int h = 0; // Hauteur pour équilibrage AVL
    // Lire l'entrée ligne par ligne
    char ligne[TAILLE_MAX_LIGNE];
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
                    strncpy(champ4, token, sizeof(champ4) - 1);
                    champ4[sizeof(champ4) - 1] = '\0';
                    break;
               case 7:  // Champ capacité
                sscanf(token, "%ld", &capacite);
                break;
            
            case 8:  // Champ consommation
                sscanf(token, "%ld", &consommation);
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

       // Appliquer une valeur par défaut si nécessaire
        if (consommation == -1) consommation = 0;

        // Rechercher un nœud existant
        pArbre existant = recherche(a, id, consommation, capacite);
        // Appliquer une valeur par défaut si nécessaire
        if (capacite == -1) capacite = 0;
        if (existant == NULL) {
            // Appliquer une valeur par défaut si nécessaire
            if (capacite == -1) capacite = 0;
            // Insérer un nouveau nœud si le nœud n'existe pas
            a = insertionAVL(a, id, capacite, consommation, &h);
        }
    }
    return a;

}

//fonction qui affiche pour un arbre
void traiter(pArbre a){
    if(a == NULL){
        return;
    }
    printf("%d:%ld:%ld\n", a->elmt.id_station, a->elmt.capacite, a->elmt.conso);
}

//parcourir en infixe pour que ce soit en ordre croissant
void afficher(pArbre a) {
    if (a == NULL) {
        return;
    }
    afficher(a->fg);
    traiter(a);
    afficher(a->fd);
}
