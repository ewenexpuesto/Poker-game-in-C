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

    /* Créaion des 20 cartes pour chaque joueuse*/
    unsigned int nb_card_tot = 20;
    card *tab_card = malloc(nb_card_tot * sizeof(card)); 

    for(int i = 0; i < nb_card_tot; i++){
        tab_card[i] = create_card();
    }

    /* Ajout des 5 cartes par joueuse */
    unsigned int nb_card_start = 5;

    for(unsigned int i = 0; i < nb_player; i++){
        for(unsigned int j = 0; j < nb_card_start; j++){
            add_card_to_hand(p[i],tab_card[j + 5*i]);
        }
    }

    /*Affichage du jeu */

    display_board(b);

    /* Paris */

    int tab_paris_1[nb_player];
    int tab_paris_2[nb_player];

    for(int i = 0; i < nb_player; i++){
        tab_paris_1[i] = get_slate(p[i]);
    }
    

    for(int i = 0; i < nb_player; i++){
        tab_paris_2[i] = get_slate(p[i]);
    }
    

    /* Placement des cartes et comparaison */
    int  
    scanf()
    for(int i = 0; i < nb_player; i++){
        play_card(p[i], )
    }

}



