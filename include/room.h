/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** room.h
*/

#ifndef LEM_IN_ROOM_H_
#define LEM_IN_ROOM_H_

#include <stdbool.h>
#include "vector.h"
#include "mylist.h"

typedef struct room
{
    char *name;
    vector_t pos;
    list_t *linked;
    bool start;
    bool end;
    list_t *ants;
} room_t;

room_t *create_room(char const *name, int x, int y);
void destroy_room(room_t *room);

#endif