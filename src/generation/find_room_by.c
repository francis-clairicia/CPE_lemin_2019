/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** find_room_by_name.c
*/

#include "lem_in.h"
#include "my.h"

room_t *find_room_by_name(list_t *rooms, char const *name)
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

room_t *find_room_by_pos(list_t *rooms, int x, int y)
{
    list_t *node = NULL;
    room_t *room = NULL;

    for (node = rooms; node != NULL; node = node->next) {
        room = NODE_DATA(node, room_t *);
        if (room->pos.x == x && room->pos.y == y)
            return (room);
    }
    return (NULL);
}