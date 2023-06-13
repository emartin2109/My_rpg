/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** create_sprite
*/

#include "../include/lib.h"

sfSprite *create_sprite(char *file, sfVector2f scale)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    if (texture == NULL)
        return (NULL);
    sfSprite *sprite = sfSprite_create();
    if (sprite == NULL)
        return (NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, (sfVector2f) {scale.x, scale.y});
    return (sprite);
}
