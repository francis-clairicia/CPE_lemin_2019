/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** set_nb_ants.c
*/

#include "lem_in.h"
#include "my.h"

bool set_nb_ants(anthill_t *anthill, char const *number)
{
    int nb = 0;

    if (!my_str_isnum(number))
        return (false);
    nb = my_getnbr(number);
    if (nb < 0)
        return (false);
    anthill->nb_ants = nb;
    return (true);
}