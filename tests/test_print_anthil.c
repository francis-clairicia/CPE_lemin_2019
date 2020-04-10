/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** test_print_anthil.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "lem_in.h"
#include "my.h"

char **get_anthill(char const *file);

Test(print_anthill, print_a_recap_of_anthill_generation)
{
    anthill_t anthill = init_anthill();
    FILE *output = fopen("tests/anthills/normal_2.output", "r");
    char **input = get_anthill("normal_2");

    cr_redirect_stdout();
    cr_expect_eq(generate_anthill(&anthill, input), true);
    print_anthill(anthill);
    cr_expect_stdout_eq(output);
    my_free_array(input);
    fclose(output);
    destroy_anthill(&anthill);
}

Test(generate_anthill, handle_comments_inside_file)
{
    anthill_t anthill = init_anthill();
    FILE *output = fopen("tests/anthills/normal_2.output", "r");
    char **input = get_anthill("normal_2_comments_inside");

    cr_redirect_stdout();
    cr_expect_eq(generate_anthill(&anthill, input), true);
    print_anthill(anthill);
    cr_expect_stdout_eq(output);
    my_free_array(input);
    fclose(output);
    destroy_anthill(&anthill);
}