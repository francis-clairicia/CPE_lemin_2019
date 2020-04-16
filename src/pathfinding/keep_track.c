/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** lem_in.c
*/

#include "my.h"
#include "room.h"

room_t *closest_room(list_t *room, room_t *end, room_t *actual_room)
{
    room_t *keep_l = NULL;
    unsigned int dte = 0;
    unsigned int cp_dte = 0;

    go_to_end(end);
    cp_dte = dist_to_end(actual_room->pos, end);
    keep_l = room;
    while (room != NULL)  {
        dte = dist_to_end(actual_room->pos, end);
        if (dte < cp_dte) {
            cp_dte = dte;
            keep_l = room;
        }
        room = room->next;
    }
    return (keep_l);
}

void keep_track(list_t *list, room_t *end)
{
    room_t *actual_room;
    list_t *tmp = actual_room->linked;
    actual_room = NODE_DATA(list, room_t *);

    closest_room(tmp, end, actual_room);
    
}