#include <stdio.h>
#include <stdlib.h>

#ifndef _CARD_
#define _CARD_

/**
\brief : type abstrait card permettant d'accéder à toutes les infos d'une carte
d'après le sujet : paquet de NB_CARDS cartes, numérotées de 1 à 5. Il y a 4 cartes de chaque type */
typedef struct card_s *card;
;

void reset_card_id_counter();

void reset_global_array2();

/**
\brief : renvoie une card initialement sans valeur
\param : rien
\return : card c sans valeur
*/
card create_card();

/**
\brief : libérer toute la mémoire allouée à la carte donné en entrée
\param c : card c
\return : rien
*/
void free_card(card c);

/**
\brief : renvoyer l'identifiant de la carte
\param : card c
\return : rien
*/
int get_card_id(card c);

/**
\brief : renvoye la carte dont l'identifiant a été donné en entrée
\param : int id identifiant de la carte
\return : carte assossiée
*/
card get_card_by_id(int id);

/**
\brief : renvoye la valeur inscrite sur la carte
\param : card c
\return: valeur inscrite sur la carte
*/
int get_value(card c);

/**
\brief : NOUVELLE FONCTION TÂCHE E, renvoie la couleur de la carte
\param : card c
\return: couleur de la carte
*/
int get_card_colour(card c);

/**
\brief : remplace la valeur inscrite sur la carte par la valeur donnée en entrée
\param : card c et int n
\return : rien
*/
void set_value(card c, int n);

/**
\brief : NOUVELLE FONCTION TÂCHE E, remplace la couleur de la carte par la valeur donnée en entrée
\param : card c et char colour
\return : rien
*/
void set_colour(card c, char colour);



/* -------------  AJOUTS Tâche E.4  ------------- */

/* Une carte est soit normale, soit spéciale.
   Les spéciales sont identifiées par leur "effet_id".              */
typedef enum {
    NO_EFFECT = 0,
    EFF_THUY_VO,
    EFF_DAVID_ROUSSEL,
    EFF_ABASS_SAGNA,
    EFF_LAURENCE_BOURARD,
    EFF_CHRISTOPHE_MOUILLERON,
    NB_EFFECTS
} effect_id;

/**
 * \brief   Crée une carte spéciale.
 *          - Alloue la structure via create_card() (identifiant unique).
 *          - Force la valeur à 0 et la couleur à ‘m’ (multicolore).
 *          - Mémorise l’identifiant d’effet passé en paramètre.
 * \param id  Identifiant (enum effect_id) correspondant au pouvoir spécial.
 * \return  pointeur sur la carte spéciale nouvellement créée.
 */
card create_special_card(effect_id id);

/**
 * \brief   Indique si une carte est spéciale.
 * \param   c  Carte à tester.
 * \return  1 si la carte porte un effet (eff != NO_EFFECT), 0 sinon.
 */
int is_special(card c);

/**
 * \brief   Renvoie l’identifiant d’effet d’une carte.
 * \param   c   Carte interrogée.
 * \return  L’énumération effect_id stockée dans la carte
 *          (NO_EFFECT pour une carte normale).
 */
effect_id get_effect_id(card c);

/**
 * \brief   Renvoie le nom humainement lisible d’une carte.
 * \param   c   Carte dont on veut le nom.
 * \return  Chaîne constante (dans effect_names) correspondant à l’effet.
 *          Pour une carte normale, renvoie "normale".
 */
const char* get_card_name(card c);


#endif
