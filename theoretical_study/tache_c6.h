#ifndef TACHE_C6_H
#define TACHE_C6_H
/** 
\brief :  simule la distribution des cartes à J2 en prenant en argument la main (i,j) de J1
\param : i et j entiers, cartes de J1
*/
int* main_J2(int i, int j);

double P_approx_2_1_main(int i_prim, int j_prim, int i, int j, int n);

double* P_approx_2_1(int i, int j ,int n);


#endif
