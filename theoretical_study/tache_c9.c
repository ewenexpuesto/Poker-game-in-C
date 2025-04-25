#include <stdio.h>
#include <stdlib.h>
#include "tache_c3.h"
#include "tache_c6.h"
tirage main_J2_incond(){
    tirage t1= main_J1();
    int n=t1.first;
    int m=t1.second;
    int*cartes=malloc(2*sizeof(int));
    cartes=main_J2(n,m);
    tirage t2={cartes[1], cartes[2]};
    return t2;
}

double P_approx_2_main(int i, int j, int n){
    int proportion_i_j =0;
    for(int k=0; k<n; k++){
        tirage t = main_J2_incond();
        if ((t.first == i && t.second == j) || (t.first == j && t.second == i)) {
            proportion_i_j++;
        }
    }
    return (double)proportion_i_j / n;
}

double* P_approx_2(int n){
    double * proportion = (double *) calloc(6, sizeof(double));
    proportion[0] = P_approx_2_main(1,1,n);
    proportion[1] = P_approx_2_main(1,2,n);
    proportion[2] = P_approx_2_main(1,3,n);
    proportion[3] = P_approx_2_main(2,2,n);
    proportion[4] = P_approx_2_main(2,3,n);
    proportion[5] = P_approx_2_main(3,3,n);
    if (proportion[0] + proportion[1] + proportion[2] + proportion[3] + proportion[4] + proportion[5] != 1) {
        printf("Erreur : la somme des probabilités n'est pas égale à 1.\n");
    }
    return proportion;
}