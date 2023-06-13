/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** level_selector
*/

#include "lib.h"
#include "menu.h"
#include "my_rpg.h"
#include "structures.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>

static void init_buttons(button_t **buttons, rpg_t *rpg)
{
    buttons[0] = init_button((sfVector2f) {200, 200},
        (sfVector2f) {150, 50}, "Level 1");
    buttons[1] = init_button((sfVector2f) {410, 200}, (sfVector2f) {150, 50},
        "Level 2");
    buttons[2] = init_button((sfVector2f) {620, 200}, (sfVector2f) {150, 50},
        "Level 3");
    buttons[3] = init_button((sfVector2f) {830, 200}, (sfVector2f) {150, 50},
        "Level 4");
    buttons[4] = init_button((sfVector2f) {1040, 200}, (sfVector2f) {150, 50},
        "Level 5");
    buttons[5] = init_button((sfVector2f) {1250, 200}, (sfVector2f) {150, 50},
        "Level 6");
}

static void draw_selector(button_t **buttons, sfRenderWindow *window)
{
    for (int i = 0; i < 6;i++)
        draw_button(buttons[i], window);
}

static void handle_events(sfEvent *event, sfRenderWindow *window,
    button_t **buttons, rpg_t *rpg)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    update_button(buttons[rpg->level + 1], rpg->event, rpg->window, rpg);
    if (buttons[rpg->level + 1]->state == PRESSED) {
        rpg->level_selector = 0;
        switch_level(rpg, rpg->level + 1);
        buttons[rpg->level - 1]->state = NONE;
    }
}

static void free_buttons(button_t **buttons)
{
    for (int i = 0; i < 6; i++) {
        sfText_destroy(buttons[i]->name);
        sfRectangleShape_destroy(buttons[i]->rect);
        free(buttons[i]);
    }
}

void level_selector(rpg_t *rpg)
{
    rpg->level_selector = true;
    if (rpg->level == MAPS_COUNT - 1)
        return end_screen(rpg);
    button_t *buttons[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
    init_buttons(buttons, rpg);
    sfRenderWindow_setMouseCursorVisible(rpg->window, 1);
    while (rpg->level_selector &&
    sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, sfBlack);
        while (sfRenderWindow_pollEvent(rpg->window, rpg->event)) {
            handle_events(rpg->event, rpg->window, buttons, rpg);
        }
        draw_selector(buttons, rpg->window);
        sfRenderWindow_display(rpg->window);
    }
    sfRenderWindow_setMouseCursorVisible(rpg->window, 0);
    free_buttons(buttons);
}
