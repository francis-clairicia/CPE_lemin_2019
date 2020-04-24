/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** valid_room.c
*/

#include "lem_in.h"
#include "my.h"

bool valid_room(room_t *room)
{
    if (room->end)
        return (true);
    if (my_list_size(room->ants) > 0)
        return (false);
    return (true);
}