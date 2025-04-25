#include <stdio.h>

/** 
\brief :  retourne les valeurs calculées de la tache C5
\param : i et j entiers, cartes de J1, i', j' cartes de J2
\return :  proba que J2 obtienne i', j' sachant que J1 a obtenu i,j
*/
double P_cond(int i_prim, int j_prim, int i, int j);