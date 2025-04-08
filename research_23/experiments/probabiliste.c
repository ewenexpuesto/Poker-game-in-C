#include "probabiliste.h"
#include "../../include/board.h"
#include "../../include/card.h"
#include "../../include/player.h"
#include "../../include/interface.h"

#define NB_TEAMS 2
#define NB_PLAYERS_TEAM 2
#define NB_ROUNDS 3
#define NB_CARDS 20

// HERE where the main is modified

int agressive_method(int player_id_1, int player_id_2) {

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
        /* Phase de pari */

        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);

                // HERE
                card smallest_card = get_card_in_hand(p, 0);
                card highest_card = get_card_in_hand(p, 0);
                for (int k = 1; k < get_size_of_hand(p); k++) {
                    card current_card = get_card_in_hand(p, k);
                    if (get_value(current_card) > get_value(highest_card)) {
                        highest_card = current_card;
                    }
                    if (get_value(current_card) < get_value(smallest_card)) {
                        smallest_card = current_card;
                    }
                }
                int value_of_smallest_card = get_value(smallest_card);
                int value_of_highest_card = get_value(highest_card);
                int gamble;
                if (value_of_smallest_card - 1 >= 5 - value_of_highest_card) {
                    int gamble = 1; // Victoire
                }
                else {
                    int gamble = 0; // Défaite
                }

                set_slate(p, gamble);
            
            }
        }

        /* Phase de jeu */

        int team_scores[NB_TEAMS] = {0, 0};

        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);

                // HERE
                int gamble = get_slate(p);
                if (gamble == 1) {
                    // Play the two highest cards if there are two cards left or else play the only card
                    if (get_size_of_hand(p) == 2) {
                        card highest_card_1 = get_card_in_hand(p, 0);
                        card highest_card_2 = get_card_in_hand(p, 1);

                        for (int k = 2; k < get_size_of_hand(p); k++) {
                            card current_card = get_card_in_hand(p, k);
                            if (get_value(current_card) > get_value(highest_card_1)) {
                                highest_card_2 = highest_card_1;
                                highest_card_1 = current_card;
                            } else if (get_value(current_card) > get_value(highest_card_2)) {
                                highest_card_2 = current_card;
                            }
                        }
                        play_card(p, highest_card_1);
                        remove_card_from_hand(p, highest_card_1);
                        play_card(p, highest_card_2);
                        remove_card_from_hand(p, highest_card_2);
                        team_scores[i] += get_value(highest_card_1) + get_value(highest_card_2);
                    } else if (get_size_of_hand(p) == 1) {
                        card only_card = get_card_in_hand(p, 0);
                        play_card(p, only_card);
                        remove_card_from_hand(p, only_card);
                        team_scores[i] += get_value(only_card);
                    }
                } else {
                    // Play the lowest card
                    card smallest_card = get_card_in_hand(p, 0);
                    for (int k = 1; k < get_size_of_hand(p); k++) {
                        card current_card = get_card_in_hand(p, k);
                        if (get_value(current_card) < get_value(smallest_card)) {
                            smallest_card = current_card;
                        }
                    }
                    play_card(p, smallest_card);
                    remove_card_from_hand(p, smallest_card);
                    team_scores[i] += get_value(smallest_card);
                }
            }
        }

        /* Détermination du gagnant du tour */

        int max_score = 0;
        int winning_team = 1;

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

int probabiliste_method() {

}

int probabiliste(int * distrib, int nb_teams, int nb_card_each_turn) {

}

