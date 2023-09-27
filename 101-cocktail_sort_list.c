#include "sort.h"
#include <stdio.h>

/**
 * swap_backward - Swaps nodes of a doubly linked list in backward traversal
 * @list: Pointer to the head of the list
 * @current: Current node to compare and swap with its previous node
 * @swapped: Pointer to a flag indicating if a swap was made
 */
void swap_backward(listint_t **list, listint_t *current, int *swapped)
{
	while (current->prev != NULL)
	{
		if (current->n < current->prev->n)
		{
			/* Swap current and current->prev */
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			*swapped = 1;
			print_list(*list);
		}
		else
			current = current->prev;
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*list = current->next;
				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;
				current->prev->next = current;
				if (current->next != NULL)
					current->next->prev = current;
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		swap_backward(list, current, &swapped);
	}
}
