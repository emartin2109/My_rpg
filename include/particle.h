/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-ethan.thierry
** File description:
** particle
*/

#ifndef PARTICLE_H_
    #define PARTICLE_H_

    #include "structures.h"
    #include "stdlib.h"
    #include <SFML/Graphics.h>


    /**
     * @brief this function updates the particle each frame and print them
     *
     * @param particle = head of the particle list
     * @param move = the absolute movement desired for the particle,
     * leave at 0, 0 if no movement is desired
     * @param w = render window for display
     */
    void update_particles (verlet_t **particle, sfVector2f move,
    sfRenderWindow *w);

    /**
     * @brief create a new particle list with the arguments specified in args
     *
     * @param args = the arguments of the function,
     * every modifiable parameter is in it
     * @return verlet_t** = the head of the particle list
     */
    verlet_t **create_particles (particles_args_t *args);

#endif /* !PARTICLE_H_ */
