/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** error_check.c
*/

#include "lem_in.h"

static bool basic_requierement(anthill_t *anthill)
{
    if (anthill->start == NULL)
        return (false);
    if (anthill->end == NULL)
        return (false);
    if (my_list_size(anthill->rooms) == 0)
        return (false);
    if (my_list_size(anthill->known_tunnels) == 0)
        return (false);
    return (true);
}

bool error_generation(anthill_t *anthill)
{
    if (anthill == NULL || basic_requierement(anthill) == false)
        return (false);
    if (my_list_size(anthill->start->linked) == 0)
        return (false);
    if (my_list_size(anthill->end->linked) == 0)
        return (false);
    return (true);
}