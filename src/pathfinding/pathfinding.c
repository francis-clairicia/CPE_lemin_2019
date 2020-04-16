/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** pathfinding.c
*/

#include "lem_in.h"
#include "my.h"

static void move_all_ants(anthill_t *anthill)
{
    room_t *room = NULL;
    list_t *node = NULL;
    room_t *closest_room = NULL;

    for (node = anthill->rooms; node != NULL; node = node->next) {
        room = NODE_DATA(node, room_t *);
        if (room->end)
            continue;
        closest_room = keep_track(room, anthill->end);
        move_ant(&anthill->moves, room, closest_room);
    }
}

static void print_moves(list_t *moves)
{
    list_t *node = NULL;

    for (node = moves; node != NULL; node = node->next) {
        my_putstr(NODE_DATA(node, char *));
        my_putchar((node->next == NULL) ? '\n' : ' ');
    }
}

void a_star_algo(anthill_t *anthill)
{
    if (anthill == NULL || anthill->start == NULL || anthill->end == NULL)
        return;
    while (my_list_size(anthill->end->ants) != anthill->nb_ants) {
        my_free_list(&anthill->moves, &free);
        move_all_ants(anthill);
        print_moves(anthill->moves);
    }
}