/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** raycast
*/

#ifndef RAYCAST_H_
    #define RAYCAST_H_

    #include "structures.h"

    /**
     * @brief This functions casts a ray in front of the player to detect walls
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *draw_all_ray_casts(rpg_t *rpg);

    /**
     * @brief This function initializes the shapes
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_shapes(rpg_t *rpg);

    /**
     * @brief return if it hit the x axis or y axis
     *
     * @param xprd - hit point x coordinate
     * @param yprd - hit point y coordinate
     * @return int - 1 or 0, 1 if is vertical
     */
    int is_vertical(float xprd, float yprd);

    /**
     * @brief return the cotangente of x
     *
     * @param x the angle in radians
     * @return double - cotangente of x
     */
    double cot(double x);

    /**
     * @brief return the angle between the two points
     *
     * @param p1 - coordonates of the first point
     * @param p2 - coordonates of the second point
     * @return float - the angle between the points in radian
     */
    float angle_between(sfVector2f p1, sfVector2f p2);

    /**
     * @brief Get the best hitpoint and distance object
     *
     * @param rpg - rpg_t structure
     * @param pointx - the hit point of the ray in x
     * @param pointy - the hit point of the ray in y
     * @return ray_cast_t* - the lower distance and the closest point
     */
    ray_cast_t *get_best_hitpoint_and_distance(rpg_t *rpg,
    sfVector2f pointx, sfVector2f pointy);

    /**
     * @brief check if the ray is colliding with a wall in the x axis
     *
     * @param rpg - rpg_t structure
     * @param pointx - the current hit point of the ray in x
     * @return int - 0 or 1, 1 if the ray is colliding with a wall
     */
    int is_colliding_x(rpg_t *rpg, sfVector2f pointx);

    /**
     * @brief check if the ray is colliding with a wall in the y axis
     *
     * @param rpg - rpg_t structure
     * @param pointx - the current hit point of the ray in y
     * @return int - 0 or 1, 1 if the ray is colliding with a wall
     */
    int is_colliding_y(rpg_t *rpg, sfVector2f pointy);

    /**
     * @brief Get the hitpoint in the x axis
     *
     * @param rpg - rpg_t structure
     * @return sfVector2f - the hit point
     */
    sfVector2f get_hitpoint_x(rpg_t * rpg);

    /**
     * @brief Get the hitpoint in the y axis
     *
     * @param rpg - rpg_t structure
     * @return sfVector2f - the hit point
     */
    sfVector2f get_hitpoint_y(rpg_t * rpg);

    /**
     * @brief Reset the angle if it is above pi or below 0
     *
     * @param angle - the angle to reset in radian
     * @return float - the reseted angle in radian
     */
    float reset_angle(float angle);

    /**
     * @brief change the entity position based on the angle of the player view
     *
     * @param rpg - the rpg_t structure
     * @param nb - the casted ray offset from the player view (rpg->slope)
     * @param rc - the ray_cast_t structure
     */
    void change_entity_position(rpg_t *rpg, int nb, ray_cast_t *rc);

#endif /* !RAYCAST_H_ */
