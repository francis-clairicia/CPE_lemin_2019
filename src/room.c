/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** room.c
*/

#include "lem_in.h"
#include "my.h"

room_t *create_room(char const *name, vector_t pos)
{
    room_t *room = malloc(sizeof(*room));

    if (room != NULL) {
        room->linked = NULL;
        room->name = my_strdup(name);
        room->start = false;
        room->pos = pos;
        room->end = false;
        room->ants = NULL;
    }
    return (room);
}

void destroy_room(room_t *room)
{
    my_free_list(&room->linked, NULL);
    my_free_list(&room->ants, NULL);
    free(room->name);
    free(room);
}