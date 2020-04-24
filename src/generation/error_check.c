/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** error_check.c
*/

#include "lem_in.h"

static bool basic_requierement(anthill_t *anthill)
{
    if (anthill->start == NULL)
        return (false);
    if (anthill->end == NULL)
        return (false);
    if (my_list_size(anthill->rooms) == 0)
        return (false);
    if (my_list_size(anthill->known_tunnels) == 0)
        return (false);
    return (true);
}

static bool room_in_list(list_t *list, room_t *room)
{
    while (list != NULL) {
        if (NODE_DATA(list, room_t *) == room)
            return (true);
        list = list->next;
    }
    return (false);
}

static bool check_way_to_end(room_t *room_to_check, list_t **rooms_visited)
{
    room_t *room = NULL;
    list_t *node = NULL;

    if (room_to_check->end)
        return (true);
    for (node = room_to_check->linked; node != NULL; node = node->next) {
        room = NODE_DATA(node, room_t *);
        if (room_in_list(*rooms_visited, room))
            continue;
        MY_APPEND_TO_LIST(rooms_visited, room);
        if (check_way_to_end(room, rooms_visited) == true)
            return (true);
    }
    return (false);
}

bool error_generation(anthill_t *anthill)
{
    list_t *rooms_visited = NULL;
    bool at_least_one_way_to_end = true;

    if (anthill == NULL || basic_requierement(anthill) == false)
        return (false);
    if (my_list_size(anthill->start->linked) == 0)
        return (false);
    if (my_list_size(anthill->end->linked) == 0)
        return (false);
    at_least_one_way_to_end = check_way_to_end(anthill->start, &rooms_visited);
    my_free_list(&rooms_visited, NULL);
    return (at_least_one_way_to_end);
}