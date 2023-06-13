/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** entity
*/

#ifndef ENTITY_H_
    #define ENTITY_H_

    #include "structures.h"

    /**
     * @brief animate the entities by moving the sfIntRectangle in there sprite
     *
     * @param rpg - the rpg_t structure
     */
    void animate_entities(rpg_t *rpg);

    /**
     * @brief This function initializes the entity structure
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_entity(rpg_t *rpg);

    /**
     * @brief reduce ennemy pv if hit
     *
     * @param rpg
     */
    void entity_is_hit(rpg_t *rpg);

#endif /* !ENTITY_H_ */
