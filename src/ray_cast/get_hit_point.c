/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** get_hit_point
*/

#include "lib.h"
#include "my_rpg.h"
#include "structures.h"
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include <raycast.h>

int is_colliding_x(rpg_t *rpg, sfVector2f pointx)
{
    return (((rpg->slope > M_PI / 2.0 && rpg->slope < 3 * M_PI / 2.0) &&
    (pointx.y < 0 || pointx.y > rpg->maps[rpg->level]->y ||
    rpg->maps[rpg->level]->array[(int) ceil(pointx.y) - 1]
    [(int) pointx.x - 1] != ' '))
    || ((rpg->slope < M_PI / 2.0 || rpg->slope > 3 * M_PI / 2.0) &&
    (pointx.y < 0 || pointx.y > rpg->maps[rpg->level]->y ||
    rpg->maps[rpg->level]->array[(int) floor(pointx.y)]
    [(int) pointx.x] != ' ')));
}

int is_colliding_y(rpg_t *rpg, sfVector2f pointy)
{
    return (((rpg->slope < 0 || rpg->slope > M_PI) &&
    (pointy.x < 0 || pointy.x > my_strlen(rpg->maps[rpg->level]->array[(int)
    floor(pointy.y)]) || rpg->maps[rpg->level]->array[(int) pointy.y - 1]
    [(int) floor(pointy.x)] != ' '))
    || ((rpg->slope > 0 && rpg->slope < M_PI) &&
    (pointy.x < 0 || pointy.x > my_strlen(rpg->maps[rpg->level]->array[(int)
    ceil(pointy.y) - 1]) || rpg->maps[rpg->level]->array[(int) pointy.y]
    [(int) ceil(pointy.x) - 1] != ' ')));
}

sfVector2f get_hitpoint_x(rpg_t * rpg)
{
    sfVector2f pointx;
    for (float i = 0.0; 1; i += 1.0) {
        if (rpg->slope > M_PI / 2.0 && rpg->slope < 3 * M_PI / 2.0)
            pointx = (sfVector2f) {floor(rpg->player_pos.x / 50.0) - i
            , rpg->player_pos.y / 50.0 + tan(rpg->slope) *
            (floor(rpg->player_pos.x / 50.0) - i - (rpg->player_pos.x / 50.0))};
        else
            pointx = (sfVector2f) {ceil(rpg->player_pos.x / 50.0) + i
            , rpg->player_pos.y / 50.0 + tan(rpg->slope) *
            (ceil(rpg->player_pos.x / 50.0) + i - (rpg->player_pos.x / 50.0))};
        if (is_colliding_x(rpg, pointx))
            break;
    }
    return (pointx);
}

sfVector2f get_hitpoint_y(rpg_t * rpg)
{
    sfVector2f pointy;
    for (float i = 0.0; 1; i += 1.0) {
        if (rpg->slope < 0 || rpg->slope > M_PI)
            pointy = (sfVector2f) {rpg->player_pos.x / 50.0 +
            cot(rpg->slope) * (floor(rpg->player_pos.y / 50.0) - i -
            (rpg->player_pos.y / 50.0)), floor(rpg->player_pos.y / 50.0) - i};
        else
            pointy = (sfVector2f) {rpg->player_pos.x / 50.0 +
            cot(rpg->slope) * (ceil(rpg->player_pos.y / 50.0) + i -
            (rpg->player_pos.y / 50.0)), ceil(rpg->player_pos.y / 50.0) + i};
        if (is_colliding_y(rpg, pointy))
            break;
    }
    return (pointy);
}

ray_cast_t *get_best_hitpoint_and_distance(rpg_t *rpg,
sfVector2f pointx, sfVector2f pointy)
{
    sfVector2f point;
    float distance = 0.0;
    float distancex = sqrt(pow((rpg->player_pos.x - pointx.x), 2) +
    pow((rpg->player_pos.y - pointx.y), 2));
    float distancey = sqrt(pow((rpg->player_pos.x - pointy.x), 2) +
    pow((rpg->player_pos.y - pointy.y), 2));
    if (distancey <= distancex) {
        distance = distancey;
        point = pointy;
        if (rpg->slope < 0 || rpg->slope > M_PI) point.y -= 0.0001;
    } else {
        distance = distancex;
        point = pointx;
        if (rpg->slope > M_PI / 2.0 && rpg->slope < 3 * M_PI / 2.0)
            point.x -= 0.0001;
    }
    ray_cast_t *rc = malloc(sizeof(ray_cast_t));
    rc->distance = distance * cos(rpg->slope - rpg->clone_slope);
    rc->hit_point = point;
    return (rc);
}
