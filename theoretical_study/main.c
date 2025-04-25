#include <stdio.h>
#include <stdlib.h>
#include "tache_c9.h"
#include "tache_c10.h"

void hist_loi_empirique_C9(int n)
{
    FILE *f = fopen("P_approx_2.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'est bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
    }
    fprintf(f," C^2_1,C^2_2,P_approx_2(n)\n"); // Ligne pour les titres des colonnes
    double *tab = P_approx_2(n); //stock les valeurs de P_approx_2(n)
    int k =0;
    while(tab[k]<6)
    {
        for (int i=0; i<4; i++)
        {
            for(int j=i; j<4; j++)
            {
                fprintf(f,"%d,%d,%f",i,j, tab[k] );
                k++;
            }
        }
    }
    fclose(f);
}

void hist_loi_empirique_alter_C10(int n)
{
    FILE *f = fopen("loi_alter.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'eest bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
    }
    fprintf(f," C^2_1,C^2_2,P_approx_2_alter(n)\n"); // Ligne pour les titres des colonnes
    double *tab = P_approx_2_alter(n); //stock les valeurs de P_approx_1(n)
    int k =0;
    while(tab[k]<6)
    {
        for (int i=0; i<4; i++)
        {
            for(int j=i; j<4; j++)
            {
                fprintf(f,"%d,%d,%f",i,j, tab[k] );
                k++;
            }
        }
    }
    fclose(f);
}


int main(){
    int n = 10;
    hist_loi_empirique_C9(n);
    hist_loi_empirique_alter_C10(n);
    return 0;
}


