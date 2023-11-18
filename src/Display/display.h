/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Displaying a board
*/

#pragma once

typedef struct max_data_s {
    int max;
    int max_i;
    int max_j;
} max_data_t;

void print_solution(char **board, int **board_clone);
