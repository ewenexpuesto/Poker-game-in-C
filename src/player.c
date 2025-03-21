#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "card.h"

struct player_s
{
    card *cards_in_hand;
    int hand;
    card *cards_on_table;
    int table;
    int ardoise; /*1 =la joueuse a parié victoire et 0=la joueuse a parié défaite */
    int id;
    int team_id;
};

int creation_id()
{
    static int id = 0;
    return id;
    id++;
}

player player_tab[4];

player create_player()
{
    player p = malloc(sizeof(struct player_s));
    if (p == NULL)
    {
        perror("Erreur durant l'allocation");
        exit(1);
    }
    p->cards_in_hand = malloc(6 * sizeof(card));
    p->hand = 0;
    p->cards_on_table = NULL;
    p->table = 0;
    p->ardoise = 0;
    p->id = creation_id();
    player_tab[p->id] = p;
    return p;
};

void free_player(player p)
{
    free(p->cards_in_hand);
    free(p->cards_on_table);
    free(p);
}

int get_player_id(player p)
{
    return p->id;
}

player get_player_by_id(int n)
{
    if (n >= 0 && n < 4)
    {
        return player_tab[n];
    }
    return NULL;
}

void add_card_to_hand(player p, card c)
{
    p->cards_in_hand[p->hand] = c;
    p->hand++;
}

int get_size_of_hand(player p)
{
    return p->hand;
}

card get_card_in_hand(player p, int card_index)
{
    return p->cards_in_hand[card_index];
}

void remove_card_from_hand(player p, card c)
{
    int id_card = get_card_id(c);
    int j = -1;
    for (int i = 0; i < p->hand; i++)
    {
        if (get_card_id(p->cards_in_hand[i]) == id_card)
        {
            free(p->cards_in_hand[i]);
            j = i;
            break;
        }
    }
    if (j != -1)
    {
        for (int i = j; i < p->hand - 1; i++)
        {
            p->cards_in_hand[i] = p->cards_in_hand[i + 1];
        }
        p->hand--;
    }
}

void play_card(player p, card c)
{
    p->cards_on_table[p->table] = c;
    p->table++;
}

int get_number_of_played_cards(player p)
{
    return p->table;
}

card get_played_card(player p, int card_index)
{
    return p->cards_on_table[card_index];
}

void remove_played_card(player p, card c)
{
    int id_card = get_card_id(c);
    int j = -1;
    for (int i = 0; i < p->table; i++)
    {
        if (get_card_id(p->cards_on_table[i]) == id_card)
        {
            free(p->cards_on_table[i]);
            j = i;
            break;
        }
    }
    if (j != -1)
    {
        for (int i = j; i < p->table - 1; i++)
        {
            p->cards_on_table[i] = p->cards_on_table[i + 1];
        }
        p->table--;
    }
}

int get_slate(player p)
{
    return p->ardoise;
}

void set_slate(player p, int n)
{
    if (n == 0 || n == 1)
    {
        p->ardoise = n;
    }
    else
    {
        printf("n doit être entre 0 et 1");
    }
}