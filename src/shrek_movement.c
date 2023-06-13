/*
** EPITECH PROJECT, 2023
** merge_save
** File description:
** shrek_movement
*/

#include "structures.h"
#include "my_rpg.h"
#include <stdio.h>

void move_shrek (rpg_t *rpg)
{
    sfVector2i shrek_coord = (sfVector2i) {rpg->entity[0].pos.x / 50,
    rpg->entity[0].pos.y / 50};
    sfVector2i player_coord = (sfVector2i) {rpg->player_pos.x / 50,
    rpg->player_pos.y / 50};
    int map_len = rpg->maps[rpg->level]->y;
    char **map = rpg->maps[rpg->level]->array;
    char **map_cpy = copy_char_array(map, map_len);
    char *instruction = find_path(map_cpy, &shrek_coord, &player_coord);
    if (instruction == NULL) {
        game_over_screen(rpg);
        return;
    }
    if (instruction[0] == 'u')
        rpg->entity->pos.y -= 2;
    if (instruction[0] == 'd')
        rpg->entity->pos.y += 2;
    if (instruction[0] == 'r')
        rpg->entity->pos.x += 2;
    if (instruction[0] == 'l')
        rpg->entity->pos.x -= 2;
}
