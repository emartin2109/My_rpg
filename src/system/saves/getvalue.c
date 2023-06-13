/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** getvalue
*/

#include "lib.h"
#include "structures.h"

char *save_getvalue(save_entry_t **save, char *name)
{
    if (save == NULL || name == NULL)
        return NULL;
    for (int i = 0; save[i] != NULL; i++) {
        if (my_strcmp(save[i]->name, name) == 0)
            return save[i]->value;
    }
    return NULL;
}
