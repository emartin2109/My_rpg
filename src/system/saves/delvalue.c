/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** delvalue
*/

#include "structures.h"
#include "lib.h"
#include "system.h"

static int my_arraylen(save_entry_t **array)
{
    int i = 0;
    while (array[i] != NULL)
        i++;
    return i;
}

save_entry_t **save_delvalue(save_entry_t **save, char *name)
{
    if (save == NULL || name == NULL || save_getvalue(save, name) == NULL)
        return NULL;
    int len = my_arraylen(save);
    save_entry_t **new_save = malloc(sizeof(save_entry_t *) * len);
    if (new_save == NULL)
        return NULL;
    for (int i = 0, j = 0; save[i] != NULL; i++) {
        if (my_strcmp(name, save[i]->name) == 0) {
            free(save[i]);
            continue;
        }
        new_save[j] = save[i];
        if (new_save[j] == NULL)
            return NULL;
        ++j;
    }
    new_save[len - 1] = NULL;
    free(save);
    return new_save;
}
