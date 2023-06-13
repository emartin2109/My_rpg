/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** system
*/

#ifndef SYSTEM_H
    #define SYSTEM_H

    #include "structures.h"
    #include <SFML/Graphics/Types.h>

    /**
     * @brief This function returns the value of the environment variable name,
     *        or NULL if the variable is not defined.
     *
     * @param env - environment variables array (Should never be NULL)
     * @param name - name of the environment variable (Should never be NULL)
     * @return char* - value of the environment variable
     */
    char *my_getenv(char **env, char *name);

    /**
     * SAVE SYSTEM
     */

    /**
     * @brief This function parses a save file and returns an array of
     *         save_entry_t
     *
     * @param filename - name of the save file
     * @return save_entry_t** - array of save_entry_t
     */
    save_entry_t **fetch_save(char *filename);

    /**
     * @brief This function returns the value of the save entry with the name
     *
     * @param save - array of save_entry_t
     * @param name - name of the save entry
     * @return char* - value of the save entry (NULL if not found)
     */
    char *save_getvalue(save_entry_t **save, char *name);

    /**
     * @brief This function sets the value of the save entry with the name
     *
     * @param save - array of save_entry_t
     * @param name - name of the save entry
     * @param value - value of the save entry
     * @return save_entry_t** - array of save_entry_t
     */
    save_entry_t **save_setvalue(save_entry_t **save, char *name, char *value);

    /**
     * @brief This functio removes the save entry with the name
     *
     * @param save - array of save_entry_t
     * @param name - name of the save entry
     * @return save_entry_t** - array of save_entry_t
     */
    save_entry_t **save_delvalue(save_entry_t **save, char *name);

    /**
     * @brief This function frees the save_entry_t array
     *
     * @param save - array of save_entry_t
     */
    void save_freesave(save_entry_t **save);

    /**
     * @brief This function writes the save_entry_t array to a file
     *
     * @param save - array of save_entry_t
     * @param filename - name of the save file
     * @return int - 0 if success, -1 if error
     */
    int save_writesave(save_entry_t **save, char *filename);

    /**
     * @brief This function save the nessesary information of the rpg struct
     *
     * @param rpg - the rpg struct, where the information to save is stored
     */
    void save (rpg_t *rpg);

    /**
     * @brief This function loads the nessesary saved information
     *        into the rpg struct
     *
     * @param rpg - the rpg struct, where the information to load is stored
     */
    void load (rpg_t *rpg);

#endif /* !SYSTEM_H */
