#include <stdio.h>
#include <stdlib.h>
#include "tache_c11.h"
#include <time.h>


int main(){
    srand(time(NULL)); // Initialisation de la graine pour la génération aléatoire
    int n = 100000;
    hist_loi_empirique_C9(n);
    hist_loi_empirique_alter_C10(n);
    hist_loi_theorique_C8();
    nuage_points_C10();
    nuage_points_alter_C10();
    return 0;
}


