/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Reading a board from command-line arguments
*/

#include "Display/display.h"
#include "Solver/solver.h"
#include "include/my_math.h"
#include "include/my_strings.h"
#include "include/my_std.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

static char *read_file(char const *filepath, int file_descriptor)
{
    char *buffer = NULL;
    int size_read = 0;
    struct stat file_stat;

    if (stat(filepath, &file_stat) == -1) {
        return NULL;
    }
    buffer = malloc(file_stat.st_size + 1);
    if (buffer == NULL)
        return NULL;
    size_read = read(file_descriptor, buffer, file_stat.st_size);
    if (size_read == -1) {
        free(buffer);
        return NULL;
    }
    buffer[size_read] = '\0';
    return buffer;
}

static char **fill_board(char *buffer, int *board_lines_count,
    int *board_columns_size)
{
    char **board = NULL;
    int start_index = 0;

    *board_lines_count = my_getnbr(buffer);
    if (*board_lines_count <= 0)
        return NULL;
    board = malloc(sizeof(char *) * (*board_lines_count + 1));
    for (; buffer[start_index] != '\n'; start_index++);
    buffer = buffer + start_index + 1;
    *board_columns_size = my_strlen(buffer) / *board_lines_count;
    for (int i = 0; i < *board_lines_count; i++) {
        board[i] = malloc(*board_columns_size);
        for (int j = 0; buffer[j] != '\n'; j++)
            board[i][j] = buffer[i * *board_columns_size + j];
        board[i][*board_columns_size - 1] = '\0';
    }
    board[*board_lines_count] = NULL;
    return board;
}

int execute_reader(char const *filepath)
{
    char **board = NULL;
    char *file_content = NULL;
    int file_descriptor = open(filepath, O_RDONLY);
    int board_lines_count = 0;
    int board_columns_size = 0;

    if (file_descriptor == -1)
        return EXIT_ERROR;
    file_content = read_file(filepath, file_descriptor);
    close(file_descriptor);
    if (file_content == NULL)
        return EXIT_ERROR;
    board = fill_board(file_content, &board_lines_count, &board_columns_size);
    solve_board(board, board_lines_count, board_columns_size);
    my_freearray(board);
    free(file_content);
    return EXIT_SUCCESS;
}
