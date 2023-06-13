/*
** EPITECH PROJECT, 2023
** main_menu
** File description:
** main_menu
*/
#include "menu.h"
#include "my_rpg.h"
#include "structures.h"
#include "sprites.h"
#include "system.h"
#include <unistd.h>
#include <stdio.h>
#include "system.h"
#include "lib.h"
#include <SFML/Graphics/Sprite.h>

void show_saves(button_t **all_buttons, sfRenderWindow *window)
{
    draw_button(all_buttons[2], window);
    draw_button(all_buttons[3], window);
    draw_button(all_buttons[4], window);
}

void how_to_play(button_t **all_buttons, rpg_t *rpg)
{
    if (all_buttons[6]->state == PRESSED) {
        static sfSprite *draw;
        if (draw == NULL)
            draw = sfSprite_create();
        sfRenderTexture_drawText(rpg->how_to_play_back,
        rpg->how_to_play_text, NULL);
        sfSprite_setTexture(draw,
        sfRenderTexture_getTexture(rpg->how_to_play_back), 0);
        sfSprite_setPosition(draw, (sfVector2f) {1300, 900});
        sfSprite_setScale(draw, (sfVector2f) {1, -1});
        sfRenderWindow_drawSprite(rpg->window, draw, NULL);
        sfSprite_destroy(draw);
    }
}

static void main_menu_handler(button_t **all_buttons, sfRenderWindow *window,
rpg_t *rpg)
{
    if (all_buttons[1]->state == PRESSED)
        load(rpg);
    settings_menu(all_buttons, rpg, "main_menu");
    how_to_play(all_buttons, rpg);
    draw_main_menu_buttons(all_buttons, window);
}

void analyse_button_events(sfEvent *event, sfRenderWindow *window,
button_t **all_buttons, rpg_t *rpg)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    update_all_buttons(all_buttons, event, window, rpg);
}

int main_menu(sfRenderWindow *window, sfEvent *event, rpg_t *rpg)
{
    sfRenderWindow_setMouseCursorVisible(window, 1);
    sfMusic_stop(rpg->music);
    button_t **all_buttons = init_all_buttons(rpg);
    sfSprite *background = create_sprite("assets/shrek_background.png",
    (sfVector2f) {1.6,1.4});
    while (sfRenderWindow_isOpen(window) && all_buttons[0]->state != PRESSED &&
    all_buttons[1]->state != PRESSED) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background, NULL);
        while (sfRenderWindow_pollEvent(window, event))
            analyse_button_events(event, window, all_buttons, rpg);
        if (all_buttons[7]->state == PRESSED) {
            sfRenderWindow_close(window);
            return 0;
        }
        main_menu_handler(all_buttons, window, rpg);
        sfRenderWindow_display(window);
    }
    set_all_button(all_buttons, NONE, rpg);
    return 0;
}
