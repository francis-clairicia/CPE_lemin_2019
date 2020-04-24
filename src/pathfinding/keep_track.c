/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** lem_in.c
*/

#include "my.h"
#include "lem_in.h"

static bool room_not_valid(list_t *invalid, room_t *room)
{
    list_t *node = NULL;

    for (node = invalid; node != NULL; node = node->next) {
        if (NODE_DATA(node, room_t *) == room)
            return (true);
    }
    return (false);
}

static room_t *get_closest_empty_room(list_t *room_list, room_t *end,
    list_t *invalid)
{
    list_t *tmp = NULL;
    room_t *room = NULL;
    room_t *keep_l = NULL;
    unsigned int dte = 0;
    unsigned int cp_dte = 0xFFFFFFFFUL;

    for (tmp = room_list; tmp != NULL; tmp = tmp->next) {
        room = NODE_DATA(tmp, room_t *);
        if (room->end)
            return (room);
        dte = dist_to_end(room->pos, end->pos);
        if ((dte < cp_dte && valid_room(room)
        && !room_not_valid(invalid, room))) {
            cp_dte = dte;
            keep_l = room;
        }
    }
    return (keep_l);
}

room_t *keep_track(ant_t *ant, room_t *actual_room, room_t *end)
{
    room_t *closest_room = NULL;
    list_t *invalid = NULL;
    list_t *room_list = NULL;
    bool valid = true;
    int nb_passages = 0;

    if (actual_room == NULL || end == NULL)
        return (NULL);
    do {
        nb_passages = 0;
        while (room_list == NULL)
            room_list = select_room(ant, actual_room->linked, nb_passages++);
        closest_room = get_closest_empty_room(room_list, end, invalid);
        valid = (closest_room == NULL) || valid_room(closest_room);
        if (!valid)
            MY_APPEND_TO_LIST(&invalid, closest_room);
    } while (!valid);
    my_free_list(&invalid, NULL);
    my_free_list(&room_list, NULL);
    return (closest_room);
}