/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** valid_room.c
*/

#include "lem_in.h"
#include "my.h"

static bool dead_end(room_t *room UNUSED)
{
    return (false);
}

bool valid_room(room_t *room)
{
    if (room->end)
        return (true);
    if (my_list_size(room->ants) > 0)
        return (false);
    if (my_list_size(room->linked) == 1)
        return (false);
    if (dead_end(room))
        return (false);
    return (true);
}
