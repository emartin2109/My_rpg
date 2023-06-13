/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** animate_entities
*/

#include "structures.h"
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Rect.h>

void animate_entities(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->entity[0].sprite, (sfIntRect)
    {rpg->entity[0].size.x *
    (((sfClock_getElapsedTime(rpg->animatinons_clock).microseconds) /
    100000) % 10), 0, rpg->entity[0].size.x, rpg->entity[0].size.y});
}
