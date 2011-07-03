#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "arithmetique.h"
#define MUL_KARATSUBA_THRESHOLD 10
#define SQRT_HERON_THRESHOLD 2

static long N;

///######################################################################################################################///
///                                                                                                                      ///
///                                    FONCTIONS/PROCEDURES LOCALES A ARITHMETIQUE.C                                     ///
///                                                                                                                      ///
///######################################################################################################################///

/** **
 ** Fonction           : comparer_nb
 ** Entree             : BIGINT nb1, BIGINT nb2
 ** Sortie             : INT [3 états : SUP = 1, EGAL = 0, INF = -1]
 ** Description        : Fonction permet de comparer deux BIGINT
 **                      Retourne 1 si nb1 > nb2
 **                      Retourne 0 si nb1 == nb2
 **                      Retourne -1 si nb1 < nb2
 ** Portée             : Fonction interne à arithmetique.c (pas de declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT int comparer_nb(BIGINT, BIGINT); DEBUT **/
int comparer_nb(BIGINT nb1, BIGINT nb2) {
    int max = 0;

    if(nb1.signe > nb2.signe) return SUP;
    else if(nb1.signe < nb2.signe) return INF;
    if(nb1.nbEl > nb2.nbEl) return (nb1.signe) ? SUP : INF;
    else if (nb1.nbEl < nb2.nbEl) return (nb2.signe) ? INF : SUP;


    while( max == 0 && (!listeVide(nb1) && !listeVide(nb2))) {
        if(nb1.debut->valeur > nb2.debut->valeur) max = SUP;
        else if(nb1.debut->valeur < nb2.debut->valeur) max = INF;
        nb1.debut = nb1.debut->suivant;
        nb2.debut = nb2.debut->suivant;
    }

    return max;
}
/** FIN int comparer_nb(BIGINT, BIGINT); FIN **/

/** **
 ** Fonction           : max
 ** Entree             : BIGINT nb1, BIGINT nb2
 ** Sortie             : INT
 ** Description        : Fonction qui renvoie le nombre d'element du plus grand nombre
 **                      Si nb1 == nb2 alors la fonction retourne nb2.nbEl
 ** Portée             : Fonction interne à arithmetique.c (pas de declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT max(BIGINT, BIGINT); DEBUT **/
int max_element(BIGINT nb1, BIGINT nb2) {
    return (nb1.nbEl > nb2.nbEl) ? nb1.nbEl : nb2.nbEl;
}
/** FIN BIGINT max(BIGINT, BIGINT); FIN **/


/** **
 ** Fonction           : min
 ** Entree             : BIGINT nb1, BIGINT nb2
 ** Sortie             : INT
 ** Description        : Fonction qui renvoie le nombre d'element du plus petit nombre
 **                      Si nb1 == nb2 alors la fonction retourne nb2.nbEl
 ** Portée             : Fonction interne à arithmetique.c (pas de declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT min(BIGINT, BIGINT); DEBUT **/
int min_element(BIGINT nb1, BIGINT nb2) {
    return (nb1.nbEl < nb2.nbEl) ? nb1.nbEl : nb2.nbEl;
}
/** DEBUT BIGINT min(BIGINT, BIGINT); DEBUT **/


/** **
 ** Fonction           : egal_zero
 ** Entree             : BIGINT nb
 ** Sortie             : INT [2 états : TRUE = 1, FALSE = 0]
 ** Description        : Fonction permet de savoir si le BIGINT est nul
 **                      Retourne 1 si nb == 0
 **                      Retourne 0 si nb != 0
 ** Portée             : Fonction interne à arithmetique.c (pas de declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT int egal_zero(BIGINT); DEBUT **/
int egal_zero(BIGINT nb) {
    return (nb.debut->valeur == 0 && nb.nbEl == 1) ? 1 : 0;
}
/** FIN int egal_zero(BIGINT); FIN **/


/** **
 ** Fonction           : divisionPar2
 ** Entree             : BIGINT nb1
 ** Sortie             : BIGINT resultat
 ** Complexité         : N.C.
 ** Description        : Fonction de division par deux
 **                      Principe repose sur 1/2 = 5/10, il suffit donc de multiplier le nombre par 5
 **                      Puis de retirer l'element le plus a droite (equivalent à resultat / 10)
 **                      Exemple : 19 / 2
 **                         19 * 5 = 95 => on retire l'element le plus a droite => 18 / 2 = 9
 ** Portée             : Fonction interne à arithmetique.c (pas de declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT divisionPar2(BIGINT); DEBUT **/
