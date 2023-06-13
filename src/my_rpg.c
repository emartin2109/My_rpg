/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** myrpg
*/

#include "my_rpg.h"
#include "lib.h"
#include "menu.h"
#include "movement.h"
#include "sprites.h"
#include "raycast.h"
#include "structures.h"
#include "system.h"
#include "window.h"
#include "events.h"
#include "entity.h"
#include "dialogs.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderTexture.h>
#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdio.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "dialogs.h"

void draw_all(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->floor, (sfVector2f) {0, rpg->y_offset});
    sfRenderWindow_drawRectangleShape(rpg->window, rpg->floor, NULL);
    rpg = draw_all_ray_casts(rpg);
    rpg->prev_mouse_pos = get_mouse_pos(rpg->window, rpg->size_x, rpg->size_y);
    sfRenderWindow_drawSprite(rpg->window, rpg->entity[0].sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->metal_pipe, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyM))
        draw_map(rpg);
    sfText_setPosition(rpg->quest, (sfVector2f) {10, 10});
    sfText_setColor(rpg->quest, sfWhite);
    sfRenderWindow_drawText(rpg->window, rpg->quest, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyTab))
        inventory(rpg);
    display_framerate(rpg);
    display_dialogs(rpg);
}

void set_entity_pos(rpg_t *rpg)
{
    float distance = sqrt(pow(rpg->player_pos.x - rpg->entity[0].pos.x, 2) +
    pow(rpg->player_pos.y - rpg->entity[0].pos.y, 2));
    sfSprite_setScale(rpg->entity[0].sprite,
    (sfVector2f) {(float) ((150 * rpg->size_y) / distance)
    / 512, (float) ((150 * rpg->size_y) / distance) / 512});
}

void button_handler(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(rpg->metal_pipe_sound);
        sfMusic_play(rpg->metal_pipe_sound);
        entity_is_hit(rpg);
    }
}

void loop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, (sfColor) {32, 16, 16, 255});
        sfRenderTexture_clear(rpg->map_texture, sfTransparent);
        if (manage_event(rpg) == 1)
            return;
        rpg = handle_player_pos(rpg);
        rpg = camera_mouvement(rpg, rpg->prev_mouse_pos);
        animate_entities(rpg);
        set_entity_pos(rpg);
        sfMouse_setPosition((sfVector2i) {rpg->size_x / 2, rpg->size_y / 2},
        (sfWindow *) rpg->window);
        move_shrek(rpg);
        draw_all(rpg);
        metal_pipe_handler(rpg);
        display_framerate(rpg);
        sfRenderWindow_display(rpg->window);
    }
}

int myrpg(void)
{
    rpg_t *rpg = init_rpg_variables();
    main_menu(rpg->window, rpg->event, rpg);
    sfMusic_play(rpg->music);
    loop(rpg);
    freemem(rpg);
    return (0);
}
