/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** setvalue
*/

#include "lib.h"
#include "structures.h"

static save_entry_t **reallocate_save(save_entry_t **save)
{
    int size = 0;
    for (; save[size] != NULL; size++);
    save_entry_t **new_save = malloc(sizeof(save_entry_t*) * (size + 2));
    if (new_save == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
        new_save[i] = save[i];
    new_save[size] = NULL;
    new_save[size + 1] = NULL;
    free(save);
    return new_save;
}

save_entry_t **save_setvalue(save_entry_t **save, char *name, char *value)
{
    if (save == NULL || name == NULL || value == NULL)
        return NULL;
    int i = 0;
    for (; save[i] != NULL; i++) {
        if (my_strcmp(save[i]->name, name) == 0) {
            save[i]->value = my_strdup(value);
            return save;
        }
    }
    save = reallocate_save(save);
    if (save == NULL)
        return NULL;
    save[i] = malloc(sizeof(save_entry_t));
    if (save[i] == NULL)
        return NULL;
    save[i]->name = my_strdup(name);
    save[i]->value = my_strdup(value);
    return save;
}