BIGINT divisionPar2(BIGINT nb) {
    BIGINT resultat;
    BIGINT cinq;

    initListe(&resultat);
    initListe(&cinq);

    empilerListe(&cinq, 5);

    resultat = multiplication(nb, cinq);

    defilerListe(&resultat);

    return resultat;
}
/** FIN BIGINT divisionPar2(BIGINT); DEBUT **/


/** **
 ** Procédure          : multiplication
 ** Entree             : BIGINT nb1, INT exposant
 ** Sortie             : BIGINT nb1
 ** Description        : Procédure de qui multiplie nb1 par une puissance de 10
 ** Portée             : Fonction interne à arithmetique.c (pas de declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT void puissancede10(BIGINT*, int); DEBUT **/
void puissancede10(BIGINT *nb, int unsigned exposant) {
    int i;

    if(!egal_zero((*nb))) {
        if(exposant > 0) {
            for(i = 0; i < exposant; i += 1) {
                insererFin(nb, 0);
            }
        }
    }
}
/** FIN BIGINT puissancede10(BIGINT, int unsigned); FIN **/


/** **
 ** Procédure          : left_shift
 ** Entree             : BIGINT nb1, INT shif
 ** Sortie             : BIGINT nb1
 ** Description        : Fonction équivalente à l'opérateur << pour les BIGINT
 ** Portée             : Fonction interne à arithmetique.c (pas de declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT void left_shift(BIGINT, int); DEBUT **/
BIGINT left_shift(BIGINT nb, unsigned int shift) {
    BIGINT tmp;
    BIGINT tmp2;
    int j;

    initListe(&tmp);
    initListe(&tmp2);

    if (shift <= 0) return nb;

    empilerListe(&tmp, 1);
    for (j=0;j<shift;++j) {
        tmp2 = multiplication(tmp, chaine2liste("2"));
        viderListe(&tmp);
        tmp = tmp2;
    }
    return multiplication(nb, tmp);
}
/** FIN void left_shift(BIGINT, int); FIN **/


/** **
 ** Procédure          : right_shift
 ** Entree             : BIGINT nb1, INT shif
 ** Sortie             : BIGINT nb1
 ** Description        : Fonction équivalente à l'opérateur >> pour les BIGINT
 ** Portée             : Fonction interne à arithmetique.c (pas de declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT void left_shift(BIGINT, int); DEBUT **/
BIGINT right_shift(BIGINT nb, unsigned int shift) {
    BIGINT tmp, tmp2;
    int j;

    initListe(&tmp);
    initListe(&tmp2);

    if (shift <= 0) return nb;

    empilerListe(&tmp, 1);
    for (j=0;j<shift;++j) {
        tmp2 = multiplication(tmp, chaine2liste("2"));
        viderListe(&tmp);
        tmp = tmp2;
    }
    return divisionScolaire(nb, tmp);
}
/** FIN void left_shift(BIGINT, int); FIN **/


BIGINT produit(int n) {
    BIGINT tmp, tmp2, tmp3;
    initListe(&tmp);
    initListe(&tmp2);
    initListe(&tmp3);
    int m = n / 2;
    if (m == 0) {
        N += 2;
        return long2bigint(N);
    }
    if (n == 2) {
        return long2bigint(((N += 2) * (N += 2)));
    }
    tmp = produit(n - m);
    tmp2 = produit(m);
    tmp3 = multiplication(tmp, tmp2);

    viderListe(&tmp);
    viderListe(&tmp2);

    return tmp3;
}

///######################################################################################################################///
///                                                                                                                      ///
///                                            FONCTIONS/PROCEDURES GLOBALES                                             ///
///                                                                                                                      ///
///######################################################################################################################///


/** **
 ** Fonction           : addition
 ** Entree             : BIGINT nb1, BIGINT nb2
 ** Sortie             : BIGINT resultat
 ** Complexité         : Complexité linéaire O(n)
 ** Description        : Fonction d'addition arithmétique sur les BIGINT
 **                      Algorithme d'addition "scolaire" ou "à la main"
 ** Portée             : Fonction globale (declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT addition(BIGINT, BIGINT); DEBUT **/
