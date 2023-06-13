/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** camera_movement
*/

#include "movement.h"
#include "my_rpg.h"
#include "raycast.h"

static void camera_mouvement_inner(rpg_t *rpg, sfVector2f prev_mouse_pos)
{
    if (get_mouse_pos(rpg->window, rpg->size_x, rpg->size_y).x <
    prev_mouse_pos.x)
        rpg->slope += (get_mouse_pos(rpg->window, rpg->size_x, rpg->size_y).x -
    prev_mouse_pos.x) * 0.001;
}

rpg_t *camera_mouvement(rpg_t *rpg, sfVector2f prev_mouse_pos)
{
    if (get_mouse_pos(rpg->window, rpg->size_x, rpg->size_y).y >
    prev_mouse_pos.y)
        if (rpg->y_offset - (get_mouse_pos(rpg->window,
        rpg->size_x, rpg->size_y).y - prev_mouse_pos.y) * 2 > - 1620)
            rpg->y_offset += (prev_mouse_pos.y
            - get_mouse_pos(rpg->window, rpg->size_x, rpg->size_y).y) * 2;
    if (get_mouse_pos(rpg->window, rpg->size_x, rpg->size_y).y <
    prev_mouse_pos.y)
        if (rpg->y_offset + (prev_mouse_pos.y - get_mouse_pos(rpg->window,
        rpg->size_x, rpg->size_y).y) * 2 < 2700)
            rpg->y_offset -= (get_mouse_pos(rpg->window,
            rpg->size_x, rpg->size_y).y - prev_mouse_pos.y) * 2;
    if (get_mouse_pos(rpg->window, rpg->size_x, rpg->size_y).x >
    prev_mouse_pos.x)
        rpg->slope -= (prev_mouse_pos.x -
        get_mouse_pos(rpg->window, rpg->size_x, rpg->size_y).x) * 0.001;
    camera_mouvement_inner(rpg, prev_mouse_pos);
    rpg->slope = reset_angle(rpg->slope);
    return (rpg);
}
