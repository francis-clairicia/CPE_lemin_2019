/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** room.c
*/

#include "lem_in.h"
#include "my.h"

room_t *create_room(char const *name, int x, int y)
{
    room_t *room = malloc(sizeof(*room));

    if (room != NULL) {
        room->linked = NULL;
        room->name = my_strdup(name);
        if (room->name == NULL) {
            free(room);
            return (NULL);
        }
        room->start = false;
        room->end = false;
        room->pos.x = x;
        room->pos.y = y;
        room->ants = NULL;
        room->len_to_end = 0;
    }
    return (room);
}

void destroy_room(room_t *room)
{
    if (room == NULL)
        return;
    my_free_list(&room->linked, NULL);
    my_free_list(&room->ants, &free);
    free(room->name);
    free(room);
}