BIGINT addition(BIGINT nb1, BIGINT nb2) {
    BIGINT resultat;
    int tmp;
    unsigned int retenue = 0;

    initListe(&resultat);

    /// Gestion du signe du résultat ///
    if(nb1.signe == MOINS && nb2.signe == PLUS) {
        nb1.signe = PLUS;
        resultat = soustraction(nb1, nb2);
        resultat.signe = MOINS;
        return resultat;
    } else if (nb1.signe == PLUS && nb2.signe == MOINS) {
        nb2.signe = PLUS;
        return resultat = soustraction(nb1, nb2);
    } else if(nb1.signe == MOINS && nb2.signe == MOINS) {
        resultat.signe = MOINS;
        nb1.signe = PLUS;
        nb2.signe = PLUS;
    }

    while(!listeVide(nb1) && !listeVide(nb2)) {
        tmp = nb1.fin->valeur + nb2.fin->valeur + retenue;
        retenue = tmp / 10;
        empilerListe(&resultat, tmp % 10);
        nb1.fin = nb1.fin->precedent;
        nb2.fin = nb2.fin->precedent;
    }

    /// Necessaire si nb1.nbEl > nb2.nbEl, il faut finir l'addition avec le reste des chiffres de nb1.nbEl ///
    /** J'ai séparé volontairement cette condition de la boucle principale, pour éviter une condition qui n'est pas nécessaire
     ** dans le cas ou nb1.nbEl = nb2.nbEl. Cela ajoute une répétition dans l'ecriture mais un léger gain en performance
     **/
    while(!listeVide(nb1)) {
        tmp = nb1.fin->valeur + retenue;
        retenue = tmp / 10;
        empilerListe(&resultat, tmp % 10);
        nb1.fin = nb1.fin->precedent;
    }

    /// Necessaire si nb2.nbEl > nb1.nbEl, il faut finir l'addition avec le reste des chiffres de nb2.nbEl ///
    /** J'ai séparé volontairement cette condition de la boucle principale, pour éviter une condition qui n'est pas nécessaire
     ** dans le cas ou nb2.nbEl = nb1.nbEl. Cela ajoute une répétition dans l'ecriture mais un léger gain en performance
     **/
    while(!listeVide(nb2)) {
        tmp = nb2.fin->valeur + retenue;
        retenue = tmp / 10;
        empilerListe(&resultat, tmp % 10);
        nb2.fin = nb2.fin->precedent;
    }

    /// Ajout de la retenue de fin, si elle existe. Exemple 99 + 10 = 1 retenue et 09 => 109 //
    if(retenue) empilerListe(&resultat, 1);

    nettoyerNb(&resultat);

    return resultat;
}
/** FIN BIGINT addition(BIGINT, BIGINT); FIN **/


/** **
 ** Fonction           : soustraction
 ** Entree             : BIGINT nb1, BIGINT nb2
 ** Sortie             : BIGINT resultat
 ** Complexité         : Complexité linéaire O(n)
 ** Description        : Fonction de soustraction arithmétique sur les BIGINT
 **                      Algorithme de soustraction "scolaire" ou "à la main"
 ** Portée             : Fonction globale (declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT soustraction(BIGINT, BIGINT); DEBUT **/
