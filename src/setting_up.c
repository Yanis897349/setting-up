/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Main file
*/

#include "Reader/reader.h"
#include "Generator/generator.h"
#include "include/my_std.h"
#include "setting_up.h"
#include "include/my_math.h"

static execution_type_t determine_execution_type(int ac)
{
    switch (ac) {
        case 2:
            return READER;
        case 3:
            return GENERATOR;
        default:
            return NO_EXEC;
    }
}

int main(int ac, char const **av)
{
    execution_type_t execution_type = determine_execution_type(ac);

    switch (execution_type) {
        case READER:
            return execute_reader(av[1]);
        case GENERATOR:
            return execute_generator(my_getnbr(av[1]), av[2]);
        case NO_EXEC:
        default:
            return EXIT_ERROR;
    }
}
