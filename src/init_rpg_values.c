/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** init_rpg_values
*/

#include "lib.h"
#include "raycast.h"
#include "structures.h"
#include "sprites.h"
#include "my_rpg.h"
#include "entity.h"
#include <SFML/System/Vector2.h>
#include "dialogs.h"
#include "system.h"

rpg_t *init_mouse(rpg_t *rpg)
{
    sfWindow_setMouseCursorVisible((sfWindow *) rpg->window, sfFalse);
    sfMouse_setPosition((sfVector2i) {rpg->size_x / 2,
    rpg->size_y / 2}, (sfWindow *) rpg->window);
    rpg->prev_mouse_pos.x = (rpg->size_x / 2) * 0.958333;
    rpg->prev_mouse_pos.y = rpg->size_y / 2;
    return (rpg);
}

rpg_t *init_all_values(rpg_t *rpg)
{
    rpg->player_pos.x = 0;
    rpg->player_pos.y = 0;
    rpg->level = 0;
    rpg->slope = SOUTH;
    rpg->gamma = 600;
    rpg->y_offset = 540;
    rpg->speed = 4;
    rpg->how_to_play_back = sfRenderTexture_create(500, 800, 0);
    sfRenderTexture_clear(rpg->how_to_play_back, sfWhite);
    rpg->how_to_play_text = create_text("You are Amonichi Gustavo,\n a SUS \
Inc. employee.\nYour role is to retrieve the\nObunga last name meaning you\n\
will have to adventure in his \nmanor.\nThe SUS inc. gave you a weapon\nto \
defend yourself, but because\nof the inflation they could only\nafford a \
Cardboard pipe\nthat you can use by pressing\nleft click.\nObunga's manor is \
divided in\ndifferent floor, each one\nhaving its own menace.\n\n\
Current objective :\nSurvive", 25);
    rpg->quest = create_text("Quest\n- Escape the enemy\n\
- Find the missing letter", 50);
    return (rpg);
}

rpg_t *init_inventory(rpg_t *rpg)
{
    rpg->inventory_back = create_sprite("assets/inventory.png",
    (sfVector2f) {1.5, 1.5});
    sfSprite_setPosition (rpg->inventory_back, (sfVector2f) {0, 500});
    rpg->inventory = NULL;
}

rpg_t *init_rpg_variables(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    rpg->size_x = 1920;
    rpg->size_y = 1080;
    rpg = init_all_values(rpg);
    rpg->window = create_window("RPG", 1920, 1080);
    rpg = init_mouse(rpg);
    rpg->event = malloc(sizeof(sfEvent));
    rpg = init_all_sprites(rpg);
    rpg = init_shapes(rpg);
    rpg = init_sounds(rpg);
    rpg->pipe_clock = sfClock_create();
    rpg->throw_speed = 2;
    rpg = init_entity(rpg);
    rpg->key_binds = malloc(sizeof(movement_keys_t));
    rpg = init_key_binds(rpg);
    rpg->dialog = init_dialog_sprite();
    rpg = init_inventory(rpg);
    rpg->dialogs = NULL;
    rpg->save_entry = fetch_save("save1");
    return (rpg);
}
