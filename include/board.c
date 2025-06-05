#include "../include/board.h"
#include "../include/card.h"
#include "../include/player.h"


board create_board() {
    board b = malloc(sizeof(*b));
    b->team1.team_id = -1;
    b->team2.team_id = -1;
    b->team1.score = 0;
    b->team2.score = 0;
    b->team1.player1 = NULL;
    b->team1.player2 = NULL;
    b->team2.player1 = NULL;
    b->team2.player2 = NULL;
    for (int i = 0; i < NB_CARDS; i++) {
        b->out_of_game_cards[i] = 0;
    }
    return b;
}

void free_board(board b) {
    free(b);
}

void add_team(board b) {
    if (b->team1.team_id == -1) {
        b->team1.team_id = 0;
    }

    else if (b->team2.team_id == -1) {
        b->team2.team_id = 1;
    }
    else {
        printf("Error: too many teams\n");
    }
}

int get_number_of_teams(board b) {
    int count = 0;
    if (b->team1.team_id != -1) {
        count++;
    }
    if (b->team2.team_id != -1) {
        count++;
    }
    return count;
}

void add_player_to_team(board b, int team_id, player player) {
    if (b->team1.team_id == team_id) {
        if (b->team1.player1 == NULL) {
            b->team1.player1 = player;
        }
        else if (b->team1.player2 == NULL) {
            b->team1.player2 = player;
        }
        else {
            printf("Error: too many players\n");
        }
    }
    
    if (b->team2.team_id == team_id) {
        if (b->team2.player1 == NULL) {
            b->team2.player1 = player;
        }
        else if (b->team2.player2 == NULL) {
            b->team2.player2 = player;
        }
        else {
            printf("Error: too many players\n");
        }
    }

    if(!(b->team1.team_id == team_id) && !(b->team2.team_id == team_id)) {
        printf("Error: wrong team id\n");
    }

}

int get_number_of_players_in_team(board b, int team_id) {
    int count = 0;
    if (b->team1.team_id == team_id) {
        if (b->team1.player1 != NULL) {
            count++;
        }
        if (b->team1.player2 != NULL) {
            count++;
        }
    }
    else if (b->team2.team_id == team_id) {
        if (b->team2.player1 != NULL) {
            count++;
        }
        if (b->team2.player2 != NULL) {
            count++;
        }
    }
    return count;
}

player get_player(board b, int team_id, int player_index) {
    if (b->team1.team_id == team_id) {
        if (player_index == 0) {
            return b->team1.player1;
        }
        else if (player_index == 1) {
            return b->team1.player2;
        }
        else {
            printf("Error: wrong player index\n");
        }
    }
    else if (b->team2.team_id == team_id) {
        if (player_index == 0) {
            return b->team2.player1;
        }
        else if (player_index == 1) {
            return b->team2.player2;
        }
        else {
            printf("Error: wrong player index\n");
        }
    }
    else {
        printf("Error: wrong team id\n");
    }
    printf("Unknown error in get_player\n");
    return NULL;
}

int get_score_of_team(board b, int team_id) {
    if (b->team1.team_id == team_id) {
        return b->team1.score;
    }
    else if (b->team2.team_id == team_id) {
        return b->team2.score;
    }
    else {
        printf("Error: wrong team id\n");
        return -1;
    }
    printf("Unknown error in get_score_of_team\n");
    return -1;
}

void set_score_of_team(board b, int team_id, int score) {
    if (b->team1.team_id == team_id) {
        b->team1.score = score;
    }
    else if (b->team2.team_id == team_id) {
        b->team2.score = score;
    }
    else {
        printf("Error: wrong team id\n");
        return;
    }
}

void add_out_of_game_card(board b, card c) {
    // On récupère le nombre actuel de cartes hors jeu
    int count = get_number_of_out_of_game_cards(b);
    
    // On vérifie si le tableau n'est pas plein
    if (count < NB_CARDS) {
        b->out_of_game_cards[count] = c;
    }
    else {
        printf("Error: out of game cards array is full\n");
    }
}

int get_number_of_out_of_game_cards(board b) {
    int count = 0;
    
    // On parcourt le tableau jusqu'à trouver une carte nulle (0)
    // ou jusqu'à atteindre la fin du tableau
    while (count < NB_CARDS && b->out_of_game_cards[count] != 0) {
        count++;
    }
    
    return count;
}

card get_out_of_game_card(board b, int card_index) {
    if (b->out_of_game_cards[card_index] == 0) {
        printf("Error: no card at this index\n");
        return NULL;
    }
    return b->out_of_game_cards[card_index];
}

