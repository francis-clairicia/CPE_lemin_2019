/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** ant.h
*/

#ifndef HEADER_LEMIN_ANT
#define HEADER_LEMIN_ANT

#include <stdlib.h>

typedef struct ant
{
    unsigned int id;
    bool can_move;
} ant_t;

static inline ant_t *create_ant(unsigned int id)
{
    ant_t *ant = malloc(sizeof(ant_t));

    if (ant != NULL) {
        ant->id = id;
        ant->can_move = true;
    }
    return (ant);
}

#endif