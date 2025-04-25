#ifndef PROBABILITY_OF_HAND_EMPIRIC_H
#define PROBABILITY_OF_HAND_EMPIRIC_H

tirage distrib(int * pioche);

tirage main_J1 ();

double P_approx_1_main(int i,int j, int n);

double * P_approx_1(int n);

double P(tirage t);

#endif