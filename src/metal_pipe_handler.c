/*
** EPITECH PROJECT, 2023
** merge_save
** File description:
** metal_pipe_handler
*/

#include "my_rpg.h"
#include "menu.h"
#include "movement.h"
#include "sprites.h"
#include "raycast.h"
#include "structures.h"
#include "system.h"
#include "window.h"
#include "events.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdio.h>
#include <stdbool.h>
#include <lib.h>

static void render_metal_pipe(rpg_t *rpg, bool *is_metal_pipe_throw,
sfVector2f *scale)
{
    sfSprite *metal_pipe_sprite = sfSprite_copy(rpg->metal_pipe);
    sfSprite_setOrigin(metal_pipe_sprite, (sfVector2f) {275 / 2, 184 / 2});
    sfSprite_move(metal_pipe_sprite, (sfVector2f) {-275 * 2.5, -184 / 2});
    sfSprite_scale(metal_pipe_sprite, *scale);
    sfRenderWindow_drawSprite(rpg->window, metal_pipe_sprite, NULL);
    if ((*scale).x <= 0)
        *is_metal_pipe_throw = false;
    (*scale).x -= 0.075;
    (*scale).y -= 0.075;
    button_handler(rpg);
}

void metal_pipe_handler(rpg_t *rpg)
{
    static bool is_metal_pipe_throw = false;
    static sfVector2f distance_multiplier = {1, 1};
    sfTime time = sfClock_getElapsedTime(rpg->pipe_clock);
    if (sfTime_asSeconds(time) > rpg->throw_speed &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_play(rpg->metal_pipe_sound);
        sfClock_restart(rpg->pipe_clock);
        is_metal_pipe_throw = true;
        distance_multiplier = INITIAL_DISTANCE_MULTIPLIER;
    }
    if (is_metal_pipe_throw == true) {
        render_metal_pipe(rpg, &is_metal_pipe_throw, &distance_multiplier);
    } else {
        sfRenderWindow_drawSprite(rpg->window, rpg->metal_pipe, NULL);
    }
}
