/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** add_tunnel.c
*/

#include "lem_in.h"
#include "my.h"

static room_t *find_room_by_name(list_t *rooms, char const *name)
{
    list_t *node = NULL;
    room_t *room = NULL;

    for (node = rooms; node != NULL; node = node->next) {
        room = NODE_DATA(node, room_t *);
        if (my_strcmp(room->name, name) == 0)
            return (room);
    }
    return (NULL);
}

static char *make_tunnel(char * const *line)
{
    int size = my_strlen(line[0]) + 1 + my_strlen(line[1]);
    char *tunnel = malloc(sizeof(char) * (size + 1));

    if (my_memset(tunnel, 0, size + 1) != NULL)
        my_strcat(my_strcat(my_strcat(tunnel, line[0]), "-"), line[1]);
    return (tunnel);
}

bool add_tunnel(anthill_t *anthill, char * const *parsed_line)
{
    room_t *first = NULL;
    room_t *second = NULL;

    if (my_array_len(parsed_line) != 2)
        return (false);
    first = find_room_by_name(anthill->rooms, parsed_line[0]);
    second = find_room_by_name(anthill->rooms, parsed_line[1]);
    if (first == NULL || second == NULL)
        return (false);
    MY_APPEND_TO_LIST(&first->linked, second);
    MY_APPEND_TO_LIST(&second->linked, first);
    MY_APPEND_TO_LIST(&anthill->known_tunnels, make_tunnel(parsed_line));
    return (true);
}