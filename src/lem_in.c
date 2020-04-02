/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** lem_in.c
*/

#include "lem_in.h"
#include "my.h"

int lem_in(char * const *config)
{
    anthill_t anthill;

    if (config == NULL || !generate_anthill(&anthill, config))
        return (84);
    return (0);
}