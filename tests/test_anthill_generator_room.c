/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** test_anthill_generator_room.c
*/

#include <criterion/criterion.h>
#include "lem_in.h"
#include "my.h"

char **get_anthill(char const *file);

Test(generate_anthill, fails_for_no_rooms_set)
{
    anthill_t anthill = init_anthill();
    char **file_content = get_anthill("no_rooms");

    cr_expect_eq(generate_anthill(&anthill, file_content), false);
    my_free_array(file_content);
    destroy_anthill(&anthill);
}

Test(generate_anthill, fails_for_bad_room_separators)
{
    anthill_t anthill = init_anthill();
    char **file_content = get_anthill("bad_room_separators");

    cr_expect_eq(generate_anthill(&anthill, file_content), false);
    my_free_array(file_content);
    destroy_anthill(&anthill);
}

Test(generate_anthill, fails_for_bad_room_coords)
{
    anthill_t anthill = init_anthill();
    char **bad_coords = get_anthill("bad_coords");
    char **negative_coords = get_anthill("negative_coords");

    cr_expect_eq(generate_anthill(&anthill, bad_coords), false);
    cr_expect_eq(generate_anthill(&anthill, negative_coords), false);
    my_free_array(bad_coords);
    my_free_array(negative_coords);
    destroy_anthill(&anthill);
}

Test(generate_anthill, fails_for_bad_room_number_of_args)
{
    anthill_t anthill = init_anthill();
    char **file_content = get_anthill("bad_room_args_nb");

    cr_expect_eq(generate_anthill(&anthill, file_content), false);
    my_free_array(file_content);
    destroy_anthill(&anthill);
}