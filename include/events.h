/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** events
*/

#ifndef EVENTS_H_
    #define EVENTS_H_

    #include "structures.h"

    #define INITIAL_DISTANCE_MULTIPLIER (sfVector2f) {\
    1, 1\
    }

    /**
     * @brief This function manages the events
     *
     * @param rpg - rpg_t structure
     * @return int - exit status
     */
    int manage_event(rpg_t *rpg);

    /**
     * @brief Registers Windows events and calls the appropriate functions
     *
     * @param window - The window to get the events from
     * @param event - The event to be analysed
     */
    void analyse_events(sfRenderWindow *window, sfEvent *event);

    /**
     * @brief Handle the events for the metal pipe,
     * and will print it correctly
     *
     * @param rpg - rpg_t structure
     */
    void metal_pipe_handler(rpg_t *rpg);

#endif /* !EVENTS_H_ */
