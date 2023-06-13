/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** create_window
*/

#include "../include/lib.h"
#include <SFML/Window/Window.h>

sfRenderWindow* create_window(char *name, int size_x, int size_y)
{
    sfRenderWindow* window;
    window = sfRenderWindow_create((sfVideoMode) {size_x, size_y, 32},
    name, sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, 1);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
