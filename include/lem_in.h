/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** lem_in.h
*/

#ifndef HEADER_LEM_IN_
#define HEADER_LEM_IN_

#include <stdbool.h>
#include "mylist.h"

typedef struct vector
{
    int x;
    int y;
} vector_t;

typedef struct room
{
    char *name;
    vector_t pos;
    list_t *linked;
    int ant;
} room_t;

typedef struct anthill
{
    int nb_ants;
    vector_t start;
    vector_t end;
    list_t *rooms;
} anthill_t;

int lem_in(char * const *config);
bool generate_anthill(anthill_t *anthill, char * const *config);

#endif