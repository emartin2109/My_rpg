/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** switch_level
*/

#include "my_rpg.h"
#include "structures.h"
#include <stdlib.h>

int switch_level(rpg_t *rpg, int level)
{
    if (rpg == NULL)
        return 1;
    if (level < 0 || level >= MAPS_COUNT)
        return 1;
    if (rpg->maps[level] == NULL)
        return 1;
    rpg->level = level;
    rpg->player_pos.x = rpg->maps[level]->meta[0] * 50;
    rpg->player_pos.y = rpg->maps[level]->meta[1] * 50;
    rpg->entity->pos.x = rpg->maps[level]->meta[4] * 50;
    rpg->entity->pos.y = rpg->maps[level]->meta[5] * 50;
    return 0;
}
