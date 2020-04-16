/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** heuritmics.c
*/

#include "room.h"
#include "mylist.h"
#include "vector.h"
#include "lem_in.h"
#include "my.h"

long int dist_to_end(vector_t pos, room_t *end)
{
    end->len_to_end = 0;

    return (my_sqrt
    (my_pow(pos->x - end->pos->y) + my_pow(pos->y - end->pos->y)));
}