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
    ant_t *ant = NULL;

    for (node = anthill->ants; node != NULL; node = node->next) {
        ant = NODE_DATA(node, ant_t *);
        room = NODE_DATA(my_node(ant->rooms_visited, -1), room_t *);
        if (room->end || ant == NULL)
            continue;
        closest_room = keep_track(ant, room, anthill->end);
        move_ant(&anthill->moves, ant, room, closest_room);
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

static void permit_all_ants_to_move(list_t *ants)
{
    list_t *node = NULL;

    for (node = ants; node != NULL; node = node->next) {
        NODE_DATA(node, ant_t *)->can_move = true;
    }
}

void a_star_algo(anthill_t *anthill)
{
    if (anthill == NULL || anthill->start == NULL || anthill->end == NULL)
        return;
    while (my_list_size(anthill->end->ants) != anthill->nb_ants) {
        move_all_ants(anthill);
        print_moves(anthill->moves);
        permit_all_ants_to_move(anthill->ants);
        my_free_list(&anthill->moves, &free);
    }
}