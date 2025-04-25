#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tache_c6.h"
 
/** 
\brief :  simule la distribution des cartes à J2 en prenant en argument la main (i,j) de J1
\param : i et j entiers, cartes de J1
\return : tableau avec les 2 cartes distribuées à J2
*/
 
int* main_J2(int i, int j)
{
 
    int cartes[4]; // préparation d'un tableau pour stocker les cartes qu'il reste dans le jeu
    int n1 = 2; // initialisation à 2 des entiers qui représentent le nombre de chaque cartes restantes
    int n2 = 2;
    int n3 = 2;
    if (i == 1) // si i = 1 alors n1 décroit car J2 ne pourra pas avoir cette carte
    {
        n1 = n1-1;
    }
    if ( i == 2)
    {
        n2 = n2-1;
    }
    if (i == 3)
    {
        n3 = n3-1;
    }
    if (j == 1)
    {
        n1=n1-1;
    }
    if (j == 2)
    {
        n2 = n2-1;
    }
    if (j == 3)
    {
        n3 = n3-1;
    }
    if(n1+n2+n3 != 4) // vérification qu'il ya bien 4 cartes dans le jeu
    {
        perror("erreur dans le comptage des cartes de J1");
        exit(1);
    }
    int index = 0;
    for (int k1=0; k1<n1; k1++) // boucle pour mettre les potentielles cartes 1
    {
        cartes[index++]= 1;
    }
    for (int k2=0; k2<n2; k2++) // boucle pour mettre les potentielles cartes 2
    {
        cartes[index++]= 2;
    }
    for (int k3=0; k3<n3; k3++) // boucle pour mettre les potentielles cartes 3
    {
        cartes[index++]= 3;
    }
    int* tab_main_J2 = malloc(2 * sizeof(int)); // tableau pour mettre les cartes de J2
    if (tab_main_J2 == NULL) 
    {
        perror("Échec malloc");
        return NULL;
    }
    int index1 = rand() % 4;
    int index2;
    do {
        index2 = rand() % 4;
    } while (index2 == index1);  // même index = même carte exacte, donc interdit    
    tab_main_J2[0] = cartes[index1];
    tab_main_J2[1] = cartes[index2];
    if(tab_main_J2[0] > tab_main_J2[1]) // cas ou les valeurs ne son pas rangées dans l'ordre croissant
    {
        int tmp = tab_main_J2[0];
        tab_main_J2[0] = tab_main_J2[1];
        tab_main_J2[1] = tmp;
    }
    return tab_main_J2;
}
 
/** 
\brief : retourne a proportion de mains (i',j') obtenues par J2 lors de n distributions indépendantes de la main de J2, conditionnellement à (C^1_1,C^1_2)=(i,j)
\param : i, j cartes de J1 et i', j' les cartes potentiellements obtenues par J2, n nombre de distributions
\return : proportion
*/
double P_approx_2_1_main(int i_prim, int j_prim, int i, int j, int n)
{
    int p = 0; // initialisation de la variable qui va compter les tirages (i', j')
    for ( int k =0; k<n; k++) // boucle pour faire n tirages
    {
        int* t_main_J2 = main_J2(i, j); // main de J2
        if(t_main_J2){
            if (t_main_J2[0]==i_prim && t_main_J2[1]==j_prim){
 
                p++;
            }
            free(t_main_J2);
        }
    }
    double proportion = (double)p /n ;
    return proportion;
}
 
/** 
\brief : retourne pour chaque main (i',j'), la proportion de telles mains obtenues par J2 lors de n distributions indépendantes de la main de J2, conditionnellement à (C^1_1,C^1_2)=(i,j).
\param: int i 
\return : tableau avec la proportion pour chaque main possible de J2
*/
double* P_approx_2_1(int i, int j ,int n)
{
    double* tab = malloc(6*sizeof(double)); // il y a 6 couples de cartes 
    int index=0; // initialisation de l'index du tableau
    for(int k=1; k<4; k++) // double boucle pour les mains (i', j')
    {
        for (int m =k; m<4; m++)
        {
            double p = P_approx_2_1_main(k, m, i, j, n);
            printf("La proportion de (%d,%d) est %f", k, m ,p);
            tab[index] = p;
            index++;
 
        }
    }
    return tab;
}