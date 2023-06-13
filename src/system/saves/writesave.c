/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** writesave
*/

#include "lib.h"
#include "structures.h"
#include <stdio.h>

int save_writesave(save_entry_t **save, char *filename)
{
    if (filename == NULL || save == NULL)
        return ERROR;
    int file = open(filename, O_WRONLY | O_CREAT, 0666);
    if (file == -1) return ERROR;
    int size = 0;
    for (int i = 0; save[i] != NULL; i++) {
        size = my_strlen(save[i]->name);
        if (write(file, save[i]->name, size) == -1)
            return ERROR;
        if (write(file, "=", 1) == -1)
            return ERROR;
        size = my_strlen(save[i]->value);
        if (write(file, save[i]->value, size) == -1)
            return ERROR;
        if (write(file, "\n", 1) == -1)
            return ERROR;
    }
    close(file);
    return SUCCESS;
}
