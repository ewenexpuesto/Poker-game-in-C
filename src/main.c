#include <stdio.h>
#include <stdlib.h>
#include "../include/board.h"
#include "../include/card.h"
#include "../include/player.h"
#include "../include/interface.h"

#define NB_TEAMS 2
#define NB_PLAYERS_TEAM 2
#define NB_ROUNDS 3
#define NB_CARDS 20

int main() {

    /* Initialisation du plateau */

    board b = create_board();
    
    /* Ajout des équipes et des joueuses */
    int all_card_id[NB_CARDS];
    int count = 0;

    for (int i = 0; i < NB_TEAMS; i++) {
        add_team(b);
        for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
            player p = create_player();
            add_player_to_team(b, i, p);

            /* Distribution des cartes */

            for (int k = 0; k < 5; k++) {
                card c = create_card();
                set_value(c, (k + 1)); 
                add_card_to_hand(p, c);
                all_card_id[count] = get_card_id(c);
                count++;
            }
        }
    }
    
    /* Déroulement des tours */

    for (int round = 0; round < NB_ROUNDS; round++) {
        display_board(b);
        
        /* Phase de pari */

        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);
                int gamble = ask_gamble(p);
                set_slate(p, gamble);
            }
        }
        
        /* Phase de jeu */

        int team_scores[NB_TEAMS] = {0, 0};

        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);
                int nb_cards = ask_number_of_played_cards(p);
                for (int k = 0; k < nb_cards; k++) {
                    card c = ask_card(p);
                    play_card(p, c);
                    remove_card_from_hand(p,c);
                    team_scores[i] += get_value(c);
                }
            }
        }
        
        /* Détermination du gagnant du tour */

        int max_score = 0;
        int winning_team = 1;

        if(team_scores[0] == team_scores[1]){
            display_message("Il y a égalité");
        }

        for (int i = 0; i < NB_TEAMS; i++) {
            if (team_scores[i] > max_score) {
                max_score = team_scores[i];
                winning_team = i;
            }
        }
        
        /* Attribution des points */

        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);
                int gamble = get_slate(p);
                if (winning_team == i && gamble == 1) {
                    set_score_of_team(b, i, get_score_of_team(b, i) + 1);
                } else if (winning_team != i && gamble == 0) {
                    set_score_of_team(b, i, get_score_of_team(b, i) + 1);
                }
            }
        }
    }
    
    /* Fin du jeu */
    display_end_game(b);
    
    /* Libération de la mémoire  */
    for (int i = 0; i < NB_TEAMS; i++) {
        for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
            player p = get_player(b, i, j);

            free_player(p);
        }
    }

    for(int i = 0; i < NB_CARDS; i++){
        card c = get_card_by_id(all_card_id[i]);
        free_card(c);
    }

    free_board(b);
    
    return 0;
}