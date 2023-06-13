/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** get_usr_input
*/

#include "my_rpg.h"
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *get_user_input(void)
{
    char *file = NULL;
    size_t line_size;
    write(1, "\x1B[34mEnter an image or nothing for default: \x1B[37m", 49);
    getline(&file, &line_size, stdin);
    if (file[0] == '\n') {
        write(1, "\x1B[32mDefault buffer loaded !\x1B[37m\n", 34);
        return ("assets/shrek-shocked.png");
    }
    file[my_strlen(file) - 1] = '\0';
    while (open(file, O_RDONLY) == -1) {
        write(1, "\x1B[31mImage not found.\n\x1B[34mTry again: \x1B[37m", 43);
        getline(&file, &line_size, stdin);
        if (file[0] == '\n') {
            write(1, "\x1B[32mDefault buffer loaded !\x1B[37m\n", 34);
            return ("assets/shrek-shocked.png");
        }
        file[my_strlen(file) - 1] = '\0';
    }
    write(1, "\x1B[32mImage Found !\n\x1B[37m", 24);
    return (file);
}
