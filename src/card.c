#include <stdio.h>
#include <stdlib.h>
#include "card.h"
struct card_s
{
    int id_card;
    int value;
};

card card_tab[20];

int creation_id()
{
    static int id = 0;
    return id;
    id++;
}

card create_card()
{
    card c = malloc(sizeof(struct card_s));
    if (c == NULL)
    {
        perror("Erreur durant l'allocation");
        exit(1);
    }
    c->id_card = creation_id();
    card_tab[c->id_card] = c;
    c->value = 0;
    return c;
}

void free_card(card c)
{
    free(c);
}

int get_card_id(card c)
{
    return c->id_card;
}

card get_card_by_id(int n)
{
    if (n >= 0 && n < 20)
    {
        return card_tab[n];
    }
    return NULL;
}

int get_value(card c)
{
    return c->value;
}

void set_value(card c, int n)
{
    if (n >= 0 && n < 6)
    {
        c->value = n;
    }
    else
    {
        printf("n doit être entre 0 et 5");
    }
}