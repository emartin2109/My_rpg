/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myhunter-yohan.decamps
** File description:
** convertions
*/

#include "../include/lib.h"

int my_int_len(int x)
{
    int i = 1;
    while (x > 9) {
        x = x / 10;
        i += 1;
    }
    return (i);
}

char *int_to_string(int x)
{
    int len = my_int_len(x);
    char *str = malloc(sizeof(char) * len);
    for (int i = len - 1; i >= 0; i--) {
        str[i] = x % 10 + '0';
        x = x / 10;
    }
    str[len] = '\0';
    return (str);
}
