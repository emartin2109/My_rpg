/*
** EPITECH PROJECT, 2023
** merge_save
** File description:
** utils
*/

#include <stdio.h>
#include "lib.h"

void free_map(int y, int **maze)
{
    for (int i = 0; i < y - 1; i++)
        free(maze[i]);
    free(maze);
}

char **copy_char_array(char** original, int length)
{
    char **copied = malloc(length * sizeof(char *));
    for (int i = 0; i < length; i++)
        copied[i] = my_strdup(original[i]);
    return copied;
}

char *my_strcat_no_free (char *dest, char *src)
{
    if (dest == NULL)
        return src;
    int dest_len = my_strlen(dest);
    int add_len = my_strlen(src);
    int i = -1;
    char *result = malloc((dest_len + add_len + 1) * sizeof(char));
    if (result == NULL)
        return NULL;
    while (dest[++i])
        result[i] = dest[i];
    i = -1;
    while (src[++i])
        result[dest_len + i] = src[i];
    result[dest_len + i] = '\0';
    return result;
}
