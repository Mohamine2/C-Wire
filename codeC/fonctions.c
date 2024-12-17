#include "structure.c"

pArbre CreerArbre(int id, int capacite, int consommation) {
  pArbre a = malloc(sizeof(Arbre)); 
  if (a == NULL) {                        
      exit(1);
  }
  a->elmt.id_station = id;
  a->elmt.capacite = capacite;
  a->elmt.conso = consommation;
  a->fg = NULL;     
  a->fd = NULL;         
  a->eq = 0;
  return a;
}

int max(int a,int b){
  if(a<b){
      return b;
  }else {
      return a;
  }
}

int min(int a, int b){
  if(a<b){
      return a;
  }else{
      return b;
  }
}

int min2(int a,int b,int c){
  return min(min(a,b),c);
}



pArbre rotationGauche(pArbre a) {
    if (a == NULL || a->fd == NULL) return a;

    pArbre pivot = a->fd;
    int eq_a = a->eq;
    int eq_p = pivot->eq;

    a->fd = pivot->fg;   
    pivot->fg = a;

    a->eq = eq_a - max(eq_p, 0) - 1;
    pivot->eq = min2(eq_a - 2, eq_a + eq_p - 2, eq_p - 1);

    return pivot;  
}

pArbre rotationDroite(pArbre a){
    if(a==NULL || a->fg==NULL) return a;

    pArbre pivot = a->fg;
    int eq_a = a->eq;
    int eq_p = pivot->eq;

    a->fg = pivot->fd;
    pivot->fd = a;

    a->eq =eq_a - max(eq_p,0) - 1;
    pivot->eq = min2(eq_a-2,eq_a+eq_p-2,eq_p-1);

    return pivot;

}

pArbre DoubleRotationGauche(pArbre a) {
  if (a == NULL) return a;
  a->fd = rotationDroite(a->fd);
  return rotationGauche(a);
}

pArbre DoubleRotationDroite(pArbre a) {
  if (a == NULL) return a;
  a->fg = rotationGauche(a->fg);
  return rotationDroite(a);
}

pArbre equilibreAVL(pArbre a) {
  if (a->eq >= 2) {
      if (a->fd != NULL && a->fd->eq >= 0) {
          return rotationGauche(a);
      } else {
          return DoubleRotationGauche(a);
      }
  } else if (a->eq <= -2) {
      if (a->fg != NULL && a->fg->eq <= 0) {
          return rotationDroite(a);
      } else {
          return DoubleRotationDroite(a);
      }
  }
  return a;
}




pArbre insertionAVL(pArbre a, int id, int capacite, int consommation, int* h) { 
  if (a == NULL) {
      *h = 1;
      return CreerArbre(id, capacite, consommation);
  }

  if (id < a->elmt.id_station) {
      a->fg = insertionAVL(a->fg, id, capacite, consommation, h);
      *h = -*h;
  } else if (id > a->elmt.id_station) {
      a->fd = insertionAVL(a->fd,id, capacite, consommation, h);
  } else {
      *h = 0;
      return a;
  }

  if(*h != 0){
a->eq = a->eq + *h;
a = equilibreAVL(a);
if(a->eq == 0){
  *h = 0;
}else{
  *h=1;
}
  }
return a;
}

void afficherInfixe(pArbre a) {
  if (a != NULL) {
      afficherInfixe(a->fg);
      printf("Station %d : Capacite = %d, Consommation = %ld\n", a->elmt.id_station, a->elmt.capacite, a->elmt.conso);
      afficherInfixe(a->fd);
  }
}
    
int recherche(pArbre a, int id, int consommation) {
    if (a == NULL) {
        return 0; // Non trouvé
    } else if (a->elmt.id_station == id) {
        a->elmt.conso += consommation; // Mettre à jour la consommation
        return 1;
    } else if (id < a->elmt.id_station) {
        return recherche(a->fg, id, consommation);
    } else {
        return recherche(a->fd, id, consommation);
    }
}

#define TAILLE_MAX_LIGNE 128

void remplirAVL(pArbre a) {
    if (a == NULL) {
        printf("Erreur : Arbre initial inexistant.\n");
        return;
    }
    int h;
    char ligne[TAILLE_MAX_LIGNE];

    // Lire l'entrée standard ligne par ligne
    while (fgets(ligne, sizeof(ligne), stdin)) {
        char *token;
        int id = -1, capacite = -1, consommation = -1; // Initialiser à des valeurs invalides
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
                case 6: // Champ capacité
                    capacite = atoi(token); // Convertir seulement si non vide
                    break;
                case 7: // Champ consommation
                    consommation = atoi(token); // Convertir seulement si non vide
                    break;
            }

            token = strtok(NULL, ";");
        }

        // Vérifier si les données importantes sont valides
        if (id == -1) {
            printf("Erreur : ID manquant ou invalide dans une ligne.\n"); 
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
}

void parcoursSomme(pArbre a, int* somme){

if(a==NULL){
    return;
}
parcoursSomme(a->fg, somme);
*somme+= a->elmt.conso;
parcoursSomme(a->fd, somme);

}

void libererArbre(pArbre a) {
    if (a != NULL) {
        libererArbre(a->fg);
        libererArbre(a->fd);
        free(a);
    }
}

    

