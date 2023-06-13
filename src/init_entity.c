/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_enemy
*/

#include "lib.h"
#include "raycast.h"
#include "structures.h"
#include "sprites.h"
#include "my_rpg.h"
#include "entity.h"
#include <SFML/System/Vector2.h>

rpg_t *init_entity(rpg_t *rpg)
{
    rpg->entity = malloc(sizeof(entity_t) * 2);
    rpg->entity[0].size = (sfVector2f) {309, 413};
    rpg->entity[0].circle = sfCircleShape_create();
    sfCircleShape_setRadius(rpg->entity[0].circle, 10);
    sfCircleShape_setOrigin(rpg->entity[0].circle, (sfVector2f) {10, 10});
    sfCircleShape_setFillColor(rpg->entity[0].circle, sfGreen);
    sfCircleShape_setPosition(rpg->entity[0].circle, rpg->entity[0].pos);
    rpg->entity[0].sprite =
    create_sprite("assets/Shrek.png", (sfVector2f) {2, 2});
    rpg->animatinons_clock = sfClock_create();
    sfSprite_setOrigin(rpg->entity[0].sprite, (sfVector2f)
    {rpg->entity[0].size.x * 0.5, rpg->entity[0].size.y * 0.5});
    sfSprite_setPosition(rpg->entity[0].sprite, (sfVector2f) {10000, 540});
    rpg->entity[0].pos = (sfVector2f) {0, 0};
    rpg->entity[0].pos.x = rpg->maps[rpg->level]->meta[4] * 50;
    rpg->entity[0].pos.y = rpg->maps[rpg->level]->meta[5] * 50;
    rpg->entity[0].pv = 100;
    return (rpg);
}
