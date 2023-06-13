/*
** EPITECH PROJECT, 2023
** main_menu.h
** File description:
** main_menu.h
*/

#ifndef MAIN_MENU_H_
    #define MAIN_MENU_H_

    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics.h>
    #include <SFML/Config.h>
    #include <stdlib.h>
    #include "structures.h"

    /**
     * @brief this function returns sfTrue if the mouse is hover the button
     *
     * @param button - button_t structure
     * @param window - sfRenderWindow *
     * @param rpg - rpg_t structure
     *
     * @return sfBool - sfTRue ou sfFalse
     */
    sfBool is_hover(struct button_s *button, sfRenderWindow *window,
    rpg_t *rpg);

    /**
     * @brief this funtion returns sfTrue if the button is cliked
     *
     * @param button - button_t structure
     * @param window - sfRenderWidow *
     * @param rpg - rpg_t structure
     * @return sfBool - sfTrue or sfFalse
     */
    sfBool is_clicked(struct button_s *button, sfRenderWindow *window,
    rpg_t *rpg);

    /**
     * @brief initialises a new button_t stucture
     *
     * @param pos - button position
     * @param size - button size
     * @param text - text that will be written on the button
     * @return button_t* initialised button
     */
    button_t *init_button(sfVector2f pos, sfVector2f size, char *text);

    /**
     * @brief draw a button
     *
     * @param button _ button to draw
     * @param window - window on wich to draw
     */
    void draw_button(struct button_s *button, sfRenderWindow *window);

    /**
     * @brief updates the button state depending on the event
     *
     * @param button - button to update
     * @param event - sfEvent*
     * @param window - sfRenderWindow*
     * @return struct button_s*
     */
    struct button_s *update_button(struct button_s *button, sfEvent *event,
                                    sfRenderWindow *window, rpg_t *rpg);

    /**
     * @brief this function draws all the buttons
     *
     * @param all_buttons - button_t ** list of all the buttons
     * @param window - window on wich to draw the buttons
     */
    void draw_all_buttons(button_t **all_buttons, sfRenderWindow *window);

    /**
     * @brief this fucntions initialises all the buttons needeed for the menus
     *
     * @param rpg - rpg_t structure
     * @return button_t** list of all the buttons
     */
    button_t **init_all_buttons(rpg_t *rpg);

    /**
     * @brief this fuction displays, handle and update the main menu
     *
     * @param window - window on wich the buttons will be displayed
     * @param event - sfEvent
     * @param rpg - rpg_t structure
     * @return int - Exit status
     */
    int main_menu(sfRenderWindow *window, sfEvent *event, rpg_t *rpg);

    /**
     * @brief updates all the buttons
     *
     * @param buttons - list of all the buttons
     * @param event - sfEvent
     * @param window - window on wich the buttons are displayed
     * @return button_t** updated list of all the buttons
     */
    button_t **update_all_buttons(button_t **buttons, sfEvent *event,
    sfRenderWindow *window, rpg_t *rpg);

    /**
     * @brief draws all the button consisting in the main menu
     *
     * @param buttons - list of all the buttons
     * @param window - window on wich to draw
     */
    void draw_main_menu_buttons(button_t **buttons, sfRenderWindow *window);

    /**
     * @brief Set the state of all the buttons
     *
     * @param all_buttons - list of all the buttons
     * @param rpg - rpg_t structure
     * @param new_state - state to update
     */
    void set_all_button(button_t **all_buttons, enum e_gui_state new_state,
    rpg_t *rpg);

    /**
     * @brief draw all the buttons constiting in the pause menu
     *
     * @param all_buttons - list of all the buttons
     * @param window - window on wich to draw the buttons
     */
    void draw_pause_menu(button_t **all_buttons, sfRenderWindow *window);

    /**
     * @brief handle, display and update the pause menu
     *
     * @param rpg - rpg_t structure
     * @return int - Exit status
     */
    int pause_menu(rpg_t *rpg);

    /**
     * @brief analyse the envents and updates the buttons accordigly
     *
     * @param event - sfEvent *
     * @param window - window on wich we have to update
     * @param all_buttons - list of all the buttons
     * @param rpg - rpg_t structure
     */
    void analyse_button_events(sfEvent *event, sfRenderWindow *window,
                                button_t **all_buttons, rpg_t *rpg);

    /**
     * @brief stops the music
     *
     * @param music - music to stop
     */
    void sfMusic_stop(sfMusic *music);

    /**
     * @brief handle the settings menu
     *
     * @param all_buttons
     * @param rpg
     * @param menu - indicates wich menu the function was called from
     * @return int
     */
    int settings_menu(button_t **all_buttons, rpg_t *rpg, char *menu);

    /**
     * @brief assign a key to a specific action
     *
     * @param rpg - rpg_t structure
     * @param button - button structure - tells wich action will be binded
     * @return sfKeyCode
     */
    int keybind(rpg_t *rpg, button_t *button);

    /**
     * @brief handle the keybind menu
     *
     * @param all_buttons - list of all the buttons
     * @param rpg - rpg_t structure
     * @return int - Exit status
     */
    void level_selector(rpg_t *rpg);

    /**
     * @brief Displays the end screen
     *
     * @param rpg rpg_t structure
     */
    void end_screen(rpg_t *rpg);

    /**
     * @brief disply the player inventory
     *
     * @param rpg
     * @return int
     */
    int inventory(rpg_t *rpg);

    /**
     * @brief game over screen
     *
     * @param rpg
     * @return int
     */
    int game_over_screen(rpg_t *rpg);

#endif /* !MAIN_MENU_H_ */
