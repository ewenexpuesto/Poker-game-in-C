#include <stdio.h>              
#include <stdlib.h>
#include <time.h>
#include <stdint.h> 
#include "../include/board.h"
#include "../include/card.h"
#include "../include/player.h"
#include "../include/interface.h"

#define NB_TEAMS 2
#define NB_PLAYERS_TEAM 2
#define NB_ROUNDS 3
//#define NB_CARDS 20 // déjà défini dans board.h

int main() {

    /* Initialisation du plateau */
    display_message("Le jeu va commencer \n");

    board b = create_board();
    
    /* Ajout des équipes et des joueuses */
    int count = 0;
    
    card* card_tot = malloc(20 * sizeof(card));
    if (card_tot == NULL) {
        printf("Error: memory allocation failed for card_tot\n");
    }

    /* ---------- AJOUT Tâche E.4  ---------- */
    int NB_SPECIALS = NB_PLAYERS_TEAM * NB_TEAMS;   /* 1 par joueuse */
    effect_id all_effects[] = {
    EFF_THUY_VO, EFF_DAVID_ROUSSEL, EFF_ABASS_SAGNA,
    EFF_LAURENCE_BOURARD, EFF_ANNE_LAURE_LIGOZAT,
    EFF_VINCENT_FAGNON,  EFF_VALENTIN_HONORE,
    EFF_FETIA_BANNOUR,   EFF_CHRISTOPHE_MOUILLERON,
    EFF_DJIBRIL_AURELIEN, EFF_LUCIENNE_PACAVE,
    EFF_LAWANDA_GAYDU,   EFF_MATHILDE_MOUGEOT,
    EFF_DIMITRI_WATEL,   EFF_CYRIL_BENEZET,
    EFF_MARIE_SZA
    };
    /* On choisit NB_SPECIALS effets distincts au hasard*/
    int nb_effects = sizeof(all_effects)/sizeof(all_effects[0]);
    for (int s = 0; s < NB_SPECIALS; ++s) 
    {
        int r = rand() % (nb_effects - s); /* indice restant */
        effect_id id = all_effects[r];
        all_effects[r] = all_effects[nb_effects - 1 - s];  /* retire l’effet */
        card_tot[count++] = create_special_card(id);
    }
/* ------------------------------------------------------------------ */

    for (int i = 0; i < NB_TEAMS; i++) {
        add_team(b);
        for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
            player p = create_player();
            add_player_to_team(b, i, p);

            /* Création des cartes */

            for (int k = 0; k < 5; k++) {
                card c = create_card();
                set_value(c, (k + 1)); 
                if (i == 0) {
                    set_colour(c, 'r');
                }
                else if (i == 1) {
                    set_colour(c, 'n');
                }
                else {
                    printf("Erreur : couleur de carte non définie\n");
                }
                card_tot[count] = c;
                count++;
            }
        }
    }

     /* Distribution des cartes */
     int index[NB_CARDS];

     srand(time(NULL) ^ (intptr_t)NB_CARDS); // Graine plus aléatoire

     
    for (int i = 0; i < NB_CARDS; i++) {
        index[i] = i;
    }

    for (int i = NB_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = index[i];
        index[i] = index[j];
        index[j] = temp;
    }

    count = 0;

    for (int i = 0; i < NB_TEAMS; i++) {
        for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
            for (int k = 0; k < 5; k++) {
                player p = get_player(b, i, j); 
                card c = card_tot[index[count]];
                add_card_to_hand(p, c);
                count++;
            }
        }
    }

    /* Déroulement des tours */

    for (int round = 0; round < NB_ROUNDS; round++) {
        display_board(b);
        
        /* Phase de pari */

        display_message("\n\nLe pari de valeur à noter est \"v\" pour victoire ou \"d\" pour Défaite. \nLe pari de couleur à noter est \"r\" pour rouge, \"n\" pour noir ou \"m\" pour multicolore\n\n");

        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);
                int gamble = ask_gamble(p);
                char colour = ask_colour();
                int mise = ask_mise(p); /*Tâche E3*/
                set_mise(p, mise);  /*Tâche E3*/
                set_slate_colour(p, colour);
                set_slate(p, gamble);
            }
        }
        
        /* Phase de jeu */

        int team_scores[NB_TEAMS] = {NB_JETONS_DEP, NB_JETONS_DEP};

        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);
                int nb_cards = ask_number_of_played_cards(p);

                while (nb_cards > 2 || nb_cards < 1) {
                    display_message("Nombre de cartes à jouer invalide");
                    nb_cards = ask_number_of_played_cards(p);
                }

                if (nb_cards == 1) {
                    card c = ask_card(p);
                    play_card(p, c);
                    add_out_of_game_card(b,c);
                    remove_card_from_hand(p,c);
                    int mise = get_mise(p); /*Tâche E3*/
                    if (get_card_colour(c) == get_slate_colour(p)) {
                        aug_jetons(p, mise);        /*Tâche E3*/
                        team_scores[i] += get_mise(p);
                    }
                    else if (get_slate_colour(p) == 'm') {
                        aug_jetons(p,mise);     /*Tâche E3*/
                        team_scores[i] += get_mise(p);
                    }
                    else {
                        sub_jetons(p, mise);        /*Tâche E3*/
                        team_scores[i] -= get_mise(p);
                    }
                    //printf("%d\n", team_scores[i]);
                }

                else{
                    card c1 = ask_card(p);
                    card c2 = ask_card(p);  

                    while (c1 == c2){
                        display_message("Vous avez joué 2 fois la même carte, veuillez jouer une autre carte");
                        c2 = ask_card(p);
                    }

                    //printf("c2 : %d\n", get_value(c2));        
                    play_card(p, c1);
                    play_card(p, c2);
                    int mise = get_mise(p);
                    if (get_card_colour(c1) == get_slate_colour(p)) {
                        aug_jetons(p,mise);
                        team_scores[i] += get_mise(p);
                    }
                    else if (get_slate_colour(p) == 'm') {
                        aug_jetons(p,mise);
                        team_scores[i] += get_mise(p);
                    }
                    else {
                        sub_jetons(p,mise);
                        team_scores[i] -= get_mise(p);
                    }
                    //printf("%d\n", team_scores[i]);
                    if (get_card_colour(c2) == get_slate_colour(p)) {
                        aug_jetons(p,mise);
                        team_scores[i] += get_mise(p);
                    }
                    else if (get_slate_colour(p) == 'm') {
                        aug_jetons(p,mise);
                        team_scores[i] += get_mise(p);
                    }
                    else {
                        sub_jetons(p,mise);
                        team_scores[i] -= get_mise(p);
                    }
                    //printf("%d\n", team_scores[i]);

                    ///add_out_of_game_card(b,c1);
                    //add_out_of_game_card(b,c2);

                    remove_card_from_hand(p, c1);
                    remove_card_from_hand(p, c2);
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
        // Regarde s'il y a égalité en toutes les équipes
        int draw = 1; // Suppose égalité au départ

        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = i + 1; j < NB_TEAMS; j++) { // j = i + 1 pour éviter i == j
                if (team_scores[i] != team_scores[j]) {
                    draw = 0; // Pas d'égalité
                    break;
                }
            }
            if (!draw) break; // Sortir aussi de la boucle extérieure
        }
        
        if (draw) {
            winning_team = -1;
            display_message("Il y a égalité pour ce round");
        }
        
        /* Attribution des points */

        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);
                int gamble = get_slate(p);
                if (winning_team == i && gamble == 1) {
                    set_score_of_team(b, i, get_score_of_team(b, i) + 1);
                } 
                else if (winning_team != i && gamble == 0) {
                    set_score_of_team(b, i, get_score_of_team(b, i) + 1);
                }
                else if (winning_team == -1) {
                    set_score_of_team(b, i, get_score_of_team(b, i) + 1);
                } // si égalité, toute le monde gagne
            }
        }
        display_message("\nFin du tour ---------------------------------------------------\n");
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
        card c = get_card_by_id(i);
        free_card(c);
    }
    free(card_tot);


    free_board(b);

    reset_player_id_counter();
    reset_card_id_counter();
    reset_global_array1();
    reset_global_array2();

    
    return 0;
}