/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** draw_button
*/

#include "structures.h"
#include "menu.h"

static void button_clicked(struct button_s *button)
{
    if (button->name != NULL)
    sfText_setColor(button->name, (sfColor) {255, 255, 255, 255});
    sfRectangleShape_setOutlineColor(button->rect,
    (sfColor) {114, 210, 184, 255});
    sfRectangleShape_setFillColor(button->rect,
    (sfColor) {114, 210, 184, 255});
}

static void button_hover(struct button_s *button)
{
    if (button->name != NULL)
    sfText_setColor(button->name, (sfColor) {124, 212, 187, 255});
    sfRectangleShape_setOutlineColor(button->rect,
    (sfColor) {124, 212, 187, 255});
    sfRectangleShape_setFillColor(button->rect,
    (sfColor) {255, 255, 255, 255});
}

static void button_default(struct button_s *button)
{
    if (button->name != NULL)
    sfText_setColor(button->name, (sfColor) {183, 232, 218, 255});
    sfRectangleShape_setOutlineColor(button->rect,
    (sfColor) {169, 214, 201, 255});
    sfRectangleShape_setFillColor(button->rect,
    (sfColor) {255, 255, 255, 255});
}

void draw_button(struct button_s *button, sfRenderWindow *window)
{
    switch (button->state) {
    case PRESSED:
        button_clicked(button);
        break;
    case HOVER:
        button_hover(button);
        break;
    case NONE:
        button_default(button);
        break;
    }
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
    sfRenderWindow_drawText(window, button->name, NULL);
}
