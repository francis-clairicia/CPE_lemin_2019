/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** ant.c
*/

#include "ant.h"

ant_t *create_ant(unsigned int id)
{
    ant_t *ant = malloc(sizeof(ant_t));

    if (ant != NULL) {
        ant->id = id;
        ant->can_move = true;
        ant->rooms_visited = NULL;
    }
    return (ant);
}

void destroy_ant(ant_t *ant)
{
    if (ant == NULL)
        return;
    my_free_list(&ant->rooms_visited, NULL);
    free(ant);
}