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
    bool start;
    bool end;
    list_t *ants;
} room_t;

typedef struct anthill
{
    int nb_ants;
    list_t *start;
    list_t *end;
    list_t *rooms;
} anthill_t;

enum line_kind {
    EXTREMITY,
    TUNNEL,
    ROOM,
    ROOM_NAMED
};

typedef void (*pointer_t)(anthill_t *, char **tab_arg, int *index);

int lem_in(char * const *config);
bool generate_anthill(anthill_t *anthill, char * const *config);

room_t *create_room(char const *name, vector_t pos);
void destroy_room(room_t *room);

#endif