#include "sort.h"

void swap_nodes(listint_t **list, listint_t **a, listint_t **b)
{
    listint_t *tmp_a = *a;
    listint_t *tmp_b = *b;

    if (tmp_a == tmp_b)
        return;

    if (tmp_a->prev)
        tmp_a->prev->next = tmp_b;
    else
        *list = tmp_b;

    if (tmp_b->next)
        tmp_b->next->prev = tmp_a;

    tmp_a->next = tmp_b->next;
    tmp_b->prev = tmp_a->prev;
    tmp_a->prev = tmp_b;
    tmp_b->next = tmp_a;
}

void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *start = NULL;
    listint_t *end = NULL;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        current = *list;

        while (current->next != end)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, &current, &(current->next));
                swapped = 1;
                print_list(*list);
            }
            else
                current = current->next;
        }

        if (!swapped)
            break;

        swapped = 0;
        end = current;

        while (current->prev != start)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, &(current->prev), &current);
                swapped = 1;
                print_list(*list);
            }
            else
                current = current->prev;
        }
        start = current;
    }
    while (swapped);
}