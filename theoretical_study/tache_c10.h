#include <stdio.h>
#include <stdlib.h>
#include "tache_c3.h"

/* Tâche C.10 */

/**
 * \brief : Calcule la proportion de mains obtenues par J2.
 * \param : i' et j' entiers, cartes de J2
 * \return : la proportion des mains obtenues par J2
 */

 double P_approx_2_1_alter(int i_prim, int j_prim, int n);

/**
 * \brief : Calcule la proportion de mains obtenues par J2.
 * \param : n entier, nombre de cartes
 * \return : la proportion des mains obtenues par J2
 */

 double* P_approx_2_alter(int n);

 /**
 * \brief Calcule la probabilité de tirer deux cartes données en entrée.
 * \param t un couple de cartes de type tirage
 * \return la probabilité d'obtenir ce couple de cartes
 */

double P_th_C2_1_C2_2(tirage t);