/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include "structures.h"

    /**
     * @brief This function catches the mouse position and its movements
     *
     * @param rpg - rpg_t structure
     * @param prev_mouse_pos - previous mouse position
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *camera_mouvement(rpg_t *rpg, sfVector2f prev_mouse_pos);

    /**
     * @brief This function changes the window's title to display the framerate
     *
     * @param rpg - rpg_t structure
     */
    void display_framerate(rpg_t *rpg);

#endif /* !WINDOW_H_ */
