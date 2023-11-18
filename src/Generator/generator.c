/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Generating a board
*/

#include <stdlib.h>
#include "Display/display.h"
#include "Solver/solver.h"
#include "include/my_std.h"
#include "include/my_strings.h"
#include "include/my_math.h"

static char **generate_board(int size, char const *pattern)
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

int execute_generator(int board_size, char const *pattern)
{
    char **board = NULL;
    int pattern_size = my_strlen(pattern);

    if (board_size <= 0 || pattern_size <= 0)
        return EXIT_ERROR;
    for (int i = 0; i < pattern_size; i++)
        if (pattern[i] != '.' && pattern[i] != 'o')
            return EXIT_ERROR;
    board = generate_board(board_size, pattern);
    if (board == NULL)
        return EXIT_ERROR;
    solve_board(board, board_size, board_size);
    my_freearray(board);
    return EXIT_SUCCESS;
}
