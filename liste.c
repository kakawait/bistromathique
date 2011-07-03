#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"
#include "main.h"

void initListe(BIGINT *ptrListe) {
    ptrListe->debut = NULL;
    ptrListe->fin = NULL;
    ptrListe->nbEl = 0;
    ptrListe->signe = 1;
}

int listeVide(BIGINT liste) {
    //return (!liste.fin && !liste.debut) || liste.nbEl == 0 ? 1 : 0;
    if(liste.fin && liste.debut) return 0;
    if(liste.nbEl == 0) return 1;
    else return 1;
}

void empilerListe(BIGINT *ptrListe, NOMBRE valeur) {
    CELLULE *tmp = malloc(sizeof(CELLULE));
    if(!tmp) exit(1);


    tmp->valeur = valeur;
    tmp->suivant = ptrListe->debut;
    tmp->precedent = NULL;
    if(listeVide(*ptrListe)) {
        ptrListe->fin = tmp;
    } else {
        ptrListe->debut->precedent = tmp;
    }
    ptrListe->debut = tmp;
    ptrListe->nbEl += 1;
}

void insererFin(BIGINT *ptrListe, NOMBRE valeur) {
    CELLULE *tmp = malloc(sizeof(CELLULE));
    if(!tmp) exit(1);

    tmp->valeur = valeur;
    tmp->suivant = NULL;
    tmp->precedent = ptrListe->fin;
    if(listeVide(*ptrListe)) {
        ptrListe->debut = tmp;
    } else {
        ptrListe->fin->suivant = tmp;
    }
    ptrListe->fin = tmp;
    ptrListe->nbEl += 1;
}

NOMBRE depilerListe(BIGINT *ptrListe) {
    NOMBRE elDepile;
    CELLULE *tmp = ptrListe->debut;

    elDepile = ptrListe->debut->valeur;
    ptrListe->debut = ptrListe->debut->suivant;
    if(!ptrListe->debut) {
        ptrListe->fin = NULL;
    } else {
        ptrListe->debut->precedent = NULL;
    }

    free(tmp);
    ptrListe->nbEl -= 1;

    return elDepile;
}

NOMBRE defilerListe(BIGINT *ptrListe) {
    NOMBRE elDefile;
    CELLULE *tmp = ptrListe->fin;

    elDefile = ptrListe->fin->valeur;
    ptrListe->fin = ptrListe->fin->precedent;
    if(!ptrListe->fin) {
        ptrListe->debut = NULL;
    } else {
        ptrListe->fin->suivant = NULL;
    }

    free(tmp);
    ptrListe->nbEl -= 1;

    return elDefile;
}

void viderListe(BIGINT *ptrListe) {
    while(!listeVide(*ptrListe)) {
        depilerListe(ptrListe);
    }

    initListe(ptrListe);
}

void afficherListe(BIGINT liste) {
    if(liste.signe == MOINS) printf("-");
    while(!listeVide(liste)) {
            printf("%d", liste.debut->valeur);
            liste.debut = liste.debut->suivant;
    }
}

BIGINT chaine2liste(char *nb) {
    int taille = strlen(nb);
    int indice;
    int fin;
    BIGINT l;

    initListe(&l);

    if(nb[0] == 45) {
        l.signe = MOINS;
        fin = 1;
    } else {
        l.signe = PLUS;
        fin = 0;
    }

    for(indice = taille - 1; indice >= fin; indice -= 1) {
        empilerListe(&l, (int)nb[indice] - 48);
    }

    return l;
}

void nettoyerNb(BIGINT *nb) {
    int out = 1;

    if(!nb->debut->valeur && nb->nbEl > 1) {
        while(out && !listeVide(*nb)) {
            if(!nb->debut->valeur) {
                depilerListe(nb);
            } else {
                out = 0;
            }
        }
        if(listeVide(*nb)) empilerListe(nb, 0);
    }
}

BIGINT clone(BIGINT nb) {
    BIGINT clone;

    initListe(&clone);

    while(!listeVide(nb)) {
        insererFin(&clone, nb.debut->valeur);
        nb.debut = nb.debut->suivant;
    }

    return clone;
}

BIGINT long2bigint(long nb) {
    BIGINT resultat;
    int n;
    initListe(&resultat);

    if(nb < 0) resultat.signe = MOINS;
    else resultat.signe = PLUS;

    while(nb != 0) {
        n = nb % 10;
        if(n < 0) n = n * -1;
        empilerListe(&resultat, n);
        nb /= 10;
    }

    return resultat;
}


BIGINT int2bigint(int nb) {
    BIGINT resultat;
        int n;

    initListe(&resultat);
    while(nb != 0) {
                n = nb % 10;
        if(n < 0) n = n * -1;

        empilerListe(&resultat,n );
        nb /= 10;
    }

    return resultat;
}



//BIGINT entier2listeWithExposant(int nb, int expo) {

