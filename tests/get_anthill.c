/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** get_anthill.c
*/

#include <stdlib.h>
#include <fcntl.h>
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

char **get_anthill(char const *file)
{
    char *path = join_path("tests/anthills/", file);
    int fd = (path == NULL) ? -1 : open(path, O_RDONLY);
    char *line = NULL;
    char **array = NULL;
    int i = 0;

    if (path != NULL)
        free(path);
    while (fd >= 0 && get_next_line(&line, fd)) {
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
