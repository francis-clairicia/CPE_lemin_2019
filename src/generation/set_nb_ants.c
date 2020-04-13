/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** set_nb_ants.c
*/

#include "lem_in.h"
#include "my.h"

static bool free_and_return(char *str, bool status)
{
    if (str != NULL)
        free(str);
    return (status);
}

static char *get_first_valid_line(char * const *config, int *index)
{
    int i = 0;
    int sharp = 0;

    if (config == NULL || index == NULL)
        return (NULL);
    while (config[i] != NULL && config[i][0] == '#' && config[i][1] != '#')
        i += 1;
    *index = i + 1;
    sharp = my_strchr_index(config[i], '#');
    return ((sharp < 0) ? my_strdup(config[i]) : my_strndup(config[i], sharp));
}

bool set_nb_ants(anthill_t *anthill, char * const *config, int *index)
{
    int nb = 0;
    char *number = get_first_valid_line(config, index);

    if (!my_str_isnum(number))
        return (free_and_return(number, false));
    nb = my_getnbr(number);
    if (nb < 0)
        return (free_and_return(number, false));
    anthill->nb_ants = nb;
    return (free_and_return(number, true));
}