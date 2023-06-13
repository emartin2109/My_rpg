/*
** EPITECH PROJECT, 2023
** merge_save
** File description:
** get_str_from_nbr
*/

#include "lib.h"
#include "structures.h"
#include "system.h"
#include <stdio.h>
#include <math.h>

static char * get_str_from_int (int nb, int nb_len, int i, int precision)
{
    char *result;
    int result_index = 0;
    result = malloc((nb_len + precision + 3) * sizeof(char));
    if (nb < 0)
        result[result_index++] = '-';
    nb = abs(nb);
    while (nb_len-- > -1) {
        result[result_index++] = (nb / i) + '0';
        nb = nb - ((nb / i) * i);
        i = i / 10;
    }
    result[result_index++] = '.';
    result[result_index] = '\0';
    return result;
}

char * get_str_from_nb (float nb, char *result, int precision, int i)
{
    int index = 0;
    int nbr = 0;
    while (index++ < precision) {
        nb = nb * 10;
        nbr = (int) nb;
        result[i++] = nbr + '0';
        nb = nb - nbr;
    }
    result[i] = '\0';
    return result;
}

char *get_str_from_float(float number, int precision)
{
    char *result = malloc(sizeof(char) * (precision + 2));
    int nb = (int) number;
    int nb_len = 0;
    int i = 1;
    while ((abs(nb) / i) >= 10) {
        nb_len++;
        i = i * 10;
    }
    result = get_str_from_int (nb, nb_len, i, precision);
    i = 0;
    while (result[i] != '\0')
        i++;
    number = number - nb;
    result = get_str_from_nb(number, result, precision, i);
    return result;
}

void save (rpg_t *rpg)
{
    save_entry_t **save_info = rpg->save_entry;
    if (save_info == NULL) {
        save_info = malloc(sizeof(save_entry_t *));
        save_info[0] = NULL;
    }
    char *pos_x = get_str_from_float(rpg->player_pos.x, 5);
    char *pos_y = get_str_from_float(rpg->player_pos.y, 5);
    save_info = save_setvalue(save_info, "pos_x", pos_x);
    save_info = save_setvalue(save_info, "pos_y", pos_y);
    char *shrek_pos_x = get_str_from_float(rpg->entity->pos.x, 5);
    char *shrek_pos_y = get_str_from_float(rpg->entity->pos.y, 5);
    save_info = save_setvalue(save_info, "shrek_pos_x", shrek_pos_x);
    save_info = save_setvalue(save_info, "shrek_pos_y", shrek_pos_y);
    char *level = get_str_from_float(rpg->level, 1);
    save_info = save_setvalue(save_info, "level", level);
    char *speed = get_str_from_float(rpg->speed, 1);
    save_info = save_setvalue(save_info, "speed", speed);
    save_writesave(save_info, "save1");
}
