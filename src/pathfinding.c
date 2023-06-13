/*
** EPITECH PROJECT, 2023
** merge_save
** File description:
** pathfinding
*/

#include "structures.h"
#include "stdio.h"
#include "lib.h"
#include "my_rpg.h"
#include <stdlib.h>

static char *end_resolve_map (queu_t * queu)
{
    queu_t *temp1;
    queu_t *temp2;
    char *result;

    if (queu == NULL)
        return NULL;
    temp1 = queu->next;
    temp2 = temp1;
    result = queu->instruction;
    while (temp1) {
        temp2 = temp1->next;
        if (temp1->instruction && my_strlen(temp1->instruction) > 1)
            free(temp1->instruction);
        free(temp1);
        temp1 = temp2;
    }
    free(queu);
    return result;
}

char *find_path (char **map, sfVector2i *start, sfVector2i *end)
{
    if (start->x == end->x && start->y == end->y)
        return NULL;
    queu_t *queu = add_to_queu(start->x, start->y, NULL, NULL);
    while (queu) {
        if (queu->y == end->y && queu->x == end->x)
            return end_resolve_map(queu);
        if (map[queu->y][queu->x] != ' ') {
            queu = next_in_queu(queu);
            continue;
        }
        map[queu->y][queu->x] = '#';
        queu = get_next_visit(queu, map);
    }
    return NULL;
}
