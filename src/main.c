#include <stdio.h>
#include <stdlib.h>
#include "../include/board.h"
#include "../include/card.h"
#include "../include/player.h"
#include "../include/interface.h"

#define NUM_TEAMS 2
#define NB_PLAYERS_TEAM 2
#define NB_ROUNDS 3

int main() {
    // Initialisation du plateau
    board b = create_board();
    
    // Ajout des équipes et des joueuses
    for (int i = 0; i < NUM_TEAMS; i++) {
        add_team(b);
        for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
            player p = create_player();
            add_player_to_team(b, i, p);
            // Distribution des cartes (exemple avec 5 cartes par joueuse)
            for (int k = 0; k < 5; k++) {
                card c = create_card();
                set_value(c, (k + 1)); // Exemple de distribution
                add_card_to_hand(p, c);
            }
        }
    }
    
    // Déroulement des tours
    for (int round = 0; round < NB_ROUNDS; round++) {
        display_board(b);
        
        // Phase de pari
        for (int i = 0; i < NUM_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);
                int gamble = ask_gamble(p);
                set_slate(p, gamble);
            }
        }
        
        // Phase de jeu
        int team_scores[NUM_TEAMS] = {0, 0};
        for (int i = 0; i < NUM_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);
                int num_cards = ask_number_of_played_cards(p);
                for (int k = 0; k < num_cards; k++) {
                    card c = ask_card(p);
                    play_card(p, c);
                    team_scores[i] += get_value(c);
                }
            }
        }
        
        // Détermination du gagnant du tour
        int max_score = 0, winning_team = -1;
        for (int i = 0; i < NUM_TEAMS; i++) {
            if (team_scores[i] > max_score) {
                max_score = team_scores[i];
                winning_team = i;
            }
        }
        
        // Attribution des points
        for (int i = 0; i < NUM_TEAMS; i++) {
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
    
    // Fin du jeu
    display_end_game(b);
    
    // Libération de la mémoire
    free_board(b);
    return 0;
}