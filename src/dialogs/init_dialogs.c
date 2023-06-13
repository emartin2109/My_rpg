/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_dialogs
*/

#include "structures.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>

sfSprite *init_dialog_sprite(void)
{
    sfSprite *dialog = sfSprite_create();
    if (dialog == NULL)
        return NULL;
    sfTexture *dialog_texture =
        sfTexture_createFromFile("assets/dialogbox.png", NULL);
    if (dialog_texture == NULL)
        return NULL;
    sfSprite_setTexture(dialog, dialog_texture, sfTrue);
    sfVector2u size = sfTexture_getSize(dialog_texture);
    sfSprite_setPosition(dialog, (sfVector2f){0, MAXWINSIZE.y - size.y});
    return dialog;
}
