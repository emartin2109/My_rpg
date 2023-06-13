/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** get_mouse_pos
*/

#include "my_rpg.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Mouse.h>

sfVector2f get_mouse_pos(sfRenderWindow *window, int x, int y)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f mouse_pos = (sfVector2f) {
    sfMouse_getPositionRenderWindow(window).x * x / window_size.x,
    sfMouse_getPositionRenderWindow(window).y * (y * 0.93611) / window_size.y};
    return (mouse_pos);
}
