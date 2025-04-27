#include <stdio.h>
#include <stdlib.h>
#include "tache_c3.h"
#include "tache_c6.h"

/* Tâche C.10 */

/**
 * \brief Calcule la probabilité d'obtenir un couple de cartes donné
 * \param i_prim le premier élément du couple
 * \param j_prim le deuxième élément du couple
 * \param i le premier élément du couple de cartes
 * \param j le deuxième élément du couple de cartes
 * \param n le nombre de tirages
 * \return la probabilité d'obtenir ce couple de cartes
 */
double P_approx_2_main_alter(int i_prim, int j_prim, int n){
    double P_B = 0;
    for(int i = 1; i <= 3; i++){
        for(int j = i; j <= 3; j++){
            P_B += P_approx_1_main(i,j,n) * P_approx_2_1_main(i_prim,j_prim,i,j,n);
        }
    }
    return P_B;
}

/**
 * \brief Calcule la probabilité d'obtenir tous les couples de cartes
 * \param n le nombre de tirages
 * \return une liste, qui est la probabilité d'obtenir tous les couples de cartes
 */

double* P_approx_2_alter(int n){
    double * proportion = (double *) calloc(6, sizeof(double));
    proportion[0] = P_approx_2_main_alter(1,1,n);
    proportion[1] = P_approx_2_main_alter(1,2,n);
    proportion[2] = P_approx_2_main_alter(1,3,n);
    proportion[3] = P_approx_2_main_alter(2,2,n);
    proportion[4] = P_approx_2_main_alter(2,3,n);
    proportion[5] = P_approx_2_main_alter(3,3,n);
    return proportion;
}

/**
 * \brief Calcule la probabilité de tirer deux cartes données en entrée.
 * \param t un couple de cartes de type tirage
 * \return la probabilité d'obtenir ce couple de cartes
 */

double P_th_C2_1_C2_2(tirage t) {
    if ((t.first == 1 && t.second == 1) || 
        (t.first == 2 && t.second == 2) || 
        (t.first == 3 && t.second == 3)) {
        return 1.0 / 15.0;
    } 
    else if ((t.first == 1 && t.second == 2) || 
             (t.first == 1 && t.second == 3) || 
             (t.first == 2 && t.second == 3)) {
        return 4.0 / 15.0;
    } 
    else {
        printf("Erreur : couple de cartes non défini.\n");
        return 0.0;
    }
}


