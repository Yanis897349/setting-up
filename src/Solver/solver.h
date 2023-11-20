/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** Solver algorithm
*/

#pragma once
#define GET_MIN(a, b, c) ((a < b ? a : b) < c ? (a < b ? a : b) : c)

int solve_board(char **board, int lines_count, int columns_size);
