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
    for(int i = 1; i < 4; i++){
        for(int j = 1; j < 4; j++){
            P_B += P_approx_1_main(i,j,n) * P_approx_2_1_main(i_prim,j_prim,i,j,n);
        }
    }
    return P_B;
}

double* P_approx_2_alter(int n){
    double* tab = malloc(6 * sizeof(double));
    double P_B = 0;
    int count = 0;
    for(int k = 0; k < 6;k++ ){
        for(int i = 1; i < 4; i++){
            for(int j = i; j < 4; j++){
                P_B += P_approx_2_1(i,j,n)[count] ;
                //printf(" sachant : %f\n", P_approx_2_1(i,j,n)[count]);
            }
        }
        printf("p_approx %f \n : ",P_approx_1(n)[count]);
        tab[count] = P_B * P_approx_1(n)[count];
        //printf(" tab : %f\n", tab[count]);
        P_B = 0;
        count++;
    }

    printf(" somme :%f \n", P_approx_1(n)[0] + P_approx_1(n)[1] + P_approx_1(n)[2] + P_approx_1(n)[3] + P_approx_1(n)[4] + P_approx_1(n)[5]);
    return tab;
}


