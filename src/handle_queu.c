/*
** EPITECH PROJECT, 2023
** merge_save
** File description:
** handle_queu
*/

#include "structures.h"
#include "stdio.h"
#include "my_rpg.h"
#include "stdlib.h"
#include "string.h"

static queu_t *get_new_queu (int x, int y, queu_t *head, char *instruction)
{
    queu_t *current = head;
    queu_t *temp = NULL;
    while (current->next && (current->next->x + 1)
    * (current->next->y + 1) >= (x + 1) * (y + 1))
        current = current->next;
    if (current->next == NULL) {
        current->next = malloc(sizeof(queu_t));
        current->next->x = x;
        current->next->y = y;
        current->next->instruction = instruction;
        current->next->next = NULL;
        return head;
    }
    temp = malloc(sizeof(queu_t));
    temp->x = x;
    temp->y = y;
    temp->instruction = instruction;
    temp->next = current->next;
    current->next = temp;
    return head;
}

queu_t *add_to_queu (const int x, const int y, queu_t *head, char *instruction)
{
    if (head == NULL) {
        head = malloc(sizeof(queu_t));
        head->next = NULL;
        head->x = x;
        head->y = y;
        head->instruction = NULL;
        return head;
    }
    return get_new_queu(x, y, head, instruction);
}

queu_t *next_in_queu(queu_t *queu)
{
    queu_t * new_queu = queu->next;
    if (queu == NULL)
        return NULL;
    if (queu->instruction && strlen(queu->instruction) > 1)
        free(queu->instruction);
    free(queu);
    return new_queu;
}

queu_t * get_next_visit(queu_t *queu, char **maze)
{
    int x = queu->x;
    int y = queu->y;
    queu_t *head = queu;
    if (queu == NULL)
        return NULL;
    if (y < 0 || x < 0)
        return queu;
    if (x > 0 && maze[y][x - 1] == ' ')
        queu = add_to_queu(x - 1, y, queu,
        my_strcat_no_free(head->instruction, "l"));
    if (maze[y][x + 1] && (maze[y][x + 1] == ' '))
        queu = add_to_queu(x + 1, y, queu,
        my_strcat_no_free(head->instruction, "r"));
    if (y > 0 && maze[y - 1][x] == ' ')
        queu = add_to_queu(x, y - 1, queu,
        my_strcat_no_free(head->instruction, "u"));
    if (maze[y] && (maze[y + 1][x] == ' '))
        queu = add_to_queu(x, y + 1, queu,
        my_strcat_no_free(head->instruction, "d"));
    return queu;
}
