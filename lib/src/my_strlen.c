/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-bsminishell1-yohan.decamps
** File description:
** my_strlen
*/

#include "../include/lib.h"

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
