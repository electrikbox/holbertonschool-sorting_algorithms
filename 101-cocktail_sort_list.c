#include "sort.h"

/**
 * swapNodes - swaps two nodes in a doubly linked list
 * @list: double pointer to the list
 * @nodeA: pointer to one node
 * @nodeB: pointer to the other node
*/
void swapNodes(listint_t **list, listint_t **nodeA, listint_t **nodeB)
{
	listint_t *tmp_a = *nodeA;
	listint_t *tmp_b = *nodeB;

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

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * @list: double pointer to the list
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL, *end = NULL, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = *list;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swapNodes(list, &current, &(current->next));
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
				swapNodes(list, &(current->prev), &current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		start = current;
	} while (swapped);
}