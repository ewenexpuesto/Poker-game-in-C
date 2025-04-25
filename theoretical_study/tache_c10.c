#include <stdio.h>
#include <stdlib.h>
#include "tache_c3.h"
#include "tache_c6.h"

/* Tâche C.10 */

/**
 * Retourne la proportion des mains obtenues par J2
 */

double P_approx_2_1_alter(int i_prim, int j_prim, int n){
    double P_B = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            P_B += P_approx_1_main(i,j,n) * P_approx_2_1_main(i_prim,j_prim,i,j,n);
        }
    }
    return P_B;
}

double* P_approx_2_alter(int n){
    double* tab = malloc(6 * sizeof(double));
    double P_B = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            P_B = P_approx_2_1(i,j,n)[count];
            tab[count] = P_B;
            count++;
        }
    }

    return tab;
}


