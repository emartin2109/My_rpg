/*
** EPITECH PROJECT, 2023
** hit entity
** File description:
** hit entity
*/
#include "my_rpg.h"
#include "structures.h"
#include "lib.h"
#include <math.h>

void entity_is_hit(rpg_t *rpg)
{
    double pipe_x = (cos(rpg->slope) * 10) + rpg->player_pos.x;
    double pipe_y = (sin(rpg->slope) * 10) + rpg->player_pos.y;
    if (pipe_x >= rpg->entity[0].pos.x - 150 &&
    pipe_x <= rpg->entity[0].pos.x + 150
    && pipe_y >= rpg->entity[0].pos.y - 150 &&
    pipe_y <= rpg->entity[0].pos.y + 150)
        rpg->entity[0].pv -= 1;
}
