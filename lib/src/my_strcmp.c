/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int pointer = 0;
    while (s1[pointer] == s2[pointer] && s1[pointer] != '\0'
            && s2[pointer] != '\0')
        pointer += 1;

    if (!s1[pointer] || !s2[pointer])
        return 0;
    return s1[pointer] - s2[pointer];
}
