/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** draw_buttons
*/

#include "menu.h"
#include "structures.h"

void draw_all_buttons(button_t **all_buttons, sfRenderWindow *window)
{
    for (int i = 0; i < 23; i++)
        draw_button(all_buttons[i], window);
}

void draw_main_menu_buttons(button_t **buttons, sfRenderWindow *window)
{
    draw_button(buttons[0], window);
    draw_button(buttons[1], window);
    draw_button(buttons[5], window);
    draw_button(buttons[6], window);
    draw_button(buttons[7], window);
}
