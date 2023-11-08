/*
** EPITECH PROJECT, 2023
** my_strupcase.c
** File description:
** Puts every letter of every word in it in uppercase
*/

#include "strings/my_strings.h"
#include "ctype/my_ctype.h"
#include <stddef.h>

char *my_strupcase(char *str)
{
    size_t len = my_strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (my_islower(str[i])) {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
