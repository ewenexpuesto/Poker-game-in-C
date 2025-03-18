#include "../include/board.h"
#include "../include/card.h"
#include "../include/player.h"
#include "../include/interface.h"

#define nb_player 4

int main(){

    /* Création des 4 joueuses*/

    /*
    player p1 = create_player();
    player p2 = create_player();
    player p3 = create_player();
    player p4 = create_player();

     */

     /* ça pue la fuite mémoire*/

    player p[nb_player];

    for(int i = 0; i < nb_player; i++){
        p[i] = create_player();
    }
    
    /* Création du tableau des scores */

    board b = create_board();

    /* Ajout des 2 équipes*/

    add_team(b);
    add_team(b);

    /* Créaion des 60 cartes pour chaque joueuse*/

    /* ça pue la fuite mémoire encore*/
    card **tab_card = malloc(nb_player * sizeof(card)); 
    unsigned int nb_card = 20;

    for(int i = 0; i < nb_card; i++){
        tab_card[i] = create_card();
        }
    }

    /* Paris */

    int *slate[4];

    for(int i = 0; i < nb_player; i++){
        
    }
    
}



