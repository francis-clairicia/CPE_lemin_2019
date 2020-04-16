/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** move_ants.c
*/

#include "my.h"
#include "lem_in.h"
#include "ant.h"
#include "mylist.h"
#include "room.h"
#include "vector.h"

static ant_t *get_ant(list_t *ants)
{
    list_t *node = NULL;
    ant_t *ant = NULL;

    for (node = ants; node != NULL; node = node->next) {
        ant = NODE_DATA(node, ant_t *);
        if (ant->can_move)
            return (ant);
    }
    return (NULL);
}

static void add_move(list_t **move_list, int ant_id, char const *name)
{
    char *nb_ant = my_nbr_to_str(ant_id);
    char *move = NULL;

    if (nb_ant == NULL)
        return;
    move = malloc(sizeof(char) * (my_strlen(nb_ant) + my_strlen(name) + 3));
    if (move != NULL) {
        move[0] = 'P';
        move[1] = '\0';
        my_strcat(move, nb_ant);
        my_strcat(move, "-");
        my_strcat(move, name);
        MY_APPEND_TO_LIST(move_list, move);
    }
    free(nb_ant);
}

void move_ant(list_t **move_list, room_t *old, room_t *new)
{
    ant_t *ant = get_ant(old->ants);

    if (ant == NULL)
        return;
    my_delete_node_from_data(&old->ants, (long)ant, NULL);
    MY_APPEND_TO_LIST(&new->ants, ant);
    ant->can_move = false;
    add_move(move_list, ant->id, new->name);
}