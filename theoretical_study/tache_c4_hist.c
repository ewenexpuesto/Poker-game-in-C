#include <stdio.h>
#include <stdlib.h>
#include "tache_c3.h"


void hist_loi_empirique_C4(int n)
{
    FILE *f = fopen("P_approx_1.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'est bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
    }
    fprintf(f,"(C1_1.C1_2),P_approx_1(n)\n"); // Ligne pour les titres des colonnes
    double *tab = P_approx_1(n); //stock les valeurs de P_approx_1(n)
    int k =0;
    while(k<6)
    {
        for (int i=1; i<4; i++)
        {
            for(int j=i; j<4; j++)
            {
                fprintf(f,"(%d.%d),%f\n",i,j, tab[k] );
                k++;
            }
        }
    }
    fclose(f);
}

void hist_loi_theorique_C4()
{
    FILE *f = fopen("loi_theorique.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'eest bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
    }
    fprintf(f,"(C1_1.C1_2),P(C1_1.C1_2)\n"); // Ligne pour les titres des colonnes
    for(int i=1; i<4; i++)
    {
        for (int j=i; j<4; j++)
        {
            tirage t ;
            t.first = i;
            t.second = j;
            fprintf(f, "(%d.%d),%f\n", i,j,P(t));
        }
    }
    fclose(f);
}


int main()
{
    int n = 10000;
    hist_loi_empirique_C4(n);
    hist_loi_theorique_C4();

}