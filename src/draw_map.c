/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** draw_map
*/

#include "lib.h"
#include "my_rpg.h"
#include "structures.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>

void draw_map_sprite(rpg_t *rpg, int i, int j, char id)
{
    if (rpg->maps[rpg->level]->array[i][j] == id) {
        sfSprite_setPosition(rpg->sprite[(int) id].map_sprite, (sfVector2f)
        {j * 50 - rpg->player_pos.x + 150, i * 50 - rpg->player_pos.y + 150});
        sfRenderTexture_drawSprite(rpg->map_texture,
        rpg->sprite[(int) id].map_sprite, NULL);
    }
}

void draw_map_x(rpg_t *rpg, int i)
{
    for (int j = 0; j < my_strlen(rpg->maps[rpg->level]->array[i]); j++) {
        if (rpg->maps[rpg->level]->array[i][j] == ' ') {
            sfRectangleShape_setPosition(rpg->rect, (sfVector2f) {j * 50
            - rpg->player_pos.x + 150, i * 50 - rpg->player_pos.y + 150});
            sfRectangleShape_setFillColor(rpg->rect, sfBlack);
            sfRenderTexture_drawRectangleShape(rpg->map_texture,
            rpg->rect, NULL);
        }
        for (int nb = 0; nb < my_strlen(rpg->sprite_str); nb++)
            draw_map_sprite(rpg, i, j, rpg->sprite_str[nb]);
    }
}

void draw_circle_map(rpg_t *rpg)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, 150);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setPosition(circle, (sfVector2f) {63, 63});
    sfCircleShape_setOutlineThickness(circle, 63);
    sfCircleShape_setOutlineColor(circle, sfBlack);
    sfCircleShape_setPointCount(circle, 200);
    sfRenderWindow_drawCircleShape(rpg->window, circle, NULL);
    sfCircleShape_destroy(circle);

}

void draw_map(rpg_t *rpg)
{
    sfRenderTexture_clear(rpg->map_texture, sfBlack);
    for (int i = 0; i < rpg->maps[rpg->level]->y; i++)
        draw_map_x(rpg, i);
    sfRenderTexture_drawCircleShape(rpg->map_texture, rpg->player_circle, NULL);
    sfCircleShape_setPosition(rpg->entity[0].circle,
    (sfVector2f) {rpg->entity[0].pos.x -
    rpg->player_pos.x + 150, rpg->entity[0].pos.y - rpg->player_pos.y + 150});
    sfRenderTexture_drawCircleShape(rpg->map_texture,
    rpg->entity[0].circle, NULL);
    sfSprite_setTexture(rpg->map_sprite,
    sfRenderTexture_getTexture(rpg->map_texture), sfTrue);
    sfSprite_setTextureRect(rpg->map_sprite, (sfIntRect)
    {0, rpg->size_y, 300, -300});
    sfSprite_setRotation(rpg->map_sprite, -rpg->slope * (180 / pi) - 90);
    sfSprite_setOrigin(rpg->map_sprite, (sfVector2f) {150, 150});
    sfSprite_setPosition(rpg->map_sprite, (sfVector2f) {150 + 63, 150 + 63});
    sfRenderWindow_drawSprite(rpg->window, rpg->map_sprite, NULL);
    draw_circle_map(rpg);
}
