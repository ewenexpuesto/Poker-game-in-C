#include "../../include/board.h"
#include "../../include/card.h"
#include "../../include/player.h"

#ifndef PROBABILISTE_H
#define PROBABILISTE_H


//int * probabiliste(int * distrib, int nb_teams, int nb_card_each_turn);

/**
 * \brief Cette fonction joue au jeu selon deux méthodes : la méthode agressive pour une équipe, et la méthode probabiliste pour l'autre équipe
 * \param n le nombre de round dans la partie
 * \return une liste contenant en premier le score de l'équipe qui utilise la méthode agressive, et en deuxième le score obtenu par l'équipe utilsiant la méthode probabiliste
 */
int * probabiliste(int n);

#endif