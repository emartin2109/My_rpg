/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_dialogs
*/

#include "dialogs.h"
#include "structures.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>

static dialog_dim_t get_elements_scale(sfRenderWindow *window, sfSprite *dialog)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    const sfTexture *texture = sfSprite_getTexture(dialog);
    sfVector2u texture_size = sfTexture_getSize(texture);
    sfVector2f scale = (sfVector2f) {(float) size.x / MAXWINSIZE.x,
        (float) size.y / MAXWINSIZE.y};
    sfSprite_setScale(dialog, scale);
    sfVector2f dialog_pos =
        (sfVector2f) {0, size.y - (texture_size.y * scale.y)};
    sfVector2f name_pos = (sfVector2f) {NAME_POSITION.x * scale.x,
                        size.y - (NAME_POSITION.y * scale.y)};
    sfVector2f text_pos = (sfVector2f) {TEXT_POSITION.x * scale.y,
                        size.y - (TEXT_POSITION.y * scale.y)};
    return (dialog_dim_t){dialog_pos, name_pos, text_pos, scale};
}

void display_dialogs(rpg_t *rpg)
{
    if (rpg->dialogs == NULL)
        return;
    dialog_t *current_dialog = rpg->dialogs;
    dialog_dim_t dim = get_elements_scale(rpg->window, rpg->dialog);
    sfRenderWindow_drawSprite(rpg->window, rpg->dialog, NULL);
    sfText_setPosition(current_dialog->text, dim.text_pos);
    sfText_setPosition(current_dialog->name, dim.name_pos);
    sfText_setScale(current_dialog->text, dim.scale);
    sfText_setScale(current_dialog->name, dim.scale);
    sfRenderWindow_drawText(rpg->window, current_dialog->text, NULL);
    sfRenderWindow_drawText(rpg->window, current_dialog->name, NULL);
    if (sfClock_getElapsedTime(current_dialog->clock).microseconds >
        current_dialog->time * 1000000) {
        rpg->dialogs = current_dialog->next;
        free(current_dialog);
        if (rpg->dialogs != NULL)
            sfClock_restart(rpg->dialogs->clock);
    }
}
