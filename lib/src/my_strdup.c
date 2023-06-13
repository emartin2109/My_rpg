/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my_strdup
*/

#include "lib.h"

char *my_strdup(char const *str)
{
    int size = my_strlen(str);
    char *dest = malloc(size + 1);

    int i = 0;
    while (str[i] != '\0') {
        dest[i] = str[i];
        i += 1;
    }
    dest[i] = '\0';
    return dest;
}
