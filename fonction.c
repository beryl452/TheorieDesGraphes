
// Author: HOUESSOU Béryl

int connection(int PreSomm, int SecoSomm, int ordre_du, int mat[][9], int *nbre_boucl)
{
    int matrice[9][9] = {0}, prod_mat[9][9] = {0};
    int sommet, nbre_boucle = 1;

    for (int i = 0; i < ordre_du; i++)
    {
        for (int j = 0; j < ordre_du; j++)
        {
            matrice[i][j] = mat[i][j];
        }
    }

    while (matrice[PreSomm][SecoSomm] != 1 && nbre_boucle < ordre_du)
    {
        if (matrice[PreSomm][SecoSomm] == 0 && nbre_boucle != ordre_du)
        {
            for (int i = 0; i < ordre_du; i++)
            {
                for (int j = 0; j < ordre_du; j++)
                {
                    prod_mat[i][j] = 0;
                    for (int k = 0; k < ordre_du; k++)
                    {
                        prod_mat[i][j] += (matrice[i][k] * mat[k][j]);
                    }
                    if (prod_mat[i][j] > 1)
                    {
                        prod_mat[i][j] = 1;
                    }
                }
            }
            nbre_boucle++;

            for (int i = 0; i < ordre_du; i++)
            {
                for (int j = 0; j < ordre_du; j++)
                {
                    matrice[i][j] = prod_mat[i][j];
                }
            }
        }
    }

    *nbre_boucl = nbre_boucle;

    if (matrice[PreSomm][SecoSomm] == 0)
    {
        // Les deux sommets sont non-connectés
        return 1;
    }
    else
    {
        // Les deux sommets sont connectés
        return 0;
    }
}
int connexes(int ordre_du_graphe, int nbre_boucle, int matrice[][9])
{
    int visite[9], composanteConnexe = 0;
    // Mettre tous les sommets sur non-visité

    for (int i = 0; i < ordre_du_graphe; i++)
    {
        visite[i] = 0;
    }
    // Parcouris, le tableau visité;

    for (int i = 0; i < ordre_du_graphe; i++)
    {

        // Si, le sommet est non-visité, incrémenter le nombre de composante connexe (composanteConnexe);
        if (visite[i] == 0)
        {
            composanteConnexe++;
            // Parcouris, le tableau visité;
            for (int j = 0; j < ordre_du_graphe; j++)
            {
                // Si,i différent de j, si le sommet i est connecté au sommet j , et si j n'est pas visité alors, mettre j à visité;
                if ((i != j) && (connection(i, j, ordre_du_graphe, matrice, &nbre_boucle) == 0) && (visite[i] == 0))
                {
                    visite[j] = 1;
                }
            }
        }
    }
    return composanteConnexe;
}
void chaineFonc(int PreSom, int SecoSomm, int matrice[][9], int visite[], int chaine[], int chaine_index, int ordre_du_graphe)
{
    visite[PreSom] = 1;
    chaine[chaine_index] = PreSom;
    chaine_index++;
    if (PreSom == SecoSomm)
    {
        for (int i = 0; i < chaine_index; i++)
        {
            printf("%d ", chaine[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < ordre_du_graphe; i++)
        {
            if (matrice[PreSom][i] == 1 && visite[i] == 0)
            {
                chaineFonc(i, SecoSomm, matrice, visite, chaine, chaine_index, ordre_du_graphe);
            }
        }
    }
    chaine_index--;
    visite[PreSom] = 0;
}
int adjacent(int somm1, int somm2, int ordre_du, int mat[][9])
{
    if (mat[somm1][somm2] == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//                 ~~  #ByBéryl  ~~