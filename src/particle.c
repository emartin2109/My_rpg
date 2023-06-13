/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-ethan.thierry
** File description:
** particle
*/

#include "particle.h"

static const int gravity_x = 0;
static const int gravity_y = 6000;

static sfCircleShape *create_circle (sfVector2f position, float radius)
{
    sfCircleShape *result = sfCircleShape_create();
    sfCircleShape_setOutlineThickness(result, 1);
    sfCircleShape_setOutlineColor(result, sfTransparent);
    sfCircleShape_setRadius(result, radius);
    sfCircleShape_setOrigin(result, (sfVector2f) {radius, radius});
    sfCircleShape_move(result, position);
    return result;
}

static void accelerate (verlet_t *particle, sfVector2f acc)
{
    particle->acceleration.x += acc.x;
    particle->acceleration.y += acc.y;
}

static void update_particle (verlet_t *particle, float dt)
{
    sfVector2f velocity;
    velocity.x = particle->curr_pos.x - particle->old_pos.x;
    velocity.y = particle->curr_pos.y - particle->old_pos.y;
    particle->old_pos = particle->curr_pos;
    particle->curr_pos.x = particle->curr_pos.x + velocity.x +
    particle->acceleration.x * dt * dt;
    particle->curr_pos.y = particle->curr_pos.y + velocity.y +
    particle->acceleration.y * dt * dt;
    particle->acceleration = (sfVector2f) {0, 0};
    sfCircleShape_setPosition(particle->circle, particle->curr_pos);
}

void update_particles (verlet_t **particle, sfVector2f move, sfRenderWindow *w)
{
    int i = 0;
    if (particle == NULL || w == NULL)
        return;
    while (particle[i]) {
        if (particle[i]->need_to_be_killed) {
            i++;
            continue;
        }
        particle[i]->curr_pos.x += move.x;
        particle[i]->curr_pos.y += move.y;
        particle[i]->old_pos.x += move.x;
        particle[i]->old_pos.y += move.y;
        accelerate(particle[i], (sfVector2f) {gravity_x, gravity_y});
        update_particle(particle[i], 0.01);
        sfRenderWindow_drawCircleShape(w, particle[i]->circle, NULL);
        if (particle[i]->curr_pos.x > 1930 || particle[i]->curr_pos.y > 1090
        || particle[i]->curr_pos.x < 0 || particle[i]->curr_pos.y < 0)
            particle[i]->need_to_be_killed = 1;
        i++;
    }
}

verlet_t **create_particles (particles_args_t *args)
{
    int i = -1;
    verlet_t **particles = malloc(sizeof(verlet_t *) * args->nbr + 1);
    particles[args->nbr] = NULL;
    while (i < args->nbr) {
        particles[i] = malloc(sizeof(verlet_t) * 1);
        particles[i]->circle = create_circle(args->position, args->radius);
        sfCircleShape_setTexture(particles[i]->circle, args->texture, 0);
        particles[i]->curr_pos = args->position;
        particles[i]->old_pos = args->position;
        particles[i]->acceleration.x = rand() % args->medium_speed_x
        - rand() % args->medium_speed_x;
        particles[i]->acceleration.y = rand() % args->medium_speed_y
        - rand() % args->medium_speed_y;
        particles[i]->need_to_be_killed = 0;
        i++;
    }
    return particles;
}
