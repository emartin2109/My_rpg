/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** draw_ray_cast
*/

#include "lib.h"
#include "my_rpg.h"
#include "structures.h"
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include <raycast.h>

void set_texture(float xprd, float yprd, sfSprite *sprite)
{
    if (is_vertical(xprd, yprd))
        sfSprite_setTextureRect(sprite, (sfIntRect) {yprd * 256, 0, 1, 256});
    else
        sfSprite_setTextureRect(sprite, (sfIntRect) {xprd * 256, 0, 1, 256});
}

void draw_ray_sprite(rpg_t *rpg, ray_cast_t *rc, int i)
{
    sfSprite *sprite = rpg->sprite[(int) rpg->sprite_str[i]].ray_sprite;
    char id = rpg->sprite_str[i];
    if (rpg->maps[rpg->level]->array[(int) rc->hit_point.y / 50]
    [(int) rc->hit_point.x / 50] == id) {
        float xprd = rc->hit_point.x / 50 - (int) (rc->hit_point.x / 50);
        float yprd = rc->hit_point.y / 50 - (int) (rc->hit_point.y / 50);
        float shades = rc->distance * 255 / rpg->gamma;
        if (shades > 255) shades = 255;
        sfSprite_setScale(sprite, (sfVector2f)
        {1, (float) ((96 * rpg->size_y) / rc->distance) / 256});
        sfSprite_setColor(sprite, (sfColor)
        {255 - shades, 255 - shades, 255 - shades, 255});
        set_texture(xprd, yprd, sprite);
        sfSprite_setPosition(sprite, (sfVector2f) {(rpg->size_x / 2) + rc->
        x_offset, rpg->y_offset - (((96 * rpg->size_y) / rc->distance) / 2)});
        sfRenderWindow_drawSprite(rpg->window, sprite, NULL);
    }
}

ray_cast_t *get_hippoint_and_dist(rpg_t *rpg, int nb)
{
    sfVector2f pointx;
    sfVector2f pointy;
    pointx = (sfVector2f) {rpg->player_pos.x / 50.0,
    rpg->player_pos.y / 50.0};
    pointy = (sfVector2f) {rpg->player_pos.x / 50.0,
    rpg->player_pos.y / 50.0};
    pointx = get_hitpoint_x(rpg);
    rpg->slope = reset_angle(rpg->slope);
    pointy = get_hitpoint_y(rpg);
    pointx = (sfVector2f) {pointx.x * 50.0,
    pointx.y * 50.0};
    pointy = (sfVector2f) {pointy.x * 50.0,
    pointy.y * 50.0};
    ray_cast_t *rc = get_best_hitpoint_and_distance(rpg, pointx, pointy);
    rc->x_offset = nb;
    return (rc);
}

void draw_ray_cast(rpg_t *rpg, int nb)
{
    ray_cast_t *rc = get_hippoint_and_dist(rpg, nb);
    change_entity_position(rpg, nb, rc);
    for (int i = 0; i < my_strlen(rpg->sprite_str); i++)
        draw_ray_sprite(rpg, rc, i);
}

rpg_t *draw_all_ray_casts(rpg_t *rpg)
{
    rpg->clone_slope = rpg->slope;
    for (int i = 0; i <= (rpg->size_x / 2); i++) {
        draw_ray_cast(rpg, i);
        rpg->slope = rpg->clone_slope + (0.0005 * (1080 / rpg->size_y))
        * (i + 1);
    }
    rpg->slope = rpg->clone_slope;
    for (int i = -0; i >= -(rpg->size_x / 2); i--) {
        draw_ray_cast(rpg, i);
        rpg->slope = rpg->clone_slope + (0.0005 * (1080 / rpg->size_y))
        * (i - 1);
    }
    rpg->slope = rpg->clone_slope;
    draw_ray_cast(rpg, 0);
    return (rpg);
}
