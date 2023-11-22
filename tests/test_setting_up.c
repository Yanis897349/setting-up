/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Unit testing setting_up
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "Generator/generator.h"
#include "Reader/reader.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(setting_up, generator_basic, .init = redirect_all_std)
{
    int board_size = 6;
    char const *pattern = "..o..";
    char const *solved = "..oxx.\n.o.xx.\no....o\n....o.\n...o..\n..o...\n";

    execute_generator(board_size, pattern);
    cr_assert_stdout_eq_str(solved);
}

Test(setting_up, generator_invalid_pattern)
{
    int board_size = 6;
    char const *pattern = "..o..x";

    cr_assert_eq(execute_generator(board_size, pattern), 84);
}

Test(setting_up, generator_invalid_size)
{
    int board_size = -1;
    char const *pattern = "..o..";

    cr_assert_eq(execute_generator(board_size, pattern), 84);
}

Test(setting_up, generator_pattern_empty)
{
    int board_size = 6;
    char const *pattern = "";

    cr_assert_eq(execute_generator(board_size, pattern), 84);
}

Test(setting_up, reader_invalid_file)
{
    char const *filepath = "dont_exist";

    cr_assert_eq(execute_reader(filepath), 84);
}

Test(setting_up, reader_invalid_sanity_characters)
{
    char const *filepath = "tests/invalid_sanity_characters";

    cr_assert_eq(execute_reader(filepath), 84);
}

Test(setting_up, reader_invalid_columns_size)
{
    char const *filepath = "tests/invalid_columns_size";

    cr_assert_eq(execute_reader(filepath), 84);
}

Test(setting_up, reader_invalid_lines_count)
{
    char const *filepath = "tests/invalid_lines_count";

    cr_assert_eq(execute_reader(filepath), 84);
}
