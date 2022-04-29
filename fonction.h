
// Author: HOUESSOU Béryl

#ifndef DEF_FONCTION
#define DEF_FONCTION

int adjacent(int somm1, int somm2, int ordre_du, int mat[][9]);
int connection(int PreSomm, int SecoSomm, int ordre_du, int mat[][9], int *nbre_boucl);
int connexes(int ordre_du_graphe, int nbre_boucle, int matrice[][9]);
void chaineFonc(int PreSom, int SecoSomm, int matrice[][9], int visite[], int chaine[], int chaine_index,int ordre_du_graphe); 

#endif
//                 ~~  #ByBéryl  ~~