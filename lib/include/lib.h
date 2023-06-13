/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my
*/

#ifndef LIB_H_
    #define LIB_H_

    #define ERROR 84
    #define SUCCESS 0
    #define FAILURE 1
    #define pi 3.1415926535

    #include <unistd.h>
    #include <stdlib.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/stat.h>

    /**
     * @brief This function returns the length of a string
     *
     * @param str - The string to be measured (not NULL)
     * @return int - The length of the string
     */
    int my_strlen(char *str);

    /**
     * @brief Create a text object for buttons
     *
     * @param displayed_text - The text to be displayed (not NULL)
     * @param size - The size of the font
     * @return struct sfText* - The created CSFML sfText object
     */
    struct sfText *create_text(char *displayed_text, int size);

    /**
     * @brief Create a window object
     *
     * @param name - The name of the window
     * @param size_x - width of the window
     * @param size_y - height of the window
     * @return sfRenderWindow* - The created CSFML sfRenderWindow object
     */
    sfRenderWindow* create_window(char *name, int size_x, int size_y);

    /**
     * @brief This function splits a string into an array of strings
     *
     * @param str - The string to be split
     * @param separator - The separator to split the string with
     * @return char** - The array of strings
     */
    char **my_str_to_word_array(char *str, char separator);

    /**
     * @brief Get a string buffer from a file
     *
     * @param filename - The name of the file
     * @return char* - The string buffer
     */
    char *get_buffer(const char *filename);

    /**
     * @brief This function counts the number of words in a string
     *
     * @param str - The string to be counted (not NULL)
     * @param separator - The separator to split the string with
     * @return int - The number of words in the string
     */
    int count_words(char *str, char separator);

    /**
     * @brief This function turns an integer into a string
     *
     * @param x - The integer to be turned into a string
     * @return char* - The string representation of the integer
     */
    char *int_to_string(int x);

    /**
     * @brief This function concatenates two strings
     *
     * @param str1 - The first string
     * @param str2 - The second string
     * @return char* - The concatenated string
     */
    char *my_strcat(char *str1, char *str2);

    /**
     * @brief Comparing two strings and returning the difference
     *
     * @param s1 - The first string
     * @param s2 - The second string
     * @return int - The difference between the two strings (0 if equal)
     */
    int my_strcmp(char const *s1, char const *s2);

    /**
     * @brief This function returns a duped string
     *
     * @param str - The string to be duped (not NULL)
     * @return char* - The duplicated string
     */
    char *my_strdup(char const *str);

    /**
     * @brief This function returns a number from a string
     *
     * @param str - The string to be converted (not NULL)
     * @return int - The number from the string
     */
    int my_getnbr(char const *str);

    /**
     * @brief This function returns an array of int from an array of strings
     *
     * @param str_array - The array of strings to be converted (not NULL)
     * @return int* - The array of int
     */
    int *str_array_to_int(char **str_array);

#endif
