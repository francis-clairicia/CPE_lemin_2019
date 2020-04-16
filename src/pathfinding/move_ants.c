/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** move_ants.c
*/

#include "my.h"
#include "lem_in.h"
#include "mylist.h"
#include "room.h"
#include "vector.h"

void move_ant(list_t **move_list, room_t *old, room_t *new)
{
    unsigned int ant = NODE_DATA(old->ants, unsigned int);
    char *nb_ant = my_nbr_to_str(ant);
    char *move = NULL;

    my_delete_node(&old->ants, 0, NULL);
    MY_APPEND_TO_LIST(&new->ants, ant);
    move = malloc(sizeof(char) * (my_strlen(nb_ant) + 
        my_strlen(new->name) + 3));
    if (move != NULL) {
        move[0] = 'P';
        move[1] = '\0';
        my_strcat(move, nb_ant);
        my_strcat(move, "-");
        my_strcat(move, new->name);
        MY_APPEND_TO_LIST(move_list, move);
    }
    free(nb_ant);
}