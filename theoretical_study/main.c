#include <stdio.h>
#include <stdlib.h>
#include "tache_c9.h"
#include "tache_c10.h"
#include <time.h>

void hist_loi_empirique_C9(int n)
{
    FILE *f = fopen("P_approx_2.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'est bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
    }
    fprintf(f,"(C2_1.C2_2),P_approx_2(n)\n"); // Ligne pour les titres des colonnes
    double *tab = P_approx_2(n); //stock les valeurs de P_approx_1(n)
    //printf("%f,%f,%f,%f,%f,%f", tab[0],tab[1],tab[2],tab[3],tab[4],tab[5]);
    //printf("Somme: %f\n", tab[0]+tab[1]+tab[2]+tab[3]+tab[4]+tab[5]);
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

void hist_loi_empirique_alter_C10(int n)
{
    
    FILE *f = fopen("loi_alter.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'est bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
    }
    
    fprintf(f,"(C2_1.C2_2),P_approx_2_alter(n)\n"); // Ligne pour les titres des colonnes
    double *tab = P_approx_2_alter(n); //stock les valeurs de P_approx_1(n)
    //printf("%f,%f,%f,%f,%f,%f", tab[0],tab[1],tab[2],tab[3],tab[4],tab[5]);
    //printf("Somme: %f\n", tab[0]+tab[1]+tab[2]+tab[3]+tab[4]+tab[5]);
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
}


int main(){
    srand(time(NULL)); // Initialisation de la graine pour la génération aléatoire
    int n = 10000;
    hist_loi_empirique_C9(n);
    hist_loi_empirique_alter_C10(n);
    
    return 0;
}


