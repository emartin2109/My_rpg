/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** getenv
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "lib.h"

static int my_cmpenv(char *name, char *env)
{
    int i = 0;

    while (name[i] != '\0' && env[i] != '\0') {
        if (name[i] != env[i])
            return 0;
        i++;
    }
    if (env[i] == '=')
        return 1;
    return 0;
}

char *my_getenv(char **env, char *name)
{
    int len = my_strlen(name);
    for (int i = 0; env[i];) {
        if (my_cmpenv(name, env[i]))
            return &env[i][len + 1];
        ++i;
    }
    return NULL;
}
