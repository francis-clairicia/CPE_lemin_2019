/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** test_anthill_generator.c
*/

#include <criterion/criterion.h>
#include "lem_in.h"
#include "my.h"

char **get_anthill(char const *file);

Test(generate_anthill, init_an_anthill_according_to_a_file_content)
{
    anthill_t anthill = init_anthill();
    char **file_content = get_anthill("normal");

    cr_expect_eq(generate_anthill(&anthill, file_content), true);
    cr_expect_eq(anthill.nb_ants, 10);
    cr_expect_eq(my_list_size(anthill.rooms), 2);
    cr_expect_eq(my_list_size(anthill.known_tunnels), 1);
    cr_expect_not_null(anthill.start);
    if (anthill.start != NULL) {
        cr_expect_str_eq(anthill.start->name, "0");
        cr_expect_eq(anthill.start->pos.x, 29);
        cr_expect_eq(anthill.start->pos.y, 26);
    }
    cr_expect_not_null(anthill.end);
    if (anthill.end != NULL) {
        cr_expect_str_eq(anthill.end->name, "1");
        cr_expect_eq(anthill.end->pos.x, 50);
        cr_expect_eq(anthill.end->pos.y, 28);
    }
    my_free_array(file_content);
    destroy_anthill(&anthill);
}

Test(generate_anthill, fails_when_nb_ants_not_set_or_invalid)
{
    anthill_t anthill = init_anthill();
    char **no_ants = get_anthill("no_ants");
    char **invalid_nb_ants = get_anthill("invalid_nb_ants");

    cr_expect_eq(generate_anthill(&anthill, no_ants), false);
    cr_expect_eq(generate_anthill(&anthill, invalid_nb_ants), false);
    my_free_array(no_ants);
    my_free_array(invalid_nb_ants);
    destroy_anthill(&anthill);
}