BIGINT soustraction(BIGINT nb1, BIGINT nb2) {
    BIGINT resultat;
    int tmp;
    unsigned int retenue = 0;

    initListe(&resultat);

    //nettoyerNb(&nb1);
    //nettoyerNb(&nb2);

    if(egal_zero(nb2)) return clone(nb1);
    else if(egal_zero(nb1)) {
        nb2.signe = nb2.signe * -1;
        return clone(nb2);
    }

    /// Gestion du signe du résultat ///
    if(nb1.signe == MOINS && nb2.signe == PLUS) {
        nb1.signe = PLUS;
        resultat = addition(nb1, nb2);
        resultat.signe = MOINS;
        return resultat;
    } else if(nb1.signe == PLUS && nb2.signe == MOINS) {
        nb2.signe = PLUS;
        resultat.signe = PLUS;
        return resultat = addition(nb1, nb2);
    } else if(nb1.signe == MOINS && nb2.signe == MOINS) {
        BIGINT tmp = nb1;
        nb1 = nb2;
        nb2 = tmp;
        nb2.signe = PLUS;
        nb1.signe = PLUS;
    }

    if(comparer_nb(nb1, nb2) == INF) {
        BIGINT tmp = nb1;
        nb1 = nb2;
        nb2 = tmp;
        resultat.signe = MOINS;
    }

    /// Necessaire si nb2.nbEl > nb1.nbEl, il faut finir la soustraction avec le reste des chiffres de nb2.nbEl ///
    /** J'ai séparé volontairement cette condition de la boucle principale, pour éviter une condition qui n'est pas nécessaire
     ** dans le cas ou nb2.nbEl = nb1.nbEl. Cela ajoute une répétition dans l'ecriture mais un léger gain en performance
     **/
    while(!listeVide(nb2)) {
        tmp = (nb1.fin->valeur - retenue - nb2.fin->valeur);
        if(nb1.fin->valeur > 0) retenue = 0;
        if(tmp < 0) {
            tmp = tmp + 10;
            retenue = 1;
        }
        empilerListe(&resultat, tmp % 10);
        nb1.fin = nb1.fin->precedent;
        nb2.fin = nb2.fin->precedent;
    }

    /// Necessaire si nb1.nbEl > nb2.nbEl, il faut finir la soustraction avec le reste des chiffres de nb1.nbEl ///
    /** J'ai séparé volontairement cette condition de la boucle principale, pour éviter une condition qui n'est pas nécessaire
     ** dans le cas ou nb1.nbEl = nb2.nbEl. Cela ajoute une répétition dans l'ecriture mais un léger gain en performance
     **/
    while(!listeVide(nb1)) {
        tmp = nb1.fin->valeur - retenue;
        if(nb1.fin->valeur > 0) retenue = 0;
        if(tmp < 0) {
            tmp = tmp + 10;
            retenue = 1;
        }
        empilerListe(&resultat, tmp % 10);
        nb1.fin = nb1.fin->precedent;
    }

    nettoyerNb(&resultat);

    return resultat;
}
/** FIN BIGINT soustraction(BIGINT, BIGINT); FIN **/


/** **
 ** Fonction           : multiplication
 ** Entree             : BIGINT nb1, BIGINT nb2
 ** Sortie             : BIGINT resultat
 ** Description        : Fonction d'aiguillage de la multiplication entre les
 **                      deux algorithmes de multiplications
 ** Portée             : Fonction globale (declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT multiplication(BIGINT, BIGINT); DEBUT **/
BIGINT multiplication(BIGINT nb1, BIGINT nb2) {
    if(min_element(nb1, nb2) > MUL_KARATSUBA_THRESHOLD) {
        return multiplicationKaratsuba(nb1, nb2);
    } else {
        return multiplicationBasique(nb1, nb2);
    }
}
/** FIN BIGINT multiplication(BIGINT, BIGINT); FIN **/


/** **
 ** Fonction           : multiplicationBasique
 ** Entree             : BIGINT nb1, BIGINT nb2
 ** Sortie             : BIGINT resultat
 ** Complexité         : Complexité quadratique O(n²)
 ** Description        : Fonction de multiplication de BIGINT
 **                      Algorithme de multiplication "scolaire" ou "à la main"
 **                      Exemple de fonctionnement de l'algorithme : 298 * 27 = 8046
 **                          On commence par le 1er chiffre de droite du 2eme nombre = 7
 **                          On additionne 7 fois 298 par lui meme
 **                              298+298=596  596+298=894 894+298=1192 ... =2086
 **                          Puis on effectue un decalage pour le 2eme nombre pour choisir le chiffre suivant
 **                          On ajoute un zero au 1er nombre 298 devient 2980
 **                          On recommence, cette fois ci on additionne 2 fois 2980 au resultat precedent (2046)
 **                          ...
 ** Performance        : Multiplication 18418 chiffres * 13472 chiffres = 467 sec 717
 ** Portée             : Fonction globale (declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT multiplicationBasique(BIGINT, BIGINT); DEBUT **/
