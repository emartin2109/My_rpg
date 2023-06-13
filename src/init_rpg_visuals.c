/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** init_rpg_visuals
*/

#include "my_rpg.h"
#include "sprites.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>

rpg_t *init_sprite(rpg_t *rpg, char id, char *file)
{
    rpg->sprite[(int) id].ray_sprite = create_sprite(file, (sfVector2f) {1,1});
    rpg->sprite[(int) id].map_sprite = create_sprite(file,
    (sfVector2f) {(float) 50 / 256, (float) 50 / 256});
    return (rpg);
}

static void sanitize_sprites(rpg_t *rpg)
{
    for (int i = 0; i < 256; i++) {
        rpg->sprite[i].map_sprite = NULL;
        rpg->sprite[i].ray_sprite = NULL;
    }
}

rpg_t *init_all_sprites(rpg_t *rpg)
{
    rpg->sprite = malloc(sizeof(sprite_t) * 256);
    sanitize_sprites(rpg);
    rpg = init_sprite(rpg, 'B', "assets/Bricks.png");
    rpg = init_sprite(rpg, 'W', "assets/Backroom_Wall.png");
    rpg = init_sprite(rpg, 'w', "assets/Wood.png");
    rpg = init_sprite(rpg, 'M', "assets/Metal.png");
    rpg = init_sprite(rpg, 'R', "assets/Arrow_Right.png");
    rpg = init_sprite(rpg, 'L', "assets/Arrow_Left.png");
    rpg = init_sprite(rpg, 'E', "assets/Escargot.png");
    rpg = init_sprite(rpg, 'b', "assets/Letter_B.png");
    rpg->sprite_str = "BWwMRLEb";
    rpg->metal_pipe =
    create_sprite("assets/metal_pipe.png", (sfVector2f) {-3, 3});
    sfSprite_setPosition(rpg->metal_pipe, (sfVector2f) {2000, 900});
    sfSprite_setRotation(rpg->metal_pipe, 30);
    rpg = init_maps(rpg);
    return (rpg);
}

rpg_t *init_shapes(rpg_t *rpg)
{
    rpg->rect = sfRectangleShape_create();
    rpg->player_circle = sfCircleShape_create();
    sfCircleShape_setPosition(rpg->player_circle, (sfVector2f) {150, 150});
    sfCircleShape_setFillColor(rpg->player_circle, sfWhite);
    sfCircleShape_setRadius(rpg->player_circle, 10);
    sfCircleShape_setOrigin(rpg->player_circle, (sfVector2f) {10, 10});
    rpg->floor = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rpg->floor, (sfColor) {16, 8, 8, 255});
    sfRectangleShape_setPosition(rpg->floor, (sfVector2f) {0, rpg->size_y / 2});
    sfRectangleShape_setSize(rpg->floor, (sfVector2f) {rpg->size_x, 3000});
    sfRectangleShape_setSize(rpg->rect, (sfVector2f) {50, 50});
    sfRectangleShape_setFillColor(rpg->rect, sfBlack);
    return (rpg);
}
