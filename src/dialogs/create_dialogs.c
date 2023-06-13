/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** create_dialogs
*/

#include "dialogs.h"
#include "structures.h"
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

static int pile_dialogs(dialog_t *dialogs, dialog_t *dialog)
{
    if (dialogs == NULL || dialog == NULL)
        return -1;
    dialog_t *tmp = dialogs;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = dialog;
    return 0;
}

dialog_t *create_dialog(dialog_t *dialogs, char *name, char *text, int time)
{
    if (name == NULL || text == NULL || time < 1) return NULL;
    dialog_t *dialog = malloc(sizeof(dialog_t));
    if (dialog == NULL) return NULL;
    dialog->name = sfText_create();
    dialog->text = sfText_create();
    dialog->time = time;
    dialog->clock = sfClock_create();
    dialog->next = NULL;
    sfText_setString(dialog->name, name);
    sfText_setString(dialog->text, text);
    sfText_setFont(dialog->name,
        sfFont_createFromFile("assets/StellaNovaBlack.ttf"));
    sfText_setFont(dialog->text,
        sfFont_createFromFile("assets/StellaNovaBlack.ttf"));
    sfText_setCharacterSize(dialog->name, NAME_SIZE);
    sfText_setCharacterSize(dialog->text, TEXT_SIZE);
    if (dialogs == NULL)
        return dialog;
    pile_dialogs(dialogs, dialog);
    return dialogs;
}