BIGINT multiplicationBasique(BIGINT nb1, BIGINT nb2) {
    BIGINT resultat, ligne, tmp;
    int j, signe_nb1, signe_nb2;

    signe_nb1 = nb1.signe;
    signe_nb2 = nb2.signe;
    nb1.signe = PLUS;
    nb2.signe = PLUS;

    initListe(&resultat);

    /// Variable pour vidage mémoire des calculs intermédiaires ///
    initListe(&tmp);

    /// Cas ou nb1 ou nb2 seraient égal à 0, on renvoie 0 directement ///
    if(egal_zero(nb1) || egal_zero(nb2)) {
        empilerListe(&resultat, 0);
        return resultat;
    }

    ligne = nb1;

    while(!listeVide(nb2)) {
        for(j = 1; j <= nb2.fin->valeur; j += 1) {
            tmp = addition(resultat, ligne);
            viderListe(&resultat);
            resultat = tmp;
        }
        nb2.fin = nb2.fin->precedent;
        insererFin(&ligne, 0);
    }

    /// Gestion du signe du résultat ///
    resultat.signe = signe_nb1 * signe_nb2;

    return resultat;
}
/** FIN BIGINT multiplicationBasique(BIGINT, BIGINT); FIN **/


/** **
 ** Fonction récursive : multiplicationKaratsuba
 ** Entree             : BIGINT nb1, BIGINT nb2
 ** Sortie             : BIGINT resultat
 ** Complexité         : Complexité O(n^(ln3/ln2)) =~ O(n^1,58)
 ** Description        : Fonction de multiplication de BIGINT
 **                      Algorithme de multiplication de type "diviser pour régner" découvert par Anatolii Alexeevitch Karatsuba en 1960
 **                      http://fr.wikipedia.org/wiki/Algorithme_de_Karatsuba
 **                      http://fr.wikipedia.org/wiki/Diviser_pour_r%C3%A9gner_(informatique)
 **                      Exemple de fonctionnement de l'algorithme : 1234 * 5678 = 7006652
 **                          Il faut diviser les deux nombres en deux parties
 **                          nb1 = x1*B^m + x0 & nb2 = y1*B^m + y0
 **                              Avec B = Base = 10 et m = (max(nb1.nbEl,nb2.nbEl) + 1)/2 = (dans notre exemple) 5/2 = 2
 **                              Donc :
 **                          1234 = 12*10² + 34 & 5678 = 56*10² + 78
 **                          On pose :
 **                              p2 = x1*y1 = 12*56 = 672
 **                              p0 = x0*y0 = 34*78 = 2652
 **                              p1 = (x1+x0)*(y1+y0)-p2-p0 = (12+34)*(56+78)-672-2652 = 2840
 **                              resultat = p2*B^(m*2) + p1*B^m + p0 = 672 * 10^(2*2) + 2840 * 10^2 + 2652 = 7006652
 **                     La fonction est recursive pour pouvoir traiter les grands nombres en les divisant plusieurs fois en deux
 **                     et effectuer karatsuba jusqu'a une certaine taille.
 **                     Il est cependant necessaire de fixer MUL_KARATSUBA_THRESHOLD (un seuil pour savoir à quel moment il faut utiliser
 **                     Karatsuba ou la multiplicationBasique)
 **                         ° Première étape : Comparer le MUL_KARATSUBA_THRESHOLD en fonction de max_element(nb1,nb2) ou min_element(nb1,nb2)
 **                           On fixe le MUL_KARATSUBA_THRESHOLD à 50 pour l'instant & nb1.nbEl = 18418 chiffres & nb2.nbEl = 5032 chiffres
 **                             Avec max_element(nb1, nb2) > MUL_KARATSUBA_THRESHOLD => 24,156 sec
 **                             Avec min_element(nb1, nb2) > MUL_KARATSUBA_THRESHOLD => 22,971 sec
 **                           Donc on comparera le MUL_KARATSUBA_ThRESHOLD en fonction de min_element(nb1, nb2)
 **                         ° Deuxieme étape : Trouver la valeur du MUL_KARATSUBA_THRESHOLD
 **                           On fixe nb1.nbEl = 18418 chiffres & nb2.nbEl = 13472 chiffres
 **                             Avec MUL_KARATSUBA_THRESHOLD = 2    =>  41 sec 045
 **                             Avec MUL_KARATSUBA_THRESHOLD = 5    =>  29 sec 990
 **                             Avec MUL_KARATSUBA_THRESHOLD = 10   =>  29 sec 529
 **                             Avec MUL_KARATSUBA_THRESHOLD = 15   =>  30 sec 336
 **                             Avec MUL_KARATSUBA_THRESHOLD = 50   =>  41 sec 752
 **                             Avec MUL_KARATSUBA_THRESHOLD = 100  =>  52 sec 090
 **                             Avec MUL_KARATSUBA_THRESHOLD = 1000 => 117 sec 027
 **                           Le choix du MUL_KARATSUBA_THRESHOLD s'est donc fait de façon empirique, en fonction des différents tests
 **                           précédement effectués.
 **                           MUL_KARATSUBA_THRESHOLD est fixé à 10 puisque la valeur optimale oscille entre ]5; 15[
 ** Performance        : Multiplication 18418 chiffres * 13472 chiffres = 29 sec 529 (~13 fois plus rapide que multiplicationBasique)
 ** Portée             : Fonction globale (declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT multiplicationKaratsuba(BIGINT, BIGINT); DEBUT **/
