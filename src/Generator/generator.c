/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Generating a board
*/

#include <stdlib.h>
#include "Display/display.h"
#include "include/my_strings.h"
#include "include/my_math.h"

static char **generate_board(int size, char *pattern)
{
    char **board = malloc(sizeof(char *) * (size + 1));
    int pattern_len = my_strlen(pattern);

    if (board == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        board[i] = malloc(size + 1);
        if (board[i] == NULL)
            return NULL;
        for (int j = 0; j < size; j++)
            board[i][j] = pattern[(i + j) % pattern_len];
        board[i][size] = '\0';
    }
    board[size] = NULL;
    return board;
}

int execute_generator(char **av)
{
    char *pattern = av[2];
    int pattern_size = my_strlen(pattern);
    int board_size = my_getnbr(av[1]);

    if (board_size <= 0 || pattern_size <= 0)
        return 84;
    for (int i = 0; i < pattern_size; i++)
        if (pattern[i] != '.' && pattern[i] != 'o')
            return 84;
    print_board(generate_board(board_size, pattern));
    return 0;
}
