// cd .\TheorieDesGraphes_TP
// gcc main.c -o main
// ./main

// Veuillez lire notre ReadMe (Le fichier '.html')
// Et consulter les graphes test (GrapheTest) 
// BINOME: HOUESSOU Béryl   - Poète Descartes

#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "fonction.c"

int main(int argc , char *argv[])
{
    int matrice[9][9] = {0},visite[9],chaine[9];
    int ordre_du_graphe, i, j, PreSomm, SecoSomm, choix, nbre_boucle = 0,chaine_index=0;

    printf("Il s agira dans un premier temps de creer votre graphe\n");

    //  ~~ Création de matrice par l'utilisateur ~~
    do
    {
        printf("Quel est l'ordre du graphes (Ce dernier doit etre compris entre 0 (exclu) et 9 (exclu)\n");
        scanf("%d", &ordre_du_graphe);
        if (ordre_du_graphe < 0 || ordre_du_graphe > 9)
        {
            system("cls");
        }
    } while (ordre_du_graphe <= 0 || ordre_du_graphe >= 9);

    for (i = 0; i < ordre_du_graphe; i++)
    {
        for (j = 0; j < ordre_du_graphe; j++)
        {
            matrice[i][j] = 0;
        }
    }
    printf(" Remplissez les %d elements de la matrice :\n\n", ordre_du_graphe * ordre_du_graphe);

    for (i = 0; i < ordre_du_graphe; ++i)
    {
        for (j = 0; j < ordre_du_graphe; ++j)
        {
            do
            {
                scanf("%d", &matrice[i][j]);
            } while (matrice[i][j] != 0 && matrice[i][j] != 1);
        }
        printf("\n");
    }

    system("cls");
    printf("Votre matrice d'adjacence est la suivante:\n");
    for (int i = 0; i < ordre_du_graphe; i++)
    {
        for (int j = 0; j < ordre_du_graphe; j++)
        {
            printf("%d  ", matrice[i][j]);
        }
        printf("\n");
    }

    // ~~ Le Menu ~~
    do
    {
        printf("\n_-_-_-_-_---------_-_-_-_-_-_\n");
        printf("_-_-_-_-    MENU    -_-_-_-_\n");
        printf("_-_-_-_-_---------_-_-_-_-_-_\n\n");
        printf("1: Connexion de deux sommets\n");
        printf("2: Composantes connexes \n");
        printf("3: Chaine\n");

        scanf("%d", &choix);

    } while (choix < 1 || choix > 3);
    switch (choix)
    {
    case 1:
        do
        {
            printf("\nEntrer le sommet 1\n");
            scanf("%d", &PreSomm);
        } while (PreSomm < 0 || PreSomm > (ordre_du_graphe - 1));

        do
        {
            printf("Entrer le sommet 2\n");
            scanf("%d", &SecoSomm);
        } while (SecoSomm < 0 || SecoSomm > (ordre_du_graphe - 1));

        if (connection(PreSomm, SecoSomm, ordre_du_graphe, matrice, &nbre_boucle))
        {
            printf("Les sommets, %d et %d ne sont pas connectes\n", PreSomm, SecoSomm);
        }
        else
        {
            printf("Les sommets, %d et %d sont connectes et separes par %d arc(s)\n", PreSomm, SecoSomm, nbre_boucle);
        }
        break;
    case 2:
        if (connexes(ordre_du_graphe, nbre_boucle, matrice) == 1)
        {
            printf("Votre graphe est CONNEXE et donc possede 01 composante connexe\n");
        }
        else
        {
            printf("Votre graphe est NON - CONNEXE et possede %d composante connexe\n", connexes(ordre_du_graphe, nbre_boucle, matrice));
        }
        break;
    case 3:
        do
        {
            printf("\nEntrer le premier sommet de votre chaine\n");
            scanf("%d", &PreSomm);
        } while (PreSomm < 0 || PreSomm > (ordre_du_graphe - 1));

        do
        {
            printf("Entrer le second sommet de votre chaine\n");
            scanf("%d", &SecoSomm);
        } while (SecoSomm < 0 || SecoSomm > (ordre_du_graphe - 1));

        if (connection(PreSomm, SecoSomm, ordre_du_graphe, matrice, &nbre_boucle)==1)
        {
            printf("Les sommets, %d et %d ne sont pas connectes donc il n y a aucune chaine entre eux.\n", PreSomm, SecoSomm);
        }
        else
        {   
            printf("Les chaines qui relient vos deux sommets sont:\n");

            for(int i = 0; i < ordre_du_graphe; i++){
                visite[i]=0; 
            } 
 
            chaineFonc(PreSomm,SecoSomm,matrice,visite,chaine,chaine_index,ordre_du_graphe); 
        }
        break;
    default:
        printf("Erreur, comment êtes-vous arrivés la ?");
        break;
    }

    return 0;
}
//                 ~~  #ByBéryl  ~~