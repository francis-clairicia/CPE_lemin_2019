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
#include "room.h"
#include "vector.h"

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

int lem_in(char * const *config);
bool generate_anthill(anthill_t *anthill, char * const *config);

typedef bool (*pointer_t)(anthill_t *, char * const *);
bool set_nb_ants(anthill_t *anthill, char const *number);
bool add_simple_room(anthill_t *anthill, char * const *parsed_line);
bool add_start_room(anthill_t *anthill, char * const *parsed_line);
bool add_end_room(anthill_t *anthill, char * const * parsed_line);
bool add_tunnel(anthill_t *anthill, char * const *parsed_line);

#endif