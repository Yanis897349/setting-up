/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** Concatenate two strings
*/

#include "strings/my_strings.h"
#include <stddef.h>

char *my_strcat(char *dest, char const *src)
{
    size_t dest_size = my_strlen(dest);
    size_t src_size = my_strlen(src);

    for (size_t i = 0; i < src_size; i++) {
        dest[dest_size + i] = src[i];
    }
    dest[dest_size + src_size] = '\0';
    return dest;
}
