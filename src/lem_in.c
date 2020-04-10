/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** lem_in.c
*/

#include "lem_in.h"
#include "my.h"

anthill_t init_anthill(void)
{
    anthill_t anthill;

    anthill.nb_ants = 0;
    anthill.rooms = NULL;
    anthill.start = NULL;
    anthill.end = NULL;
    anthill.known_tunnels = NULL;
    return (anthill);
}

void destroy_anthill(anthill_t *anthill)
{
    my_free_list(&anthill->rooms, &destroy_room);
    my_free_list(&anthill->known_tunnels, &free);
}

int lem_in(char * const *config)
{
    anthill_t anthill = init_anthill();

    if (config == NULL || !generate_anthill(&anthill, config)) {
        destroy_anthill(&anthill);
        return (84);
    }
    print_anthill(anthill);
    destroy_anthill(&anthill);
    return (0);
}