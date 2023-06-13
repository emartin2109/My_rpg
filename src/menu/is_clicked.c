/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** is_clicked
*/

#include "menu.h"
#include "structures.h"
#include "movement.h"

sfBool is_clicked(struct button_s* button, sfRenderWindow *window, rpg_t *rpg)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f rect_size = sfRectangleShape_getSize(button->rect);
    sfVector2f mouse_pos = get_mouse_pos(window, rpg->size_x, rpg->size_y);

    if (rect_pos.x < mouse_pos.x && rect_pos.y < mouse_pos.y) {
        if (rect_pos.x + rect_size.x > mouse_pos.x && rect_pos.y +
        rect_size.y > mouse_pos.y) {
            return (sfTrue);
        }
    }
    return (sfFalse);
}
