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
    anthill.moves = NULL;
    return (anthill);
}

void destroy_anthill(anthill_t *anthill)
{
    my_free_list(&anthill->rooms, &destroy_room);
    my_free_list(&anthill->known_tunnels, &free);
}

static void put_all_ants(anthill_t *anthill)
{
    int i = 0;

    for (i = 1; i <= anthill->nb_ants; i += 1)
        MY_APPEND_TO_LIST(&anthill->start->ants, i);
}

int lem_in(char * const *config)
{
    anthill_t anthill = init_anthill();
    bool generation_status = true;

    if (config == NULL) {
        destroy_anthill(&anthill);
        return (84);
    }
    generation_status = generate_anthill(&anthill, config);
    print_anthill(anthill);
    if (generation_status == true) {
        put_all_ants(&anthill);
        my_putstr("#moves\n");
        a_star_algo(&anthill);
    }
    destroy_anthill(&anthill);
    return ((generation_status == true) ? 0 : 84);
}