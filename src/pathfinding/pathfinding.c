/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** pathfinding.c
*/

#include "lem_in.h"
#include "ant.h"
#include "my.h"

static void move_all_ants(anthill_t *anthill)
{
    room_t *room = NULL;
    list_t *node = NULL;
    room_t *closest_room = NULL;

    for (node = anthill->rooms; node != NULL; node = node->next) {
        room = NODE_DATA(node, room_t *);
        if (my_list_size(room->ants) == 0 || room->end)
            continue;
        closest_room = keep_track(room, anthill->end);
        if (closest_room != NULL)
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

static void permit_all_ants_to_move(list_t *rooms)
{
    list_t *n_room = NULL;
    list_t *n_ant = NULL;
    room_t *room = NULL;

    for (n_room = rooms; n_room != NULL; n_room = n_room->next) {
        room = NODE_DATA(n_room, room_t *);
        for (n_ant = room->ants; n_ant != NULL; n_ant = n_ant->next)
            NODE_DATA(n_ant, ant_t *)->can_move = true;
    }
}

void a_star_algo(anthill_t *anthill)
{
    if (anthill == NULL || anthill->start == NULL || anthill->end == NULL)
        return;
    while (my_list_size(anthill->end->ants) != anthill->nb_ants) {
        move_all_ants(anthill);
        print_moves(anthill->moves);
        permit_all_ants_to_move(anthill->rooms);
        my_free_list(&anthill->moves, &free);
    }
}