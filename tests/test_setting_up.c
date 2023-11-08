/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Unit testing setting_up
*/

#include <criterion/criterion.h>
#include "src/Reader/reader.h"

Test(setting_up, should_return_0)
{
    int result = reader();

    cr_assert_eq(result, 0);
}
