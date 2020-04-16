/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** lem_in.c
*/

#include "my.h"
#include "lem_in.h"

static room_t *get_closest_empty_room(room_t *actual_room, room_t *end)
{
    list_t *tmp = NULL;
    room_t *room = NULL;
    room_t *keep_l = NODE_DATA(actual_room->linked, room_t *);
    unsigned long int dte = 0;
    unsigned long int cp_dte = dist_to_end(keep_l->pos, end->pos);

    for (tmp = actual_room->linked; tmp != NULL; tmp = tmp->next) {
        room = NODE_DATA(tmp, room_t *);
        dte = dist_to_end(room->pos, end->pos);
        if (dte < cp_dte && (my_list_size(room->ants) == 0 || room->end)) {
            cp_dte = dte;
            keep_l = room;
        }
    }
    return (keep_l);
}

room_t *keep_track(room_t *actual_room, room_t *end)
{
    room_t *closest_room = NULL;

    if (actual_room == NULL || end == NULL)
        return (NULL);
    closest_room = get_closest_empty_room(actual_room, end);
    return (closest_room);
}