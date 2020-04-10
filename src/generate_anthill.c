/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** generate_anthill.c
*/

#include "lem_in.h"
#include "my.h"

static void remove_comments(char **parsed, int length)
{
    int sharp = 0;
    int index = 0;
    char *new = NULL;

    while (parsed[index] != NULL && !my_strchr(parsed[index], '#'))
        index += 1;
    sharp = my_strchr_index(parsed[index], '#');
    new = (sharp <= 0) ? NULL : my_strndup(parsed[index], sharp);
    free(parsed[index]);
    parsed[index] = new;
    index += 1;
    while (index < length) {
        free(parsed[index]);
        parsed[index] = NULL;
        index += 1;
    }
}

static char **parse_line(char const *line, char const separator[])
{
    char **parsed = my_str_to_word_array(line, separator);

    if (parsed != NULL)
        remove_comments(parsed, my_array_len(parsed));
    return (parsed);
}

static setter_t choose_function_to_use(char * const *config, int *index)
{
    int minus_index = 0;
    int space_index = 0;

    while (config[*index] != NULL
    && config[*index][0] == '#' && config[*index][1] != '#')
        *index += 1;
    if (my_strcmp(config[*index], "##start") == 0) {
        *index += 1;
        return (&add_start_room);
    }
    if (my_strcmp(config[*index], "##end") == 0) {
        *index += 1;
        return (&add_end_room);
    }
    minus_index = my_strchr_index(config[*index], '-');
    space_index = my_strchr_index(config[*index], ' ');
    if (minus_index >= 0 && (space_index < 0 || minus_index < space_index))
        return (&add_tunnel);
    return (&add_simple_room);
}

static char **get_infos(char * const *config, int *index, setter_t *function)
{
    *function = choose_function_to_use(config, index);
    if (config[*index] == NULL)
        return (NULL);
    if (*function == &add_tunnel)
        return (parse_line(config[*index], "-"));
    return (parse_line(config[*index], " "));
}

bool generate_anthill(anthill_t *anthill, char * const *config)
{
    int index = 1;
    char **arg = NULL;
    bool status = true;
    setter_t setter = NULL;

    if (config == NULL || anthill == NULL || !set_nb_ants(anthill, config[0]))
        return (false);
    while (status == true && config[index] != NULL) {
        arg = get_infos(config, &index, &setter);
        if (arg == NULL)
            return (false);
        status = setter(anthill, arg);
        index += 1;
        my_free_array(arg);
    }
    status &= (anthill->start != NULL) & (anthill->end != NULL);
    return (status);
}