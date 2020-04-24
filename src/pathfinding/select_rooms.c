/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** select_rooms.c
*/

#include "lem_in.h"
#include "my.h"

static int get_nb_of_passages(ant_t *ant, room_t *room)
{
    int nb = 0;
    list_t *node = NULL;

    for (node = ant->rooms_visited; node != NULL; node = node->next)
        nb += (NODE_DATA(node, room_t *) == room);
    return (nb);
}

static int get_greatest_nb_of_passages(ant_t *ant, list_t *list)
{
    int max = 0;
    int nb_passages = 0;
    list_t *node = NULL;

    for (node = list; node != NULL; node = node->next) {
        nb_passages = get_nb_of_passages(ant, NODE_DATA(node, room_t *));
        if (nb_passages > max)
            max = nb_passages;
    }
    return (max);
}

list_t *select_room(ant_t *ant, list_t *room_list, int nb_passages)
{
    int max_passages = get_greatest_nb_of_passages(ant, room_list);
    list_t *rooms_chosen = NULL;
    list_t *node = NULL;
    room_t *room = NULL;
    bool add_this_room = true;

    for (node = room_list; node != NULL; node = node->next) {
        room = NODE_DATA(node, room_t *);
        add_this_room = true;
        add_this_room &= (get_nb_of_passages(ant, room) == nb_passages);
        add_this_room &= (my_list_size(room->ants) == 0 || room->end);
        add_this_room |= (nb_passages > max_passages);
        if (add_this_room)
            MY_APPEND_TO_LIST(&rooms_chosen, node->data);
    }
    return (rooms_chosen);
}