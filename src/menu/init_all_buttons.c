/*
** EPITECH PROJECT, 2023
** init_all_buttons
** File description:
** init_all_buttons
*/
#include "menu.h"
#include "structures.h"

static void init_resolution_buttons(button_t **all_buttons, int x, int y)
{
    all_buttons[19] = init_button((sfVector2f) {x * 0.15625, y * 0.09259},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "1920 x 1080");
    all_buttons[20] = init_button((sfVector2f) {x * 0.15625, y * 0.185185},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "690 x 420");
}

static void init_settings_buttons(button_t **all_buttons, int x, int y)
{
    all_buttons[11] = init_button((sfVector2f) {x * 0.296875, y * 0.185185},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Resolution");
    init_resolution_buttons(all_buttons, x, y);
    all_buttons[12] = init_button((sfVector2f) {x * 0.296875, y * 0.27777},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Sensitivity");
    all_buttons[13] = init_button((sfVector2f) {x * 0.296875, y * 0.37037},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Move Forward");
    all_buttons[14] = init_button((sfVector2f) {x * 0.296875, y * 0.462962},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Move Backwards");
    all_buttons[15] = init_button((sfVector2f) {x * 0.296875, y * 0.555555},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Move Left");
    all_buttons[16] = init_button((sfVector2f) {x * 0.296875, y * 0.648148},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Move Right");
    all_buttons[17] = init_button((sfVector2f) {x * 0.296875, y * 0.74074},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Use");
    all_buttons[18] = init_button((sfVector2f) {x * 0.296875, y * 0.83333},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Interact");
}

static void init_pause_menu_button(button_t **all_buttons, int x, int y)
{
    all_buttons[8] = init_button((sfVector2f) {x * 0.4375, y * 0.27777},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Resume Game");
    all_buttons[9] = init_button((sfVector2f) {x * 0.4375, y * 0.370370},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Save");
    all_buttons[10] = init_button((sfVector2f) {x * 0.4375, y * 0.648148},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Exit to Main Menu");
}

static void init_main_menu_buttons(button_t **all_buttons, int x, int y)
{
    all_buttons[0] = init_button((sfVector2f) {x * 0.4375, y * 0.27777},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "New Game");
    all_buttons[1] = init_button((sfVector2f) {x * 0.4375, y * 0.370370},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Load Game");
    all_buttons[2] = init_button((sfVector2f) {x * 0.578125, y * 0.24074},
    (sfVector2f) {x * 0.104166, y * 0.06481}, "Save 1");
    all_buttons[3] = init_button((sfVector2f) {x * 0.578125, y * 0.32407},
    (sfVector2f) {x * 0.104166, y * 0.06481}, "Save 2");
    all_buttons[4] = init_button((sfVector2f) {x * 0.578125, y * 0.4074},
    (sfVector2f) {x * 0.104166, y * 0.06481}, "Save 3");
    all_buttons[5] = init_button((sfVector2f) {x * 0.4375, y * 0.462962},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Settings");
    all_buttons[6] = init_button((sfVector2f) {x * 0.4375, y * 0.555555},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "How to Play");
    all_buttons[7] = init_button((sfVector2f) {x * 0.4375, y * 0.648148},
    (sfVector2f) {x * 0.130208, y * 0.06481}, "Exit");
}

button_t **init_all_buttons(rpg_t *rpg)
{
    button_t **all_buttons = malloc(sizeof(button_t *) * 21);
    if (all_buttons == NULL)
        return NULL;
    for (int i = 0; i < 21; i++) {
        all_buttons[i] = malloc(sizeof(button_t));
        if (all_buttons[i] == NULL)
            return NULL;
    }
    init_main_menu_buttons(all_buttons, rpg->size_x, rpg->size_y);
    init_pause_menu_button(all_buttons, rpg->size_x, rpg->size_y);
    init_settings_buttons(all_buttons, rpg->size_x, rpg->size_y);
    return all_buttons;
}
