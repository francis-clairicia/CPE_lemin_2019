/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** add_room.c
*/

#include "lem_in.h"
#include "my.h"

static room_t *create_room_from_params(char * const *params)
{
    if (my_array_len(params) != 3)
        return (NULL);
    if (!my_str_isnum(params[1]) || !my_str_isnum(params[2]))
        return (NULL);
    return (create_room(params[0], my_getnbr(params[1]), my_getnbr(params[2])));
}

bool add_simple_room(anthill_t *anthill, char * const *parsed_line)
{
    room_t *room = create_room_from_params(parsed_line);

    if (room == NULL)
        return (false);
    MY_APPEND_TO_LIST(&anthill->rooms, room);
    return (true);
}

bool add_start_room(anthill_t *anthill, char * const *parsed_line)
{
    room_t *room = NULL;

    if (anthill->start != NULL)
        return (false);
    room = create_room_from_params(parsed_line);
    if (room == NULL)
        return (false);
    room->start = true;
    MY_APPEND_TO_LIST(&anthill->rooms, room);
    anthill->start = room;
    return (true);
}

bool add_end_room(anthill_t *anthill, char * const *parsed_line)
{
    room_t *room = NULL;

    if (anthill->end != NULL)
        return (false);
    room = create_room_from_params(parsed_line);
    if (room == NULL)
        return (false);
    room->end = true;
    MY_APPEND_TO_LIST(&anthill->rooms, room);
    anthill->end = room;
    return (true);
}