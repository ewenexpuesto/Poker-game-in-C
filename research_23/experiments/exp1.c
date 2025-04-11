#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probabiliste.h"
#include "player.h"
#include "board.h"
#include "card.h"
#include "interface.h"

#define N_MIN 3
#define N_MAX 20

int main()
{
    FILE *fd = fopen("resultats.csv", "w");
    if (!fd)
    {
        perror("Erreur ouverture fichier resultats.csv");
        return 1;
    }
    fprintf(fd, "n_tours,partie,temps_ms,score_methode\n");
    /*on crée 20 parties */
    for (int i = 0; i < 20; i++)
    {
        srand(time(NULL));
        /*la partie se joue en n tours avec n compris entre 3 et 20*/
        int n = (rand() % 18) + 3;
        clock_t debut = clock();
        int scores = probabiliste(n); /*on lance une partie avec la fonction probabiliste*/
        clock_t fin = clock();
        double temps_ms = ((double)(fin - debut)) * 1000.0 / CLOCKS_PER_SEC;
        fprintf(fd, "%d,%d,%.2f,%d, %d\n", i + 1, n, temps_ms, scores, victoires);
        int victoires = scores[1];
    }
    fclose(fd);
    return 0;
}