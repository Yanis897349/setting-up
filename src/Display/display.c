/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Displaying a board
*/

#include "include/my_io.h"
#include <stddef.h>

void print_board(char **board)
{
    for (int i = 0; board[i] != NULL; i++) {
        for (int j = 0; board[i][j] != '\0'; j++) {
            my_putchar(board[i][j]);
        }
        my_putchar('\n');
    }
}
