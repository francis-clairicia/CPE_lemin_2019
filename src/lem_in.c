/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** lem_in.c
*/

#include "lem_in.h"
#include "my.h"

static anthill_t init_anthill(void)
{
    anthill_t anthill;

    anthill.nb_ants = 0;
    anthill.rooms = NULL;
    anthill.start = NULL;
    anthill.end = NULL;
    return (anthill);
}

static void destroy_anthill(anthill_t *anthill)
{
    list_t *node = NULL;

    for (node = anthill->rooms; node != NULL; node = node->next)
        destroy_room((room_t *)(node->data));
    my_free_list(&anthill->rooms, false);
}

int lem_in(char * const *config)
{
    anthill_t anthill = init_anthill();

    if (config == NULL || !generate_anthill(&anthill, config))
        return (84);
    destroy_anthill(&anthill);
    return (0);
}