BIGINT multiplicationKaratsuba(BIGINT nb1, BIGINT nb2) {
    BIGINT x0, x1, y0, y1, p0, p1, p2, resultat;
    BIGINT tmp, tmp2;
    int m, i, signe_nb1, signe_nb2;

    signe_nb1 = nb1.signe;
    signe_nb2 = nb2.signe;
    nb1.signe = PLUS;
    nb2.signe = PLUS;
    nb1.signe = PLUS;
    nb2.signe = PLUS;

    initListe(&resultat);

    /// Variables pour calculs intermédiaires ///
    initListe(&x0);
    initListe(&x1);
    initListe(&y0);
    initListe(&y1);
    initListe(&p0);
    initListe(&p1);
    initListe(&p2);

    /// Variables pour vidage mémoire des calculs intermédiaires ///
    initListe(&tmp);
    initListe(&tmp2);

    /// On enlève les 0 devant nb1 et nb2, car la taille du nombre est importante dans l'execution de l'algorithme de karatsuba ///
    nettoyerNb(&nb1);
    nettoyerNb(&nb2);

    /// m = milieu du plus grand nombre. Exemple : 9828839 => m = 4, 192893 => m = 3 ///
    m = (max_element(nb1, nb2) + 1) / 2;

    /// Creation de x0 et x1, dont nb1 = x1 * B^m + x0 ///
    if(nb1.nbEl <= m) {
        x0 = clone(nb1);
        empilerListe(&x1, 0);
    } else {
        for(i = 0; i < m; i += 1) {
            empilerListe(&x0, nb1.fin->valeur);
            nb1.fin = nb1.fin->precedent;
        }
        while(!listeVide(nb1)) {
            empilerListe(&x1, nb1.fin->valeur);
            nb1.fin = nb1.fin->precedent;
        }
    }

    /// Creation de y0 et y1, dont nb2 = y1 * B^m + y0 ///
    if(nb2.nbEl <= m) {
        y0 = clone(nb2);
        empilerListe(&y1, 0);
    } else {
        for(i = 0; i < m; i += 1) {
            empilerListe(&y0, nb2.fin->valeur);
            nb2.fin = nb2.fin->precedent;
        }
        while(!listeVide(nb2)) {
            empilerListe(&y1, nb2.fin->valeur);
            nb2.fin = nb2.fin->precedent;
        }
    }

    /// On enlève les 0 devant x0, x1, y0 et y1, car la taille du nombre est importante dans l'execution de l'algorithme de karatsuba ///
    nettoyerNb(&x0);
    nettoyerNb(&x1);
    nettoyerNb(&y0);
    nettoyerNb(&y1);

    /// Calculs d'après l'algorithme de karatsuba (voir description) ///
    p0 = multiplication(x0, y0);
    p2 = multiplication(x1, y1);

    tmp = addition(x0, x1);
    tmp2 = addition(y0, y1);

    p1 = multiplication(tmp, tmp2);

    viderListe(&tmp);
    viderListe(&tmp2);
    viderListe(&x0);
    viderListe(&x1);
    viderListe(&y0);
    viderListe(&y1);

    tmp = soustraction(p1, p2);

    p1 = soustraction(tmp, p0);

    viderListe(&tmp);

    puissancede10(&p1, m);
    puissancede10(&p2, (m * 2));

    tmp = addition(p0, p2);
    resultat = addition(p1, tmp);

    viderListe(&tmp);

    /// Gestion du signe du résultat ///
    resultat.signe = signe_nb1 * signe_nb2;

    return resultat;
}
/** FIN BIGINT multiplicationKaratsuba(BIGINT, BIGINT); FIN **/


