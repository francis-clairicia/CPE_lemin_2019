/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** add_tunnel.c
*/

#include "lem_in.h"
#include "my.h"

static list_t *find_room_by_name(list_t *rooms, char const *name)
{
    list_t *node = NULL;
    room_t *room = NULL;

    for (node = rooms; node != NULL; node = node->next) {
        room = (room_t *)(node->data);
        if (my_strcmp(room->name, name) == 0)
            break;
    }
    return (node);
}

bool add_tunnel(anthill_t *anthill, char * const *parsed_line)
{
    list_t *first = NULL;
    list_t *second = NULL;

    if (my_array_len(parsed_line) != 2)
        return (false);
    first = find_room_by_name(anthill->rooms, parsed_line[0]);
    second = find_room_by_name(anthill->rooms, parsed_line[1]);
    if (first == NULL || second == NULL)
        return (false);
    my_append_to_list(&((room_t *)(first->data))->linked, (long)second);
    my_append_to_list(&((room_t *)(second->data))->linked, (long)first);
    return (true);
}