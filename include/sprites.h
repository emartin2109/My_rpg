/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** sprites
*/

#ifndef SPRITES_H_
    #define SPRITES_H_

    #include "structures.h"

    /**
     * @brief This function draws a tile sprite on the map
     *
     * @param rpg - rpg_t structure
     * @param i - The current x position
     * @param j - The current y position
     * @param id - The ID of the given sprite
     */
    void draw_map_sprite(rpg_t *rpg, int i, int j, char id);

    /**
     * @brief This function draws the minimap
     *
     * @param rpg - rpg_t structure
     */
    void draw_map(rpg_t *rpg);

    /**
     * @brief This function initializes the sprites
     *
     * @param rpg - rpg_t structure
     * @param id - The ID of the sprite
     * @param file - The path to the image file
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_sprite(rpg_t *rpg, char id, char *file);

    /**
     * @brief This function initializes all the sprites
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_all_sprites(rpg_t *rpg);

    /**
     * @brief Creates a sprite object
     *
     * @param file - The path to the image file
     * @param scale - The scale of the sprite
     * @return sfSprite* - The created CSFML sfSprite object
     */
    sfSprite *create_sprite(char *file, sfVector2f scale);

#endif /* !SPRITES_H_ */
