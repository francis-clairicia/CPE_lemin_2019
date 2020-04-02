/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** generate_anthill.c
*/

#include "lem_in.h"
#include "my.h"

static const pointer_t func[] = {
};

bool init_extremity_room(anthill_t *anthill, char * const *config,
    int *index, char **arg)
{
    char **arg_next = NULL;
    bool ret = true;

    if (my_strcmp(arg[*index], "##start") == 0) {
        *index += 1;
        arg_next = my_str_to_word_array(config[*index], " ");
        ret = add_start_room(anthill, arg_next);
    } else if (my_strcmp(arg[*index], "##end") == 0) {
        *index += 1;
        arg_next = my_str_to_word_array(config[*index], " ");
        ret = add_end_room(anthill, arg_next);
    }
    my_free_array(arg_next);
    return (ret);
}

bool generate_anthill(anthill_t *anthill, char * const *config)
{
    int index = 1;
    char **arg = NULL;
    int len = 0;

    if (my_str_isnum(config[0]) == 0)
        anthill->nb_ants = my_getnbr(config[0]);
    else {
        return (false);
    }
    while (config[index] != NULL) {
        arg = my_str_to_word_array(config[index], " -");
        len = my_array_len(arg);
        if (len == 1) {
            init_extremity_room(anthill, config, &index, arg);
        } else if (len >= 2 && len <= 4) {
            func[len](anthill, arg);
        }
        index += 1;
        my_free_array(arg);
    }
    return (true);
}