/*
** EPITECH PROJECT, 2023
** merge_save
** File description:
** load
*/

#include "structures.h"
#include "system.h"
#include <stdio.h>

static float get_float_from_str(char* str)
{
    int result = 0;
    float decimal = 0.0;
    float divisor = 1.0;
    while (*str != '.') {
        result = result * 10 + (*str - '0');
        ++str;
    }
    str++;
    while (*str) {
        decimal = decimal + ((*str - '0') / divisor);
        divisor *= 10;
        ++str;
    }
    return result + decimal;
}

void load (rpg_t *rpg)
{
    if (rpg->save_entry == NULL) {
        game_over_screen(rpg);
        return;
    }
    char *pos_x = save_getvalue(rpg->save_entry, "pos_x");
    char *pos_y = save_getvalue(rpg->save_entry, "pos_y");
    rpg->player_pos.x = get_float_from_str(pos_x);
    rpg->player_pos.y = get_float_from_str(pos_y);
    char *shrek_pos_x = save_getvalue(rpg->save_entry, "shrek_pos_x");
    char *shrek_pos_y = save_getvalue(rpg->save_entry, "shrek_pos_y");
    rpg->entity->pos.x = get_float_from_str(shrek_pos_x);
    rpg->entity->pos.y = get_float_from_str(shrek_pos_y);
    char *level = save_getvalue(rpg->save_entry, "level");
    rpg->level = get_float_from_str(level);
    char *speed = save_getvalue(rpg->save_entry, "speed");
    rpg->speed = get_float_from_str(speed);
}