void remove_out_of_game_card(board b, card c) {
    int i = 0;
    while (b->out_of_game_cards[i] != c) {
        i++;
        if (i >= NB_CARDS) {
            printf("Error: card not found\n");
            return;
        }
    }
    b->out_of_game_cards[i] = 0;
}



/* ----------------- Ajout Tâche E.4  ------------------- */

/**
 * \brief  Tableau de dispatch des effets spéciaux. À l’indice i se trouve le pointeur de fonction qui implémente l’effet dont l’identifiant est i (voir enum effect_id). Une entrée NULL signifie : effet non implémenté.
 * \param  // rien
 * \return rien
 */
static void (* const effect_table[NB_EFFECTS])(board, player, card) = 
{
    NULL,
    effect_thuy_vo,
    effect_david_roussel,
    effect_abass_sagna,
    effect_laurence_bourard,
    effect_christophe_mouilleron
};

/**
 * \brief  Applique l’effet de la carte spéciale « special ». Cherche l’identifiant de l’effet, vérifie qu’il est valide, puis appelle la fonction correspondante via '\c' effect_table.
 * \param  b        Plateau de jeu courant.
 * \param  p        Joueuse qui a posé la carte spéciale.
 * \param  special  Pointeur vers la carte spéciale jouée.
 * \return rien
 */
void apply_special_effect(board b, player p, card special)
{
    effect_id id = get_effect_id(special);
    if (id == NO_EFFECT || id >= NB_EFFECTS) return;
    if (effect_table[id])
        effect_table[id](b, p, special);
}

/**
 * \brief  Effet « Thuy Vo » : une carte jouée ce tour devient 1 rouge. Si la cible était une carte spéciale, son pouvoir est annulé.
 * \param  b        Plateau de jeu (non utilisé ici, mais pour homogénéité).
 * \param  p        Joueuse qui déclenche l’effet.
 * \param  special  Carte spéciale elle-même (non modifiée).
 * \return rien
 */
void effect_thuy_vo(board b, player p, card special)
{
    display_message("[Thuy Vo] choisissez une carte jouée ce tour :");
    card target = ask_card(p);
    set_value(target, 1);
    set_colour(target, 'r');
    target->eff = NO_EFFECT;
}

/**
 * \brief  Effet « David Roussel » : une carte devient 2 noir. Neutralise le pouvoir de la cible si c’était une spéciale.
 * \param  b        Plateau de jeu.
 * \param  p        Joueuse qui déclenche l’effet.
 * \param  special  Carte spéciale jouée.
 * \return rien
 */
void effect_david_roussel(board b, player p, card special)
{
    display_message("[David Roussel] Sélectionnez une carte jouée ce tour.");
    card target = ask_card(p);
    set_value (target, 2);
    set_colour(target, 'n');
    if (is_special(target))
    {
        target->eff = NO_EFFECT;
    }
}

/**
 * \brief  Effet « Abass Sagna » : une carte devient 3 multicolore (‘m’), donc ignorée dans les paris rouge/noir. Neutralise son pouvoir si c’était une spéciale.
 * \param  b        Plateau de jeu.
 * \param  p        Joueuse qui déclenche l’effet.
 * \param  special  Carte spéciale jouée.
 * \return rien
 */
void effect_abass_sagna(board b, player p, card special)
{
    display_message("[Abass Sagna] Sélectionnez une carte jouée ce tour.");
    card target = ask_card(p);
    set_value (target, 3);
    set_colour(target, 'm');
    if (is_special(target))
    {
        target->eff = NO_EFFECT;
    }   
}

/**
 * \brief  Effet « Laurence Bourard » : inverse tous les paris de valeur (Victoire ↔ Défaite). Les couleurs de pari restent inchangées.
 * \param  b        Plateau de jeu.
 * \param  p        Joueuse qui déclenche l’effet.
 * \param  special  Carte spéciale jouée (non utilisée ici).
 * \return rien
 */
void effect_laurence_bourard(board b, player p, card special)
{
    display_message("[Laurence Bourard] Inversion des paris !");
    for (int t = 0; t < NB_TEAMS; t++)
        for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
            player pl = get_player(b, t, j);
            int old = get_slate(pl);
            if (old != -1) set_slate(pl, 1 - old);
        }
}

/**
 * \brief  Effet « Christophe Mouilleron » : si la somme des cartes est un nombre premier, la joueuse gagne son pari quoi qu’il arrive.  Concrètement, on place un drapeau \c prime_override dans le plateau.
 * \param  b        Plateau de jeu (le drapeau est stocké dedans).
 * \param  p        Joueuse qui déclenche l’effet.
 * \param  special  Carte spéciale jouée.
 * \return rien
 */
void effect_christophe_mouilleron(board b, player p, card special)
{
    display_message("[Christophe Mouilleron] Prime aux nombres premiers !");
    b->prime_override = 1;
}
