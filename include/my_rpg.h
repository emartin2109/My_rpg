/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my
*/

#ifndef MYRPG_H_
    #define MYRPG_H_

    #include "structures.h"

    #define MAPS_COUNT 6

    /**
     * @brief The main function for the project
     *
     * @return int - Exit status
     */
    int myrpg(void);

    /**
     * @brief This function initializes all the values of the rpg_t structure
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_all_values(rpg_t *rpg);

    /**
     * @brief This function initializes all the program's variables
     *
     * @return rpg_t* - The initialized
     */
    rpg_t *init_rpg_variables(void);

    /**
     * @brief This function initializes the sounds
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_sounds(rpg_t *rpg);

    /**
     * @brief This function initializes the map
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_maps(rpg_t *rpg);

    /**
     * @brief This function initializes the mouse structure
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_mouse(rpg_t *rpg);

    /**
     * @brief This function draw all the game elements
     *
     * @param rpg - rpg_t structure
     * @return void
    */
    void draw_all(rpg_t *rpg);

    /**
     * @brief This function reinitialyses the value of rpg stuct
     *
     * @param rpg - rpg_t struture
     * @return rpg_t srtucture
    */
    rpg_t *reinit_rpg_values(rpg_t *rpg);

    /**
     * @brief this function copy a char **
     *
     * @param original the char ** that need to be copied
     * @param length the length of the char **
     * @return char**
     */
    char **copy_char_array(char** original, int length);

    /**
     * @brief this function free a char **
     *
     * @param map the char ** that need to be freed
     * @param y the lenght of the char **
    */
    void free_map(int y, int **map);

    /**
     * @brief add the node in x, y to the queu
     *
     * @param x the coordinate of the node to be added to queue
     * @param y the coordinate of the node to be added to queue
     * @param head the head of the queue
    */
    queu_t *add_to_queu (const int x, const int y, queu_t *head,
    char *instruction);

    /**
     * @brief switch current node to current->next
     *
     * @param queu the current node that need to be switched
     * @return queu_t*
    */
    queu_t * next_in_queu(queu_t * queu);

    /**
     * @brief add the next node that need to be visited to the queue
     *
     * @param queu the current node to current->next
     * @param map the map
     * @return queu_t*
    */
    queu_t * get_next_visit(queu_t *queu, char **map);

    /**
     * @brief Switches the level
     *
     * @param rpg - rpg_t structure
     * @return int - return status
     */
    int switch_level(rpg_t *rpg, int level);

    /**
     * @brief This function frees the memory allocated for the rpg_t structure
     *
     * @param rpg - rpg_t structure
     */
    void freemem(rpg_t *rpg);

    /**
     * @brief This function init default key binds
     *
     * @param rpg - rpg_t structure
     * @return rpg_t structure
     */
    rpg_t *init_key_binds(rpg_t *rpg);

    /**
     * @brief find path for shrek to go to the player
     *
     * @param map a clone of the map
     * @param start the coordinate of shrek
     * @param end the coordinate of the player
     * @return char * instruction for shrek
     */
    char *find_path (char **map, sfVector2i *start, sfVector2i *end);

    void move_shrek (rpg_t *rpg);
    char *my_strcat_no_free (char *dest, char *src);
    void button_handler(rpg_t *rpg);

#endif /* !MY_H_ */
