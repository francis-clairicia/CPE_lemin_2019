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

ant_t *get_ant_who_will_move(list_t *ants)
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

bool move_ant(list_t **move_list, ant_t *ant, room_t *old, room_t *new)
{
    if (ant == NULL || old == NULL || new == NULL)
        return (false);
    my_delete_node_from_data(&old->ants, (long)ant, NULL);
    MY_APPEND_TO_LIST(&new->ants, ant);
    ant->can_move = false;
    MY_APPEND_TO_LIST(&ant->rooms_visited, new);
    add_move(move_list, ant->id, new->name);
    return (true);
}