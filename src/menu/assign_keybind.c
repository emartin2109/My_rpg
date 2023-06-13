/*
** EPITECH PROJECT, 2023
** assign_keybind
** File description:
** assign_keybind
*/
#include "structures.h"
#include "menu.h"

int keybind(rpg_t *rpg, button_t *button)
{
    sfRenderWindow_waitEvent(rpg->window, rpg->event);
    button->state = NONE;
    return rpg->event->key.code;
}
