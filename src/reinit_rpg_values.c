/*
** EPITECH PROJECT, 2023
** reinitialyse rpg values
** File description:
** reinitialyse rpg values
*/
#include "my_rpg.h"
#include "lib.h"

rpg_t *reinit_rpg_values(rpg_t *rpg)
{
    rpg->slope = 2 * pi;
    rpg->player_pos.x = rpg->maps[rpg->level]->meta[0] * 50;
    rpg->player_pos.y = rpg->maps[rpg->level]->meta[1] * 50;
    rpg->gamma = 600;
    rpg->y_offset = rpg->size_y ;
    rpg->speed = 4;
    rpg->entity->pv = 100;
    rpg->entity->pos.x = rpg->maps[rpg->level]->meta[4] * 50;
    rpg->entity->pos.y = rpg->maps[rpg->level]->meta[5] * 50;
    sfWindow_setMouseCursorVisible((sfWindow *) rpg->window, sfFalse);
    sfMusic_play(rpg->music);
    sfMouse_setPositionRenderWindow((sfVector2i) {rpg->size_x / 2,
    rpg->size_x / 2}, rpg->window);
    return rpg;
}
