/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** ant.h
*/

#ifndef HEADER_LEMIN_ANT
#define HEADER_LEMIN_ANT

#include <stdlib.h>
#include <stdbool.h>
#include "mylist.h"

typedef struct ant
{
    unsigned int id;
    list_t *rooms_visited;
    bool can_move;
} ant_t;

ant_t *create_ant(unsigned int id);
void destroy_ant(ant_t *ant);
ant_t *get_ant_who_will_move(list_t *ants);

#endif