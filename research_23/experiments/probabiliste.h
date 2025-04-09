#include "../../include/board.h"
#include "../../include/card.h"
#include "../../include/player.h"
#include "../../include/interface.h"

#ifndef PROBABILISTE_H
#define PROBABILISTE_H


//int * probabiliste(int * distrib, int nb_teams, int nb_card_each_turn);

/**
 * \brief Cette fonction joue au jeu selon deux méthodes : la méthode agressive pour une équipe, et la méthode probabiliste pour l'autre équipe
 * \param 
 * \return une liste contenant en premier le nombre de points de l'équipe qui utilise la méthode agressive, et en deuxième le nombre de points obtenus par l'équipe utilsiant la méthode probabiliste
 */
int * probabiliste();

#endif