/*
** EPITECH PROJECT, 2023
** pause_menu
** File description:
** pause_menu
*/
#include "menu.h"
#include "structures.h"
#include "my_rpg.h"
#include "system.h"
#include <stdio.h>

void draw_pause_menu(button_t **all_buttons, sfRenderWindow *window)
{
    draw_button(all_buttons[8], window);
    draw_button(all_buttons[9], window);
    draw_button(all_buttons[5], window);
    draw_button(all_buttons[6], window);
    draw_button(all_buttons[10], window);
}

int pause_menu(rpg_t *rpg)
{
    button_t **all_buttons = init_all_buttons(rpg);
    sfRenderWindow_setMouseCursorVisible(rpg->window, 1);
    while (all_buttons[8]->state != PRESSED &&
    sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, sfBlack);
        while (sfRenderWindow_pollEvent(rpg->window, rpg->event)) {
            analyse_button_events(rpg->event, rpg->window, all_buttons, rpg);
        }
        if (all_buttons[10]->state == PRESSED)
            return main_menu(rpg->window, rpg->event, rpg);
        if (all_buttons[9]->state == PRESSED)
            save(rpg);
        draw_all(rpg);
        draw_pause_menu(all_buttons, rpg->window);
        settings_menu(all_buttons, rpg, "pause_menu");
        sfRenderWindow_display(rpg->window);
    }
    sfRenderWindow_setMouseCursorVisible(rpg->window, 0);
    return 2;
}
