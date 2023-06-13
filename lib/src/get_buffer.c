/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** get_buffer
*/

#include "../include/lib.h"

char *get_buffer(const char *filename)
{
    FILE *fp;
    char *buffer;
    struct stat s;
    if (stat(filename, &s) != 0)
        return NULL;
    if ((fp = fopen (filename, "rd")) == NULL)
        return NULL;
    buffer = malloc((s.st_size + 1) * sizeof(char));
    if (fread(buffer, s.st_size, 1, fp) != 1) {
        fclose(fp);
        free(buffer);
        return NULL;
    }
    fclose(fp);
    buffer[s.st_size] = '\0';
    return (buffer);
}
