#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "arithmetique.h"
#include <time.h>

int main()
{
    /*
    char nb1[1000000];
    char nb2[1000000];
    int nb3 = 0;
    int operateur = 0 ;
    int reponse = 1 ;
    unsigned int nb4= 0;
    clock_t begin;
    clock_t end;
    double temps;

    printf("###############################################################################\n");
    printf("#                                                                             #\n");
    printf("#                           BISTROMATIQUE                                     #\n");
    printf("#                                                                             #\n");
    printf("###############################################################################\n");

    while (1)
    {

        printf("Quelle operation voulez-vous faire ?\n");
        printf("Pour faire une addition: taper 1\n");
        printf("Pour faire une soustraction:taper 2\n");
        printf("Pour faire une multiplication: taper 3\n");
        printf("Pour faire une division:taper 4\n");
        printf("Pour calculer le carre d'un nombre:taper 5\n");
        printf("Pour calculer le cube d'un nombre:taper 6\n");
        printf("Pour calculer la racine d'un nombre:taper 7\n");
        printf("Pour calculer la factorielle d'un nombre:taper 8\n");
        printf("Pour calculer la puissance n-ieme d'un nombre:taper 9\n");
        printf("Pour quitter taper 0\n\n");
        scanf("%d",&operateur);

        if (operateur == 1)
        {

            printf("Quels nombres voulez-vous additionner?\n");
            printf("Entrez le 1er nombre:\n");
            scanf("%s",&nb1);
            printf("Entrez le 2ème nombre:\n");
            scanf("%s",&nb2);
            printf("Le resultat est: ");
            begin = clock();
            afficherListe(addition(chaine2liste(nb1), chaine2liste(nb2)));
            end = clock();
            temps = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nL'operation a pris : %.3lf secondes.", temps);
        }
        else if (operateur ==2)
        {

            printf("Quels nombres voulez-vous soustraire\n");
            printf("Entrez le 1er nombre:\n");
            scanf("%s",&nb1);
            printf("Entrez le 2ème nombre:\n");
            scanf("%s",&nb2);
            printf("Le resultat est: ");
            begin = clock();
            afficherListe(soustraction(chaine2liste(nb1), chaine2liste(nb2)));
            end = clock();
            temps = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nL'operation a pris : %.3lf secondes.", temps);

        }
           else if (operateur ==3)
        {
            printf("Quels nombres voulez-vous multiplier\n");
            printf("Entrez le 1er nombre:\n");
            scanf("%s",&nb1);
            printf("Entrez le 2ème nombre:\n");
            scanf("%s",&nb2);
            printf("Le resultat est: ");
            begin = clock();
            afficherListe(multiplication(chaine2liste(nb1), chaine2liste(nb2)));
            end = clock();
            temps = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nL'operation a pris : %.3lf secondes.", temps);
        }
           else if (operateur ==4)
        {
            printf("Quels nombres voulez-vous diviser\n");
            printf("Entrez le 1er nombre:\n");
            scanf("%s",&nb1);
            printf("Entrez le 2ème nombre:\n");
            scanf("%s",&nb2);
            printf("Le resultat est: ");
            begin = clock();
            afficherListe(divisionScolaire(chaine2liste(nb1),chaine2liste(nb2)));
            end = clock();
            temps = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nL'operation a pris : %.3lf secondes.", temps);
        }
           else if (operateur ==8)
        {
            printf("Vous chercher la factorielle de quel nombre ?\n");
            printf("Entrez le nombre:\n");
            scanf("%d",&nb4);
            printf("Le resultat est: ");
            begin = clock();
            afficherListe(factorielle(nb4));
            end = clock();
            temps = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nL'operation a pris : %.3lf secondes.", temps);

        }
           else if (operateur ==5)
        {
            printf("Vous chercher le carré de quel nombre ?\n");
            printf("Entrez le nombre:\n");
            scanf("%s",&nb1);
            printf("Le resultat est: ");
            begin = clock();
            afficherListe(multiplication(chaine2liste(nb1), chaine2liste(nb1)));
            end = clock();
            temps = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nL'operation a pris : %.3lf secondes.", temps);

        }
           else if (operateur ==6)
        {
            printf("Vous chercher le cube de quel nombre ?\n");
            printf("Entrez le nombre:\n");
            scanf("%s",&nb1);
           // BIGINT temporaire;
           // initListe(&temporaire);
            printf("Le resultat est: ");
            begin = clock();
            //temporaire = multiplication(chaine2liste(nb1), chaine2liste(nb1));
            afficherListe(puissanceDC(chaine2liste(nb1), 3));
            end = clock();
            temps = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nL'operation a pris : %.3lf secondes.", temps);
        }
           else if (operateur ==7)
        {
            printf("Vous chercher la racine de quel nombre ?\n");
            printf("Entrez le nombre:\n");
            scanf("%s",&nb1);
            printf("Le resultat est: ");
            begin = clock();
            afficherListe(racine_carree(chaine2liste(nb1)));
            end = clock();
            temps = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nL'operation a pris : %.3lf secondes.", temps);
        }
           else if (operateur ==9)
        {
            printf("De quels nombre voulez-vous la puissance\n");
            printf("Entrez le nombre dont vous voulez la puissance:\n");
            scanf("%s",&nb1);
            printf("A quel puissance voulez-vous ce nombre ?:\n");
            scanf("%d",&nb3);
            printf("Le resultat est: ");
            begin = clock();
            afficherListe(puissanceDC(chaine2liste(nb1),nb3));
            end = clock();
            temps = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nL'operation a pris : %.3lf secondes.", temps);
        }
            else
        {
            exit(0);
        }
   // printf("Voulez-vous faire une autre operation ? \noui=1\nnon = 2\n");
   // scanf("%d",&reponse);
    }
    */
    clock_t debut, fin;
    double temps;

    int n = 2;
    int e = 2009;
    int i;
    debut = clock();

    BIGINT p = puissanceDC(chaine2liste("2"), 2009);

    fin = clock();
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("L'operation a pris : %.3lf secondes.\n", temps);

    afficherListe(p);

    p = soustraction(multiplication(p, chaine2liste("9")), chaine2liste("1"));
    i = 4 * e + 1;
    debut = clock();

    while(i>0) {
        i--;
        if((p.fin->valeur % 2) == 0) {
            p = divisionPar2(p);
        } else {
            p = addition(multiplication(p, chaine2liste("3")), chaine2liste("1"));
        }
    }

    fin = clock();
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("\n\nL'operation a pris : %.3lf secondes.\n", temps);

    afficherListe(p);
}
