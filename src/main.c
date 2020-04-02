/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** main.c
*/

#include "lem_in.h"
#include "my.h"

static void *free_and_return(char **array, char *line, void *ptr)
{
    if (array != NULL)
        my_free_array(array);
    if (line != NULL)
        free(line);
    return (ptr);
}

static char **my_realloc_array(char **array, unsigned int to_add)
{
    int new_size = my_array_len(array) + to_add;
    char **new_array = malloc(sizeof(char *) * (new_size + 1));
    int i = 0;

    if (new_array != NULL) {
        for (i = 0; array != NULL && array[i] != NULL; i += 1)
            new_array[i] = array[i];
        while (i <= new_size) {
            new_array[i] = NULL;
            i += 1;
        }
    }
    free(array);
    return (new_array);
}

static char **read_stdin(void)
{
    char *line = NULL;
    char **array = NULL;
    int i = 0;

    while (get_next_line(&line, 0)) {
        array = my_realloc_array(array, 1);
        if (array == NULL)
            return (free_and_return(array, line, NULL));
        array[i] = my_strdup(line);
        if (array[i] == NULL)
            return (free_and_return(array, line, NULL));
        i += 1;
    }
    return (array);
}

int main(void)
{
    char **anthill_file = read_stdin();
    int output = 0;

    if (anthill_file == NULL)
        return (84);
    output = lem_in(anthill_file);
    my_free_array(anthill_file);
    return (output);
}