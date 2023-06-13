/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** init_other_rpg_vars
*/

#include "events.h"
#include "menu.h"
#include "lib.h"
#include "my_rpg.h"
#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

int manage_event(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window, rpg->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && pause_menu(rpg) == 1)
            return pause_menu(rpg);
        analyse_events(rpg->window, rpg->event);
    }
    return 2;
}

rpg_t *init_sounds(rpg_t *rpg)
{
    rpg->music = sfMusic_createFromFile("assets/Theme.ogg");
    rpg->metal_pipe_sound =
    sfMusic_createFromFile("assets/Metal_pipe_sound.ogg");
    return (rpg);
}

static map_t *fetch_map(rpg_t *rpg, char *map_name)
{
    char *buffer = get_buffer(map_name);
    map_t *map = malloc(sizeof(map_t));
    if (buffer == NULL || map == NULL)
        return NULL;
    map->fcontent = my_str_to_word_array(get_buffer(map_name), '\n');
    map->array = &map->fcontent[1];
    char **meta = my_str_to_word_array(map->fcontent[0], ';');
    map->meta = str_array_to_int(meta);
    map->y = count_words(get_buffer(map_name), '\n') - 1;
    free(buffer);
    for (int i = 0; i < 4; i++)
        free(meta[i]);
    free(meta);
    return map;
}

rpg_t *init_maps(rpg_t *rpg)
{
    rpg->map_sprite = sfSprite_create();
    rpg->map_texture = sfRenderTexture_create(rpg->size_x,
    rpg->size_y, sfFalse);
    rpg->maps = malloc(sizeof(map_t *) * (MAPS_COUNT + 1));
    rpg->maps[0] = fetch_map(rpg, "assets/maps/map1.txt");
    rpg->maps[1] = fetch_map(rpg, "assets/maps/map2.txt");
    rpg->maps[2] = fetch_map(rpg, "assets/maps/map3.txt");
    rpg->maps[3] = fetch_map(rpg, "assets/maps/map4.txt");
    rpg->maps[4] = fetch_map(rpg, "assets/maps/map5.txt");
    rpg->maps[5] = fetch_map(rpg, "assets/maps/map6.txt");
    rpg->maps[MAPS_COUNT] = NULL;
    return rpg;
}

rpg_t *init_key_binds(rpg_t *rpg)
{
    rpg->key_binds->forward = sfKeyZ;
    rpg->key_binds->backward = sfKeyS;
    rpg->key_binds->left = sfKeyQ;
    rpg->key_binds->right = sfKeyD;
    rpg->key_binds->run = sfKeyLShift;
    return rpg;
}
