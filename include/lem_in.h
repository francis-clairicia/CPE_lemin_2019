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
    room_t *start;
    room_t *end;
    list_t *rooms;
    list_t *known_tunnels;
} anthill_t;

int lem_in(char * const *config);

anthill_t init_anthill(void);
void destroy_anthill(anthill_t *anthill);
bool generate_anthill(anthill_t *anthill, char * const *config);
void print_anthill(anthill_t anthill);

typedef bool (*setter_t)(anthill_t *, char * const *);
bool set_nb_ants(anthill_t *anthill, char * const *config, int *index);
bool add_simple_room(anthill_t *anthill, char * const *parsed_line);
bool add_start_room(anthill_t *anthill, char * const *parsed_line);
bool add_end_room(anthill_t *anthill, char * const * parsed_line);
bool add_tunnel(anthill_t *anthill, char * const *parsed_line);

#endif