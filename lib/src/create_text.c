/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** create_text
*/

#include "../include/lib.h"

struct sfText *create_text(char *displayed_text, int size)
{
    sfText *text;
    sfFont *font = sfFont_createFromFile("assets/Shrek.ttf");
    if (!font)
        return (NULL);
    text = sfText_create();
    sfText_setString(text, displayed_text);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfBlack);
    return (text);
}
