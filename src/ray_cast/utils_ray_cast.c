/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** utils_ray_cast
*/

#include "lib.h"
#include "my_rpg.h"
#include "structures.h"
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <math.h>

int is_vertical(float xprd, float yprd)
{
    if ((xprd < 0.5 && yprd < 0.5 && xprd < yprd)
    || (xprd > 0.5 && yprd > 0.5 && xprd > yprd)
    || (xprd < 0.5 && yprd > 0.5 && 1 - xprd > yprd)
    || (xprd > 0.5 && yprd < 0.5 && xprd > 1 - yprd))
        return (1);
    return (0);
}

float angle_between(sfVector2f p1, sfVector2f p2)
{
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return ((float) atan2(dy, dx));
}

float reset_angle(float angle)
{
    if (angle > M_PI)
        angle -= 2 * M_PI;
    if (angle < 0)
        angle += 2 * M_PI;
    return (angle);
}

void change_entity_position_inner(rpg_t *rpg, int nb, ray_cast_t *rc,
float angle)
{
    if (angle > rpg->slope && angle < rpg->slope + (0.0005 * (1080 /
    rpg->size_y)))
        sfSprite_setPosition(rpg->entity[0].sprite, (sfVector2f)
        {(rpg->size_x / 2) + nb, rpg->y_offset});
    if (rpg->clone_slope + -(rpg->size_x / 2) * (0.0005 * (1080 /
    rpg->size_y)) > angle
    || rpg->clone_slope + (rpg->size_x / 2) * (0.0005 * (1080 /
    rpg->size_y)) < angle || rpg->entity[0].pv <= 0)
        sfSprite_setPosition(rpg->entity[0].sprite,
        (sfVector2f) {10000 + nb, rpg->y_offset});
    if (((rc->x_offset + 1) / rpg->size_x) >= rpg->entity[0].slope
    && ((rc->x_offset - 1) / rpg->size_x) < rpg->entity[0].slope)
        sfSprite_setPosition(rpg->entity[0].sprite,
        (sfVector2f) {(rpg->size_x / 2) + rc->x_offset, rpg->y_offset});
}

void change_entity_position(rpg_t *rpg, int nb, ray_cast_t *rc)
{
    float angle = angle_between(rpg->player_pos, rpg->entity[0].pos);
    angle = reset_angle(angle);
    float pnj_distance = sqrt(pow(rpg->player_pos.x - rpg->entity[0].pos.x, 2) +
    pow(rpg->player_pos.y - rpg->entity[0].pos.y, 2));
    float shades = pnj_distance * 255 / rpg->gamma;
    if (shades > 255)
        shades = 255;
    sfSprite_setColor(rpg->entity[0].sprite, (sfColor)
    {255 - shades, 255 - shades, 255 - shades, 255});
    change_entity_position_inner(rpg, nb, rc, angle);
}
