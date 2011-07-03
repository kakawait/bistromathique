#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
#define FALSE 0
#define TRUE 1
#define MOINS -1
#define PLUS 1
#define EGAL 0
#define SUP 1
#define INF -1

typedef int NOMBRE;

typedef struct _CELLULE {
    NOMBRE valeur;
    struct _CELLULE *suivant;
    struct _CELLULE *precedent;
} CELLULE;

typedef struct _BIGINT {
    CELLULE *debut;
    CELLULE *fin;
    int nbEl;
    int signe;
} BIGINT;

void initListe(BIGINT *);
int listeVide(BIGINT);
void empilerListe(BIGINT *, NOMBRE);
void insererFin(BIGINT *, NOMBRE);
NOMBRE depilerListe(BIGINT *);
NOMBRE defilerListe(BIGINT *);
void viderListe(BIGINT *);
void afficherListe(BIGINT);
BIGINT chaine2liste(char *);
void nettoyerNb(BIGINT*);
BIGINT clone(BIGINT);
BIGINT long2bigint(long);
BIGINT int2bigint(int);


#endif // LISTE_H_INCLUDED
