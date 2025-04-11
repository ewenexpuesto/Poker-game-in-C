#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probabiliste.h"
#include "player.h"
#include "board.h"
#include "card.h"
#include "interface.h"

#define N_MIN 3
#define N_MAX 60

int main()
{
    printf("ca commence");
    FILE *fd = fopen("resultats1.csv", "w");
    
    if (!fd)
    {
        perror("Erreur ouverture fichier resultats.csv");
        return 1;
    }
    fprintf(fd, "ième partie, n_tours,partie,temps_ms,scores, victoires\n");
    /*on crée 20 parties */
    for (int i = 0; i < 60; i++)
    {
        srand(time(NULL));
        /*la partie se joue en n tours avec n compris entre 3 et 20*/
        int n = (rand() % 18) + 3;
        printf("n :%d", n);
        clock_t debut = clock();
        int scores = probabiliste(n); /*on lance une partie avec la fonction probabiliste*/
        printf("scores : %d", scores);
        clock_t fin = clock();
        double temps_ms = ((double)(fin - debut)) * 1000.0 / CLOCKS_PER_SEC;
        int victoires = scores[1];
        fprintf(fd, "%d,%d,%.2f,%d, %d\n", i + 1, n, temps_ms, scores, victoires);
    }
    fclose(fd);
    return 0;
}