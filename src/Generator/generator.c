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

static char **generate_board(int size, char const *pattern, int pattern_len)
{
    char **board = malloc(sizeof(char *) * (size + 1));

    if (board == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        board[i] = malloc(size + 1);
        if (board[i] == NULL)
            return NULL;
        for (int j = 0; j < size; j++)
            board[i][j] = pattern[(i * size + j) % pattern_len];
        board[i][size] = '\0';
    }
    board[size] = NULL;
    return board;
}

static int check_pattern_sanity(char const *pattern, int pattern_len)
{
    for (int i = 0; i < pattern_len; i++)
        if (pattern[i] != '.' && pattern[i] != 'o')
            return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int execute_generator(int board_size, char const *pattern)
{
    char **board = NULL;
    int pattern_len = my_strlen(pattern);

    if (board_size <= 0 || pattern_len <= 0)
        return EXIT_ERROR;
    if (check_pattern_sanity(pattern, pattern_len) == EXIT_ERROR)
        return EXIT_ERROR;
    board = generate_board(board_size, pattern, pattern_len);
    if (board == NULL)
        return EXIT_ERROR;
    solve_board(board, board_size, board_size);
    my_freearray(board);
    return EXIT_SUCCESS;
}
