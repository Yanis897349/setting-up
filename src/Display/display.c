/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Displaying a board
*/

#include "display.h"
#include "include/my_io.h"
#include <stdlib.h>

static void print_board(char **board)
{
    for (int i = 0; board[i] != NULL; i++) {
        my_putstr(board[i]);
        my_putchar('\n');
    }
}

static void is_superior(int **board_clone, max_data_t *max_data, int i)
{
    for (int j = 0; board_clone[i][j] != -1; j++) {
        if (board_clone[i][j] > max_data->max) {
            max_data->max = board_clone[i][j];
            max_data->max_i = i;
            max_data->max_j = j;
        }
    }
}

void print_solution(char **board, int **board_clone)
{
    max_data_t max_data = {0, 0, 0};

    for (int i = 0; board_clone[i] != NULL; i++)
        is_superior(board_clone, &max_data, i);
    for (int i = max_data.max_i; i > max_data.max_i - max_data.max; i--)
        for (int j = max_data.max_j; j > max_data.max_j - max_data.max; j--)
            board[i][j] = 'x';
    print_board(board);
    for (int i = 0; board_clone[i] != NULL; i++)
        free(board_clone[i]);
    free(board_clone);
}
