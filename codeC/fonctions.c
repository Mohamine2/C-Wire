int Somme(int a,int b){
    return a+b;

pArbre CreerArbre(Element x) {
    pArbre a = malloc(sizeof(Arbre)); 
    if (a == NULL) {                        
        exit(1);
    }
    a->elmt = x;     
    a->fg = NULL;     
    a->fd = NULL;         
    a->equilibre = 0;   
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
    int eq_a = a->equilibre;
    int eq_p = pivot->equilibre;

    a->fd = pivot->fg;   
    pivot->fg = a;

    a->equilibre = eq_a - max(eq_p, 0) - 1;
    pivot->equilibre = min2(eq_a - 2, eq_a + eq_p - 2, eq_p - 1);

    return pivot;  
}




pArbre rotationDroite(pArbre a){
    if(a==NULL || a->fg==NULL) return a;
    
    pArbre pivot = a->fg;
    int eq_a = a->equilibre;
    int eq_p = pivot->equilibre;
    
    a->fg = pivot->fd;
    pivot->fd = a;
    
    a->equilibre =eq_a - max(eq_p,0) - 1;
    pivot->equilibre = min2(eq_a-2,eq_a+eq_p-2,eq_p-1);
    
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

void ajouterFilsDroit(pArbre a,Element e){
    if(a== NULL || a->fd !=NULL){
        return;
    }
    a->fd = CreerArbre(e);
}

void ajouterFilsGauche(pArbre a,Element e){
    if(a == NULL || a->fg != NULL){
        return;
    }
    a->fg = CreerArbre(e);
}


pArbre equilibreAVL(pArbre a) {
    if (a->equilibre >= 2) {
        if (a->fd != NULL && a->fd->equilibre >= 0) {
            return rotationGauche(a);
        } else {
            return DoubleRotationGauche(a);
        }
    } else if (a->equilibre <= -2) {
        if (a->fg != NULL && a->fg->equilibre <= 0) {
            return rotationDroite(a);
        } else {
            return DoubleRotationDroite(a);
        }
    }
    return a;
}




pArbre insertionAVL(pArbre a, Element e, int* h) {
    if (a == NULL) {
        *h = 1;
        return CreerArbre(e);
    }

    if (e < a->elmt) {
        a->fg = insertionAVL(a->fg, e, h);
        *h = -*h;
    } else if (e > a->elmt) {
        a->fd = insertionAVL(a->fd, e, h);
    } else {
        *h = 0;
        return a;
    }

    if(*h != 0){
	a->equilibre = a->equilibre + *h;
	a = equilibrageAVL(a);
	if(a->equilibre == a){
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
        printf("Station %d : Capacite = %d, Consommation = %d\n", a->elmt.station, a->elmt.capacite, a->elmt.consommation);
        afficherInfixe(a->fd);
    }
}
