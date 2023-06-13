/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** freemem
*/

#include "structures.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <stdlib.h>

void freemaps(map_t **maps)
{
    for (int i = 0; maps[i] != NULL; i++) {
        for (int j = 0; j < maps[i]->y + 1; j++)
            free(maps[i]->fcontent[j]);
        free(maps[i]->fcontent);
        free(maps[i]->meta);
        free(maps[i]);
    }
    free(maps);
}

static void free_sprites(rpg_t *rpg)
{
    for (int i = 0; i < 256; i++)
        if (rpg->sprite[i].map_sprite != NULL) {
            sfSprite_destroy(rpg->sprite[i].map_sprite);
            sfSprite_destroy(rpg->sprite[i].ray_sprite);
        }
    sfSprite_destroy(rpg->map_sprite);
    sfSprite_destroy(rpg->metal_pipe);
    sfRenderTexture_destroy(rpg->how_to_play_back);
}

void freemem(rpg_t *rpg)
{
    freemaps(rpg->maps);
    free(rpg->event);
    free_sprites(rpg);
    sfRectangleShape_destroy(rpg->floor);
    sfRenderTexture_destroy(rpg->map_texture);
    sfCircleShape_destroy(rpg->player_circle);
    sfRectangleShape_destroy(rpg->rect);
    sfMusic_destroy(rpg->metal_pipe_sound);
    sfMusic_destroy(rpg->music);
    sfRenderWindow_destroy(rpg->window);
    sfText_destroy(rpg->how_to_play_text);
    sfText_destroy(rpg->quest);
}
