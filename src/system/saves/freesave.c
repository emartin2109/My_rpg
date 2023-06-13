/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** freesave
*/

#include "structures.h"
#include "lib.h"
#include <stdio.h>

void save_freesave(save_entry_t **save)
{
    if (save == NULL)
        return;
    for (int i = 0; save[i] != NULL; i++) {
        if (save[i] == NULL)
            return;
        if (save[i]->name)
            free(save[i]->name);
        if (save[i]->value)
            free(save[i]->value);
        free(save[i]);
    }
    free(save);
}
