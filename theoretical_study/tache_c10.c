#include <stdio.h>
#include <stdlib.h>
#include "tache_c3.h"
#include "tache_c6.h"

/* Tâche C.10 */

/**
 * Retourne la proportion des mains obtenues par J2
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


