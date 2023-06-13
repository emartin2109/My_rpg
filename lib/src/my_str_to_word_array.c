/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-bsminishell1-yohan.decamps
** File description:
** my_str_to_word_array
*/

#include "../include/lib.h"

int count_words(char *str, char separator)
{
    int nb_words = 0;
    for (int i = 0; i < my_strlen(str) - 1; i++) {
        if (str[i] == separator)
            nb_words++;
    }
    return (nb_words + 1);
}

char **alloc_array(char *str, char separator)
{
    int word_size = 0;
    int word_nb = 0;
    char **array = malloc(sizeof(char *) * (count_words(str, separator) + 1));
    array[count_words(str, separator)] = NULL;
    if (array == NULL)
        return (NULL);
    for (int i = 0; i <= my_strlen(str); i++) {
        word_size++;
        if (str[i] == separator || i == my_strlen(str)) {
            array[word_nb] = malloc(sizeof(char) * (word_size + 1));
            word_nb++;
            word_size = 0;
        }
    }
    return (array);
}

char **my_str_to_word_array(char *str, char separator)
{
    int word_size = 0;
    int word_nb = 0;
    char **array = alloc_array(str, separator);
    word_nb = 0;
    word_size = 0;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] != separator) {
            array[word_nb][word_size] = str[i];
        } else {
            array[word_nb][word_size] = '\0';
            word_nb++;
            i++;
            word_size = 0;
            array[word_nb][word_size] = str[i];
        }
        word_size++;
    }
    if (word_nb == count_words(str, separator) - 1)
        array[word_nb][word_size] = '\0';
    return (array);
}
