/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** end_screen
*/

#include "lib.h"
#include "structures.h"
#include "menu.h"
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>

void end_screen(rpg_t *rpg)
{
    sfClock *clock = sfClock_create();
    sfText *text = create_text("You won !\nSUS triumphs", 150);
    sfText_setPosition(text, (sfVector2f) {150, 500});
    sfText_setColor(text, sfWhite);
    while (sfRenderWindow_isOpen(rpg->window) &&
        sfClock_getElapsedTime(clock).microseconds < 5000000) {
        sfRenderWindow_clear(rpg->window, sfBlack);
        sfRenderWindow_drawText(rpg->window, text, NULL);
        sfRenderWindow_display(rpg->window);
    }
    sfRenderWindow_setMouseCursorVisible(rpg->window, 0);
    sfClock_destroy(clock);
    sfText_destroy(text);
    sfRenderWindow_close(rpg->window);
}

int game_over_screen(rpg_t *rpg)
{
    sfClock *clock = sfClock_create();
    sfText *text = create_text("You loose !\nShrek got you", 150);
    sfText_setPosition(text, (sfVector2f) {150, 500});
    sfText_setColor(text, sfWhite);
    while (sfRenderWindow_isOpen(rpg->window) &&
        sfClock_getElapsedTime(clock).microseconds < 2500000) {
        sfRenderWindow_clear(rpg->window, sfBlack);
        sfRenderWindow_drawText(rpg->window, text, NULL);
        sfRenderWindow_display(rpg->window);
    }
    return main_menu(rpg->window, rpg->event, rpg);
}