/** **
 ** Fonction           : divisionScolaire
 ** Entree             : BIGINT nb1, BIGINT nb2
 ** Sortie             : BIGINT resultat
 ** Complexité         : N.C.
 ** Description        : Fonction de division arithmétique sur les BIGINT
 **                      Algorithme de soustraction "scolaire" ou "à la main"
 ** Portée             : Fonction globale (declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT divisionScolaire(BIGINT, BIGINT); DEBUT **/
BIGINT divisionScolaire(BIGINT nb1, BIGINT nb2) {
    BIGINT resultat, ligne;
    BIGINT tmp;

    initListe(&resultat);
    initListe(&ligne);

    /// Variable pour vidage mémoire des calculs intermédiaires ///
    initListe(&tmp);

    /// Gestion du signe du résultat ///
    resultat.signe = nb1.signe * nb2.signe;

    nb1.signe = PLUS;
    nb2.signe = PLUS;

    if(comparer_nb(nb1, nb2) == INF) {
        empilerListe(&resultat, 0);
        return resultat;
    } else if(comparer_nb(nb1, nb2) == EGAL) {
        empilerListe(&resultat, 1);
        return resultat;
    } else if(nb2.debut->valeur == 0 && nb2.nbEl == 1) {
        /// Impossible de diviser par zero ///
        return;
    }

    while(!listeVide(nb1)) {
        insererFin(&ligne, 0);
        ligne.fin->valeur = nb1.debut->valeur;
        insererFin(&resultat, 0);

        nettoyerNb(&ligne);

        while(comparer_nb(ligne, nb2) >= EGAL) {
            resultat.fin->valeur += 1;
            tmp = soustraction(ligne, nb2);

            viderListe(&ligne);

            ligne = tmp;
        }
        nb1.debut = nb1.debut->suivant;
    }

    nettoyerNb(&resultat);

    return resultat;
}
/** FIN BIGINT divisionScolaire(BIGINT, BIGINT); FIN **/


/** **
 ** Fonction           : racine_carree
 ** Entree             : BIGINT nb
 ** Sortie             : BIGINT resultat
 ** Complexité         : N.C.
 ** Description        : Fonction de la racine carrée du BIGINT
 **                      Basée sur la méthode d'heron, qui utilise une suite convergente vers la racine carrée.
 **                      http://fr.wikipedia.org/wiki/M%C3%A9thode_de_H%C3%A9ron
 **                         Un+1 = (Un + (nb / Un)) / 2
 **                      Exemple de fonctionnement de l'algorithme : racine_carrée(298)
 **                          Il faut tout d'abord une valeur initial (initial_guess) de préférence proche de la racine du nombre
 **                          pour cela on initialise initial_guess à la moitié (tronquée) du nombre nb
 **                              initial_guess = 29
 **                          Puis on effectue la suite
 **                             U1 = (29 + (298 / 29)) / 2 = 19
 **                             U2 = (19 + (298 / 19)) / 2 = 17
 **                             U3 = (17 + (298 / 17)) / 2 = 17
 **                          Lorqu'on trouve 2 fois (définie par SQRT_HERON_THRESHOLD) de suite Un+1 = Un on stop la boucle et on retourne le resultat
 ** Performance        :
 ** Portée             : Fonction globale (declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT racine_carree(BIGINT); DEBUT **/
BIGINT racine_carree(BIGINT nb) {
    BIGINT  resultat, tmp2, tmp, initial_guess;
    int i;

    initListe(&resultat);
    initListe(&initial_guess);
    initListe(&tmp);
    initListe(&tmp2);

    initial_guess = clone(nb);

    for(i = 0; i < (nb.nbEl / 2); i += 1) defilerListe(&initial_guess);

    i = 0;

    while(i < SQRT_HERON_THRESHOLD) {
        resultat = clone(initial_guess);
        tmp = divisionScolaire(nb, initial_guess);
        tmp2 = addition(tmp, initial_guess);
        viderListe(&tmp);
        viderListe(&initial_guess);
        initial_guess = divisionPar2(tmp2);
        if(comparer_nb(initial_guess, resultat) == EGAL) {
            i += 1;
        }
        viderListe(&resultat);
        viderListe(&tmp2);
    }

    return initial_guess;
}
/** FIN BIGINT racine_carree(BIGINT); FIN **/


