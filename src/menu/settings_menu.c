/*
** EPITECH PROJECT, 2023
** settings_menu
** File description:
** settings_menu
*/
#include "menu.h"
#include "structures.h"
#include "lib.h"

void draw_settings_buttons(button_t **all_buttons, rpg_t *rpg)
{
    draw_button(all_buttons[11], rpg->window);
    draw_button(all_buttons[12], rpg->window);
    draw_button(all_buttons[13], rpg->window);
    draw_button(all_buttons[14], rpg->window);
    draw_button(all_buttons[15], rpg->window);
    draw_button(all_buttons[16], rpg->window);
    draw_button(all_buttons[17], rpg->window);
    draw_button(all_buttons[18], rpg->window);
}

void set_settings_button(int state, button_t **all_buttons)
{
    all_buttons[11]->state = state;
    all_buttons[12]->state = state;
    all_buttons[13]->state = state;
    all_buttons[14]->state = state;
    all_buttons[15]->state = state;
    all_buttons[16]->state = state;
    all_buttons[17]->state = state;
    all_buttons[18]->state = state;
}

int resolution_menu_little_window(button_t **buttons, rpg_t *rpg, char *menu)
{
    sfRenderWindow_close(rpg->window);
    rpg->window = create_window("RPG", 960, 540);
    rpg->size_x = 960;
    rpg->size_y = 540;
    buttons[20]->state = NONE;
    if (my_strcmp(menu, "main_menu") == 0)
        return main_menu(rpg->window, rpg->event, rpg);
    return pause_menu(rpg);
}

int resolution_menu (button_t **all_button, rpg_t *rpg, char *menu)
{
    draw_button(all_button[19], rpg->window);
    draw_button(all_button[20], rpg->window);
    if (all_button[19]->state == PRESSED) {
        sfRenderWindow_close(rpg->window);
        rpg->window = create_window("RPG", 1920, 1080);
        rpg->size_x = 1920;
        rpg->size_y = 1080;
        all_button[19]->state = NONE;
        if (my_strcmp(menu, "main_menu") == 0)
            return main_menu(rpg->window, rpg->event, rpg);
        return pause_menu(rpg);
    }
    if (all_button[20]->state == PRESSED)
        return resolution_menu_little_window(all_button, rpg, menu);
    return 1;
}

int settings_menu(button_t **all_buttons, rpg_t *rpg, char *menu)
{
    if (all_buttons[5]->state == PRESSED)
        draw_settings_buttons(all_buttons, rpg);
    if (all_buttons[5]->state == NONE)
        set_settings_button(NONE, all_buttons);
    if (all_buttons[13]->state == PRESSED)
        rpg->key_binds->forward = keybind(rpg, all_buttons[13]);
    if (all_buttons[14]->state == PRESSED)
        rpg->key_binds->backward = keybind(rpg, all_buttons[14]);
    if (all_buttons[15]->state == PRESSED)
        rpg->key_binds->left = keybind(rpg, all_buttons[15]);
    if (all_buttons[16]->state == PRESSED)
        rpg->key_binds->right = keybind(rpg, all_buttons[16]);
    if (all_buttons[11]->state == PRESSED &&
    resolution_menu(all_buttons, rpg, menu) != 1)
        all_buttons[8]->state = PRESSED;
    return 0;
}
