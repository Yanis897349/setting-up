/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Solver algorithm
*/

#include <stdlib.h>
#include "Display/display.h"
#include "Solver/solver.h"
#include "include/my_std.h"
#include "include/my_io.h"
#include "include/my_strings.h"
#include <strings.h>

static void check_around(char **board, int **board_clone, int i, int j)
{
    if (i == 0 || j == 0)
        board_clone[i][j] = board[i][j] == 'o' ? 0 : 1;
    else
        board_clone[i][j] = board[i][j] == 'o' ? 0 : GET_MIN(
            board_clone[i - 1][j], board_clone[i][j - 1],
            board_clone[i - 1][j - 1]) + 1;
}

int solve_board(char **board, int lines_count, int columns_size)
{
    int **board_clone = malloc(sizeof(int *) * (lines_count + 1));

    if (board_clone == NULL)
        return EXIT_ERROR;
    for (int i = 0; i < lines_count; i++) {
        board_clone[i] = malloc(sizeof(int) * (columns_size + 1));
        if (board_clone[i] == NULL)
            return EXIT_ERROR;
        my_memset(board_clone[i], 0,
            (columns_size + 1) * sizeof(*board_clone[i]));
        for (int j = 0; j < columns_size - 1; j++)
            check_around(board, board_clone, i, j);
        board_clone[i][columns_size] = -1;
    }
    board_clone[lines_count] = NULL;
    print_solution(board, board_clone);
    return 0;
}
