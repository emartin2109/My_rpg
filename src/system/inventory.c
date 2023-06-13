/*
** EPITECH PROJECT, 2023
** inventory
** File description:
** inventory
*/
#include "menu.h"
#include "lib.h"
#include "structures.h"



int inventory(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->inventory_back, NULL);
    return 0;
}
