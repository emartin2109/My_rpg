/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dialogs
*/

#ifndef DIALOGS_H_
    #define DIALOGS_H_

    #include "structures.h"

    #define TEXT_SIZE 50
    #define NAME_SIZE 70
    #define NAME_POSITION (sfVector2u) {\
    310, 460\
    }
    #define TEXT_POSITION (sfVector2u) {\
    100, 350\
    }

    /**
     * @brief Create a dialog object from a name, a text and a time
     *
     * @param dialogs The current piled dialogs
     * @param name The name of the dialog
     * @param text The text of the dialog
     * @param time The time the dialog will be displayed
     * @return dialog_t* The new dialog
     */
    dialog_t *create_dialog(dialog_t *dialogs,
                            char *name,
                            char *text,
                            int time);

    /**
     * @brief Initialize the dialog sprite
     *
     * @return sfSprite* The dialog sprite
     */
    sfSprite *init_dialog_sprite(void);

    /**
     * @brief Display the dialogs
     *
     * @param rpg The rpg_t structure
     */
    void display_dialogs(rpg_t *rpg);

    /**
     * @brief Free the dialog object
     *
     * @param dialog The dialog to free
     */
    void free_dialog(dialog_t *dialog);

    /**
     * @brief Free the dialogs
     *
     * @return sfSprite* The dialog bubble sprite
     */
    sfSprite *init_dialog_sprite(void);

#endif /* !DIALOGS_H_ */
