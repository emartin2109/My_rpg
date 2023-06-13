/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** free_dialogs
*/

#include "structures.h"
#include <SFML/Graphics/Text.h>
#include <stdlib.h>

void free_dialog(dialog_t *dialog)
{
    sfText_destroy(dialog->name);
    sfText_destroy(dialog->text);
    sfClock_destroy(dialog->clock);
    free(dialog);
}
