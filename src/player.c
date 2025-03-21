#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "card.h"


struct player_s{
    card* cards_in_hand;
    int hand;
    card* cards_on_table; 
    int table;
    int ardoise;            /*1 =la joueuse a parié défaite et 0=la joueuse a parié défaite */
    int id;
};

typedef struct player_s player; 

int creation_id(){
    static int id=1;
    return id;
    id++;
}

player* create_player (){
    player *p= (player*)malloc(sizeof(player));
    if (p == NULL){
        perror("Erreur durant l'allocation");
        exit(1);
    }
    p->cards_in_hand = NULL;
    p->hand=0;
    p->cards_on_table = NULL;
    p->table=0;
    p->ardoise = NULL;
    p->id = creation_id();

    return p;
};

void free_player(player* p){
    free(p->cards_in_hand);
    free(p->cards_on_table);
    free(p->ardoise);
    free(p);
}

int get_player_id(player p){
    return p.id;
}

player get_player_by_id(int n){
    if (player.id ==n){
        return player;
    }
}

void add_card_to_hand(player *p, card c){
    p->cards_in_hand = (card*)malloc(p.cards_in_hand +1)*sizeof(card);
    p->cards_in_hand[player->hand]=c;
    p->hand++;
    c.index=p->hand;
}

int get_size_of_hand(player p){
    return p.hand;
}

card get_card_in_hand(player p, int card_index){
    return p->cards_in_hand[card_index];
}

void remove_card_from_hand(player *p, card c){
    int index = c.index;
    free(p->cards_in_hand[c.index]);
    if (c.index >0){
        for (int i=c.index; i<p->hand+1; i++){
            cards_in_hand[i]=cards_in_hand[i-1];      
        }
    }
}