/** **
 ** Fonction           : puissanceDC
 ** Entree             : BIGINT nb1, INT UNSIGNED
 ** Sortie             : BIGINT resultat
 ** Complexité         : N.C.
 ** Description        : Fonction de puissance pour les BIGINT
 **                      Algorithme de multiplication successive
 ** Portée             : Fonction globale (declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT puissanceDC(BIGINT, INT UNSIGNED); DEBUT **/
BIGINT puissanceBasique(BIGINT nb, int exp) {
    BIGINT resultat;
    int i;

    initListe(&resultat);
    resultat = clone(nb);

    if(exp == 0) {
        empilerListe(&resultat, 1);
        return resultat;
    }

    for(i = 1; i < exp; i++) {
        resultat = multiplication(resultat, nb);
    }

    return resultat;
}
/** FIN BIGINT puissanceBasique(BIGINT, INT); FIN **/


/** **
 ** Fonction           : puissanceDC
 ** Entree             : BIGINT nb1, INT UNSIGNED
 ** Sortie             : BIGINT resultat
 ** Complexité         : N.C.
 ** Description        : Fonction de puissance pour les BIGINT
 **                      Algorithme de type "diviser pour régner"
 ** Portée             : Fonction globale (declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT puissanceDC(BIGINT, INT UNSIGNED); DEBUT **/
BIGINT puissanceDC(BIGINT nb, int unsigned exp) {
    BIGINT resultat;
    BIGINT tmp, tmp2;

    initListe(&resultat);
    initListe(&tmp);
    initListe(&tmp2);

    if(exp == 0) {
        empilerListe(&resultat, 1);
        return resultat;
    } else if(exp == 1) {
        return nb;
    }

    resultat = puissanceDC(nb, exp / 2);
    if(exp % 2 == 0) {
        tmp = multiplication(resultat, resultat);
        return tmp;
    } else {
        tmp = multiplication(resultat, resultat);
        tmp2 = multiplication(tmp, nb);
        viderListe(&tmp);
        return tmp2;
    }
}
/** FIN BIGINT puissanceDC(BIGINT, INT UNSIGNED); FIN **/


/** **
 ** Fonction           : factorielle
 ** Entree             : INT nb
 ** Sortie             : BIGINT resultat
 ** Complexité         : N.C.
 ** Description        : Fonction de factorielle pour les BIGINT
 **                      Algorithme de Boiten
 ** Portée             : Fonction globale (declaration dans arithmetique.h)
 ** Auteur             : Thibaud Lepretre & Louis Forme-Becherat
 ** **/
/** DEBUT BIGINT factorielle(BIGINT, INT); DEBUT **/
BIGINT factorielle(unsigned int nb) {
    BIGINT tmp, tmp2, tmp3;
    BIGINT p = chaine2liste("1");
    BIGINT r = chaine2liste("1");

    int h = 0, shift = 0, high = 1;
    unsigned int y = nb;

    initListe(&tmp);
    initListe(&tmp2);
    initListe(&tmp3);

    if (nb < 2) return chaine2liste("1");

    N = 1;
    int log2n = -1;
    /// Equivaut à log2(n) ///
    while (y) {
        y >>= 1;
        log2n++;
    }

    while (h != nb) {
        shift += h;
        h = nb >> log2n--;
        int len = high;
        high = (h - 1) | 1;
        len = (high - len) / 2;

        if (len > 0) {
            tmp = produit(len);
            tmp2 = multiplication(p, tmp);

            viderListe(&p);

            p = tmp2;

            viderListe(&tmp);

            tmp3 = multiplication(r, p);

            viderListe(&r);

            r = tmp3;
        }
    }

    viderListe(&p);

    tmp = left_shift(r, shift);

    viderListe(&r);

    return tmp;
}
/** FIN BIGINT factorielle(BIGINT, INT); FIN **/
