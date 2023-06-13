/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_button
*/

#include "structures.h"
#include "menu.h"
#include "my_rpg.h"

static sfText *create_text(char *str)
{
    sfText *text = sfText_create();
    sfFont *shrek = sfFont_createFromFile("assets/Shrek.ttf");
    sfText_setFont(text, shrek);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 30);
    return text;
}

static sfText *init_text_for_button(char *text_str, sfVector2f size,
sfVector2f pos)
{
    size.x *= 0.7;
    size.y *= 0.7;
    pos.x += size.x * 0.15;
    pos.y += size.y * 0.15;
    sfText *text = create_text(text_str);
    sfText_setColor(text, (sfColor) {41, 41, 41, 255});
    if (text == NULL)
        return (NULL);
    sfFloatRect text_bounds = sfText_getGlobalBounds(text);
    while (text_bounds.width >= size.x || text_bounds.height >= size.y) {
        sfText_setCharacterSize(text, sfText_getCharacterSize(text) - 1);
        text_bounds = sfText_getGlobalBounds(text);
    }
    sfText_setPosition(text, (sfVector2f) {pos.x + (size.x / 2) -
    (text_bounds.width / 2), pos.y + (size.y / 2) - (text_bounds.height / 2)});
    return (text);
}

button_t *init_text(sfVector2f size, char *text, button_t *button)
{
    if (text == NULL) {
        button->name = NULL;
    } else {
        button->name = init_text_for_button(text, size,
        sfRectangleShape_getPosition(button->rect));
        if (button->name == NULL)
            return (NULL);
    }
    return (button);
}

button_t *init_button(sfVector2f pos, sfVector2f size,
char *text)
{
    struct button_s *button = malloc(sizeof(button_t));
    if (button == NULL)
        return (NULL);
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, sfYellow);
    sfRectangleShape_setOutlineThickness(button->rect, 4);
    sfRectangleShape_setOutlineColor(button->rect, sfBlack);

    button = init_text(size, text, button);
    button->is_clicked = is_clicked;
    button->is_hover = is_hover;
    button->state = NONE;
    button->is_toggle = sfTrue;
    return (button);
}
