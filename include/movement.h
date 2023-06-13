/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** movement
*/

#ifndef MOVEMENT_H_
    #define MOVEMENT_H_

    #include "structures.h"
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

    /**
     * @brief Get the user input object
     *
     * @return char*
     */
    char *get_user_input(void);

    /**
     * @brief Get the mouse position object
     *
     * @param window - The window to get the mouse position from
     * @param rpg - rpg_t structure
     * @return sfVector2f - The mouse position
     */
    sfVector2f get_mouse_pos(sfRenderWindow *window, int x, int y);

    /**
     * @brief This function handles movement keystrokes
     *
     * @param rpg - rpg_t structure
     * @param speed - The speed of the player
     * @param key - The key pressed
     * @param angle - The current angle of direction of the player
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *handle_direction(rpg_t *rpg, float speed,
    sfKeyCode key, float angle);

    /**
     * @brief This function handles the players movement and collisions
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *handle_player_pos(rpg_t *rpg);

#endif /* !MOVEMENT_H_ */
