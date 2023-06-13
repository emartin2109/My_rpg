/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** display_framerate
*/

#include "lib.h"
#include "my_rpg.h"
#include "structures.h"

void display_framerate(rpg_t *rpg)
{
    static int first = 1;
    static sfClock * clock;
    static int fps = 0;

    if ( first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime ( clock ) ;
    if (sfTime_asSeconds(elapsed) >= 1) {
        sfRenderWindow_setTitle(rpg->window,
        my_strcat(my_strcat("RPG ", int_to_string(fps)), " FPS"));
        fps = 0;
        sfClock_restart (clock);
    } else
        fps ++;
}
