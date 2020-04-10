/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** print_anthill.c
*/

#include "lem_in.h"
#include "my.h"

static void print_room(room_t *room)
{
    if (room->start)
        my_putstr("##start\n");
    else if (room->end)
        my_putstr("##end\n");
    my_printf("%s %d %d\n", room->name, room->pos.x, room->pos.y);
}

void print_anthill(anthill_t anthill)
{
    list_t *node = NULL;

    my_printf("#number_of_ants\n%d\n", anthill.nb_ants);
    my_putstr("#rooms\n");
    for (node = anthill.rooms; node != NULL; node = node->next)
        print_room(NODE_DATA(node, room_t *));
    my_putstr("#tunnels\n");
    for (node = anthill.known_tunnels; node != NULL; node = node->next)
        my_printf("%s\n", NODE_DATA(node, char *));
}