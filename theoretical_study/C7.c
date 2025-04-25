#include <stdio.h>
#include <stdlib.h>
#include "tache_c3.h"
#include "tache_c6.h"
#include "tacheC5.h"

/** 
\brief :  rempli un csv avec les valeurs de la loi empirique de (C^2_1,C^2_2), conditionnellement à (C^1_1,C^1_2) = (1,2)
\param : n le nombre de distributions indépendantes
\return :  nothing
*/

int hist_empirique_C7(int n)
{
    FILE *file = fopen("data1.csv", "w");
    if (file == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    double *result = P_approx_2_1(1, 2, n); //on stocke les valeurs dans un tableau result
    int index = 0;
    fprintf(file, "proportion, (i,j)\n");
    for (int i = 1; i < 4; i++)
    {
        for (int j = i; j < 4; j++)
        {
            fprintf(file, "%f, (%d,%d)\n", result[index], i, j);
            index ++;
        }
    }
    fclose(file);
    free(result);
    return 0;
}


/** 
\brief :  rempli un csv avec les valeurs de la loi théorique de (C^2_1,C^2_2), conditionnellement à (C^1_1,C^1_2) = (1,2)
\param : nothing
\return :  nothing
*/

int hist_theorique_C7()
{
    FILE *fd = fopen("data2.csv", "w");
    if (fd == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    fprintf(fd, "resultat, (i,j)\n");
    for (int i = 1; i < 4; i++)
    {
        for (int j = i; j < 4; j++)
        {
            fprintf(fd, "%f, (%d, %d)\n", P_cond(1,2 , i, j), i, j);
        }
    }
    fclose(fd);
    return 0;
}


/** 
\brief :  rempli un csv avec les valeurs P_approx_2_1_main(2,3,1,2,n) pour n allant de 1 à 100000
\param : nothing
\return :  nothing
*/

int nuage_C7()
{
    FILE *f = fopen("data3.csv", "w");
    if (f == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    fprintf(f, "N, proba\n");
    for (int i = 1; i < 100001; i+= 10) //on crée une boucle de 1 à 100000
    {
        fprintf(f, "%d, %f\n", i, P_approx_2_1_main(2, 3, 1, 2, i));
    }
    fclose(f);
    return 0;
}

/** 
\brief :  rempli un csv avec la droite  y = P( (C^2_1,C^2_2) = (2,3) | (C^1_1,C^1_2)=(1,2) )
\param : nothing
\return :  nothing
*/

int droite()
{
    FILE *fdd = fopen("data4.csv", "w");
    if (fdd == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    fprintf(fdd, "y\n");
    fprintf(fdd, "%f\n", P_cond(2, 3, 1, 2)); //valeur de P( (C^2_1,C^2_2) = (2,3) | (C^1_1,C^1_2)=(1,2) )
    fclose(fdd);
    return 0;
}

int main()
{
    srand(time(NULL)); //Initialise le générateur de variables aléatoires
    hist_empirique_C7(10000);
    hist_theorique_C7();
    nuage_C7();
    droite();
    return 0;
}


int main()
{
    hist_empirique_C7(10000);
    hist_theorique_C7();
    nuage_C7();
    droite();
    return 0;
}
