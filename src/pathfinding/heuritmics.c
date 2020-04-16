/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** heuritmics.c
*/

#include "my.h"
#include "lem_in.h"

unsigned int dist_to_end(vector_t room_pos, vector_t end_pos)
{
    int x = my_pow(room_pos.x - end_pos.x, 2);
    int y = my_pow(room_pos.y - end_pos.y, 2);

    if ((x + y) < 0)
        return (0);
    return (my_sqrt(x + y));
}