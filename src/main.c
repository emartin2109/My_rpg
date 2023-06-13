/*
** EPITECH PROJECT, 2023
** stumper04
** File description:
** main
*/

#include "lib.h"
#include "my_rpg.h"
#include "system.h"

int main(int __attribute__((unused))ac,
        char __attribute__((unused))**av,
        char **env)
{
    if (my_getenv(env, "DISPLAY") == NULL)
        return ERROR;
    return myrpg();
}
