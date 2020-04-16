/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** go_to_end.c
*/

#include "my.h"
#include "room.h"
#include "lem_in.h"
#include "mylist.h"
#include "vector.h"

void go_to_end(room_t *end)
{
    list_t *tmp = end->linked;
    room_t *room = NULL;

    while (tmp != NULL) {
        room = NODE_DATA(tmp, room_t *);
        if (my_list_size(room->ants) > 0) {
            my_printf("P%d-%s", room->ants, room->name);
            my_delete_node(room->ants);
        }
        tmp = tmp->next;
    }
}