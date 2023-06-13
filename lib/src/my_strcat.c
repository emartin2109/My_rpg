/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-yohan.decamps
** File description:
** my_strcat
*/

#include "../include/lib.h"

char *my_strcat(char *str1, char *str2)
{
    int j = 0;
    int total_len = my_strlen(str1) + my_strlen(str2);
    char *dest = malloc(sizeof(char) * (total_len + 1));
    if (dest == NULL)
        return (NULL);
    for (int i = 0; i < my_strlen(str1); i++)
        dest[i] = str1[i];
    for (int i = my_strlen(str1); i < total_len; i++) {
        dest[i] = str2[j];
        j++;
    }
    dest[total_len] = '\0';
    return (dest);
}
