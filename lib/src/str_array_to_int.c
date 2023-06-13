/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** str_array_to_int
*/

#include "lib.h"

int my_arraylen(char **array)
{
    int i = 0;
    for (; array[i] != NULL; i++);
    return i;
}

int *str_array_to_int(char **str_array)
{
    int *int_array = malloc(sizeof(int) * (my_arraylen(str_array) + 1));
    if (int_array == NULL)
        return NULL;
    for (int i = 0; str_array[i] != NULL; i++)
        int_array[i] = my_getnbr(str_array[i]);
    int_array[my_arraylen(str_array)] = -1;
    return int_array;
}
