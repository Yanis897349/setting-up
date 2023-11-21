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

    if (stat(filepath, &file_stat) == -1)
        return NULL;
    buffer = malloc(file_stat.st_size + 1);
    if (buffer == NULL)
        return NULL;
    my_memset(buffer, '\0', file_stat.st_size + 1);
    size_read = read(file_descriptor, buffer, file_stat.st_size);
    if (size_read != file_stat.st_size) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

static int check_board_characters(const char *row, int row_len)
{
    for (int j = 0; j < row_len; j++) {
        if (row[j] != '.' && row[j] != 'o')
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

static int check_board_integrity(char **board, int board_lines_count,
    int board_columns_size)
{
    int row_len = board_columns_size - 1;

    if (board_lines_count <= 0 || board_columns_size <= 0)
        return EXIT_ERROR;
    for (int i = 0; i < board_lines_count; i++) {
        if (check_board_characters(
            board[i], row_len) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
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
        my_memcpy(board[i], buffer + i * *board_columns_size,
            *board_columns_size);
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
    if (check_board_integrity(
        board, board_lines_count, board_columns_size) == EXIT_ERROR)
        return EXIT_ERROR;
    solve_board(board, board_lines_count, board_columns_size);
    my_freearray(board);
    free(file_content);
    return EXIT_SUCCESS;
}
