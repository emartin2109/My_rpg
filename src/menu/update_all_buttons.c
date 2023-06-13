/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_buttons
*/

#include "structures.h"
#include "menu.h"
#include "lib.h"
#include "my_rpg.h"

void set_all_button(button_t **all_buttons, enum e_gui_state new_state,
rpg_t *rpg)
{
    if (all_buttons[1]->state != PRESSED)
        rpg = reinit_rpg_values(rpg);
    for (int i = 0; i < 11; i++)
        all_buttons[i]->state = new_state;
    sfWindow_setMouseCursorVisible((sfWindow *) rpg->window, sfFalse);
    sfMusic_play(rpg->music);
    sfMouse_setPositionRenderWindow((sfVector2i) {960, 540}, rpg->window);
}

button_t **update_all_buttons(button_t **buttons,
sfEvent *event, sfRenderWindow *window, rpg_t *rpg)
{
    for (int i = 0; i < 21; i++)
        buttons[i] = update_button(buttons[i], event, window, rpg);
    return (buttons);
}
