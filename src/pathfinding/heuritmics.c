/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** heuritmics.c
*/

#include "my.h"
#include "lem_in.h"

unsigned long int dist_to_end(vector_t room_pos, vector_t end_pos)
{
    unsigned long int x = my_pow(room_pos.x - end_pos.x, 2);
    unsigned long int y = my_pow(room_pos.y - end_pos.y, 2);

    return (my_sqrt(x + y));
}