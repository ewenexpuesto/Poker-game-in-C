#include <stdio.h>
#include <stdlib.h>
#include "tache_c9.h"
#include "tache_c10.h"
#include "tache_c11.h"
#include <time.h>


void hist_loi_empirique_C9(int n)
{
    FILE *f = fopen("C11/P_approx_2.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'est bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
        return; // Ajout d'un return facultatif pour éviter de continuer si le fichier ne s'ouvre pas, et donc d'éviter d'allouer de la mémoire inutilement, d'où la fuite mémoire
    }
    fprintf(f,"(C2_1.C2_2),P_approx_2\n"); // Ligne pour les titres des colonnes
    double *tab = P_approx_2(n); //stock les valeurs de P_approx_1(n)

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
    free(tab);
    fclose(f);
}

void hist_loi_empirique_alter_C10(int n)
{
    
    FILE *f = fopen("C11/loi_alter.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'est bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }
    
    fprintf(f,"(C2_1.C2_2),P_approx_2_alter\n"); // Ligne pour les titres des colonnes
    double *tab = P_approx_2_alter(n); //stock les valeurs de P_approx_1(n)

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
    free(tab);
    fclose(f);
}

void hist_loi_theorique_C8()
{
    FILE *f = fopen("C11/loi_theorique.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'eest bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
    }
    fprintf(f,"(C2_1.C2_2),P(C2_1.C2_2)\n"); // Ligne pour les titres des colonnes
    for(int i=1; i<4; i++)
    {
        for (int j=i; j<4; j++)
        {
            tirage t ;
            t.first = i;
            t.second = j;
            fprintf(f, "(%d.%d),%f\n", i,j,P_th_C2_1_C2_2(t));
        }
    }
    fclose(f);
}

void nuage_points_C10()
{
    FILE *f = fopen("C11/nuage_alter_C10.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'eest bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
  
    }
    fprintf(f,"n,P_approx_2_alter(2.3.n)\n"); // Ligne pour les titres des colonnes
    for(int n=1; n<10001; n++)
    {
        fprintf(f, "%d,%f\n",n,P_approx_2_main_alter(2,3,n));
    }
    fclose(f);
    printf("Fichier créé avec succès : nuage_alter_C10.csv\n");
   
}

void nuage_points_alter_C10()
{
    FILE *f = fopen("C11/nuage_C10.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'eest bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
  
    }
    fprintf(f,"n,P_approx_2(2.3.n)\n"); // Ligne pour les titres des colonnes
    for(int n=1; n<10001; n++)
    {
        fprintf(f, "%d,%f\n",n,P_approx_2_main(2,3,n));
    }
    fclose(f);
    printf("Fichier créé avec succès : nuage_C10.csv\n");
   
}