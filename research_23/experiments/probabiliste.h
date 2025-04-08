#ifndef PROBABILISTE_H
#define PROBABILISTE_H

/**
 * \brief Cette fonction joue au jeu selon deux méthodes : la méthode agressive pour une équipe, et la méthode probabiliste pour l'autre équipe
 * \param distrib une liste de 5 éléments contenant la distribution de probabilités pour les 5 cartes
 * \param nb_teams le nombre d'équipes, doit être soit 2 soit 4
 * \param nb_card_each_turn le nombre de cartes jouées à chaque tour, doit être entre 1 et 5
 * \return une liste contenant en premier le nombre de points de l'équipe qui utilise la méthode agressive, et en deuxième le nombre de points obtenus par l'équipe utilsiant la méthode probabiliste
 */
void probabiliste(int * distrib, int nb_teams, int nb_card_each_turn);

#endif