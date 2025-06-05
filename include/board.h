#ifndef BOARD_H
#define BOARD_H

#include "card.h"
#include "player.h"

#define NB_CARDS 20 // DOIT ETRE MULTIPLE DE NB_PLAYERS_TEAM*NB_TEAMS
#define NB_TEAMS 2
#define NB_PLAYERS_TEAM 2
#define NB_JETONS_DEP 20 //tâche E3 nombre de jetons initiale

struct team {
    int team_id;
    player player1;
    player player2;
    int score;
};

/**
 * \brief Une variable de type team permettra d'accéder à toutes les informations relatives à une équipe
 */
typedef struct team team;

struct board {
    team team1;
    team team2;
    card out_of_game_cards[NB_CARDS];
    /*  Tâche E.4  */
    int prime_override; /* 0 = désactivé, 1 = actif pour ce tour */
};

/**
 * \brief Une variable de type board permettra d'accéder à toutes les informations relatives au plateau de jeu
 */
typedef struct board * board;


/**
 * \brief Cette fonction devra allouer la mémoire nécessaire pour créer un nouveau plateau
 * \param 
 * \return un plateau board 
 */
board create_board();

/**
 * \brief Cette fonction devra libérer toute la mémoire allouée au plateau donné en entrée
 * \param b de type board
 * \return rien
 */
void free_board(board b);

/**
 * \brief Cette fonction devra ajouter une équipe au plateau
 * \param b de type board
 * \return void
 */
void add_team(board b);

/**
 * \brief Cette fonction devra renvoyer le nombre d'équipes présentes sur le plateau
 * \param b de type board
 * \return un entier, le nombre de joueurs sur le plateau
 */
int get_number_of_teams(board b);

/**
 * \brief Cette fonction devra ajouter une joueuse à l'équipe dont l'id est team_id
 * \param b de type board
 * \param team_id un entier identifiant l'équipe
 * \param player une joueuse
 * \return void
 */
void add_player_to_team(board b, int team_id, player player);

/**
 * \brief Cette fonction devra renvoyer le nombre de joueuses dans l'équipe dont l'id est team_id
 * \param b de type board
 * \param team_id un entier identifiant l'équipe
 * \return un entier, le nombre de joueuses dans l'équipe
 */
int get_number_of_players_in_team(board b, int team_id);

/**
 * \brief Cette fonction devra renvoyer la joueuse de l'équipe dont l'id est team_id et dont l'indice dans l'équipe est player_index
 * \param b de type board
 * \param team_id un entier identifiant l'équipe
 * \param player_index un entier représentant l'index de la joueuse dans l'équipe, 0 pour la première et 1 pour la deuxième
 * \return une joueuse
 */
player get_player(board b, int team_id, int player_index);

/**
 * \brief Cette fonction devra renvoyer le score de l'équipe dont l'id est team_id
 * \param b de type board
 * \param team_id un entier identifiant l'équipe
 * \return un entier représentant le score de l'équipe
 */
int get_score_of_team(board b, int team_id);

/**
 * \brief Cette fonction devra remplacer le score de l'équipe dont l'id est team_id par la valeur donnée en entrée
 * \param b de type board
 * \param team_id un entier identifiant l'équipe
 * \param score un entier représentant le nouveau score de l'équipe
 * \return void
 */
void set_score_of_team(board b, int team_id, int score);

/**
 * \brief Cette fonction devra ajouter une carte à l'ensemble des cartes mises de côté
 * \param b de type board
 * \param c une carte
 * \return void
 */
void add_out_of_game_card(board b, card c);

/**
 * \brief Cette fonction devra renvoyer le nombre de cartes mises de côté
 * \param b de type board
 * \return un entier, le nombre de cartes mises de côté
 */
int get_number_of_out_of_game_cards(board b);

/**
 * \brief Cette fonction devra renvoyer la carte mise de côté dont l'indice est card_index
 * \param b de type board
 * \param card_index un entier représentant l'index de la carte mise de côté
 * \return une carte
 */
card get_out_of_game_card(board b, int card_index);

/**
 * \brief Cette fonction devra supprimer la carte de l'ensemble des cartes mises de côté
 * \param b de type board
 * \param c une carte
 * \return void
 */
void remove_out_of_game_card(board b, card c);




/* ----------------- Ajout Tâche E.4  ------------------- */

/**
 * \brief  Applique l’effet de la carte spéciale « special ». Cherche l’identifiant de l’effet, vérifie qu’il est valide, puis appelle la fonction correspondante via '\c' effect_table.
 * \param  b        Plateau de jeu courant.
 * \param  p        Joueuse qui a posé la carte spéciale.
 * \param  special  Pointeur vers la carte spéciale jouée.
 * \return rien
 */
void apply_special_effect(board b, player p, card special);

/**
 * \brief  Effet « Thuy Vo » : une carte jouée ce tour devient 1 rouge. Si la cible était une carte spéciale, son pouvoir est annulé.
 * \param  b        Plateau de jeu (non utilisé ici, mais pour homogénéité).
 * \param  p        Joueuse qui déclenche l’effet.
 * \param  special  Carte spéciale elle-même (non modifiée).
 * \return rien
 */
void effect_thuy_vo(board b, player p, card special);

/**
 * \brief  Effet « David Roussel » : une carte devient 2 noir. Neutralise le pouvoir de la cible si c’était une spéciale.
 * \param  b        Plateau de jeu.
 * \param  p        Joueuse qui déclenche l’effet.
 * \param  special  Carte spéciale jouée.
 * \return rien
 */
void effect_david_roussel(board b, player p, card special);

/**
 * \brief  Effet « Abass Sagna » : une carte devient 3 multicolore (‘m’), donc ignorée dans les paris rouge/noir. Neutralise son pouvoir si c’était une spéciale.
 * \param  b        Plateau de jeu.
 * \param  p        Joueuse qui déclenche l’effet.
 * \param  special  Carte spéciale jouée.
 * \return rien
 */
void effect_abass_sagna(board b, player p, card special);

/**
 * \brief  Effet « Laurence Bourard » : inverse tous les paris de valeur (Victoire ↔ Défaite). Les couleurs de pari restent inchangées.
 * \param  b        Plateau de jeu.
 * \param  p        Joueuse qui déclenche l’effet.
 * \param  special  Carte spéciale jouée (non utilisée ici).
 * \return rien
 */
void effect_laurence_bourard(board b, player p, card special);

/**
 * \brief  Effet « Christophe Mouilleron » : si la somme des cartes est un nombre premier, la joueuse gagne son pari quoi qu’il arrive.  Concrètement, on place un drapeau \c prime_override dans le plateau.
 * \param  b        Plateau de jeu (le drapeau est stocké dedans).
 * \param  p        Joueuse qui déclenche l’effet.
 * \param  special  Carte spéciale jouée.
 * \return rien
 */
void effect_christophe_mouilleron(board b, player p, card special);



#endif /* BOARD_H */