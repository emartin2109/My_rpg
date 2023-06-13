/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** handle_movement
*/

#include "lib.h"
#include "menu.h"
#include "my_rpg.h"
#include "structures.h"
#include <math.h>

rpg_t *handle_direction(rpg_t *rpg, float speed, sfKeyCode key, float angle)
{
    if (sfKeyboard_isKeyPressed(key)) {
        if (rpg->maps[rpg->level]->array[(int) ((rpg->player_pos.y +
            sin(rpg->slope + angle)
        * 20) / 50)][(int) ((rpg->player_pos.x) / 50)] == ' ')
            rpg->player_pos = (sfVector2f) {rpg->player_pos.x,
            rpg->player_pos.y + sin(rpg->slope + angle) * speed};
        if (rpg->maps[rpg->level]->array[(int) ((rpg->player_pos.y) / 50)][(int)
        ((rpg->player_pos.x + cos(rpg->slope + angle) * 20) / 50)] == ' ')
            rpg->player_pos = (sfVector2f) {rpg->player_pos.x +
            cos(rpg->slope + angle) * speed, rpg->player_pos.y};
    }
    return (rpg);
}

static void check_goal(rpg_t *rpg)
{
    if (rpg->maps[rpg->level]->meta[2] == (int) rpg->player_pos.x / 50 &&
        rpg->maps[rpg->level]->meta[3] == (int) rpg->player_pos.y / 50)
            level_selector(rpg);
}

rpg_t *handle_player_pos(rpg_t *rpg)
{
    handle_direction(rpg, rpg->speed, rpg->key_binds->forward, 0);
    if (sfKeyboard_isKeyPressed(rpg->key_binds->forward))
        handle_direction(rpg, rpg->speed * 0.5, rpg->key_binds->run, 0);
    handle_direction(rpg, rpg->speed, rpg->key_binds->backward, pi);
    handle_direction(rpg, rpg->speed * 0.75,
    rpg->key_binds->left, 3 * (pi / 2));
    handle_direction(rpg, rpg->speed * 0.75, rpg->key_binds->right, pi / 2);
    check_goal(rpg);
    return (rpg);
}
