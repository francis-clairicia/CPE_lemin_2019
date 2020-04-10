/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** test_anthill_generator_tunnel.c
*/

#include <criterion/criterion.h>
#include "lem_in.h"
#include "my.h"

char **get_anthill(char const *file);

Test(generate_anthill, fails_for_bad_tunnel_separators)
{
    anthill_t anthill = init_anthill();
    char **file_content = get_anthill("bad_tunnel_separators");

    cr_expect_eq(generate_anthill(&anthill, file_content), false);
    my_free_array(file_content);
    destroy_anthill(&anthill);
}

Test(generate_anthill, fails_for_bad_tunnel_names)
{
    anthill_t anthill = init_anthill();
    char **file_content = get_anthill("bad_tunnel_names");

    cr_expect_eq(generate_anthill(&anthill, file_content), false);
    my_free_array(file_content);
    destroy_anthill(&anthill);
}

Test(generate_anthill, fails_for_bad_tunnel_number_of_args)
{
    anthill_t anthill = init_anthill();
    char **file_content = get_anthill("bad_tunnels_args_nb");

    cr_expect_eq(generate_anthill(&anthill, file_content), false);
    my_free_array(file_content);
    destroy_anthill(&anthill);
}