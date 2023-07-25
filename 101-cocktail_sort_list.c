#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 *	in ascending order using the Cocktail shaker sort algorithm
 * @list: The head of the linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *last;
	int swapped = 0;

	if (list && *list)
	{
		if (!(*list)->next)
			return;

		do {
			swapped = 0;
			last = sort_next(list, &swapped);

			if (!swapped)
				break;

			swapped = 0;
			sort_prev(last, list, &swapped);
		} while (swapped);
	}
}

/**
 * swap - swap two nodes
 * @node1: first node
 * @node2: second node
 * @list: the head of the list
 */

void swap(listint_t *node1, listint_t *node2, listint_t **list)
{
	if (!node1->prev)
		*list = node2;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node2->prev)
		node2->prev->next = node2;

	if (node1->next)
		node1->next->prev = node1;
}

/**
 * sort_next - sort list from start to end
 * @list: The head of the list
 * @swapped: integer
 *
 * Return: last node
 */

listint_t *sort_next(listint_t **list, int *swapped)
{
	listint_t *current, *next;

	current = *list;
	next = current->next;

	while (next)
	{
		if (current->n > next->n)
		{
			swap(current, next, list);
			*swapped = 1;
			print_list(*list);

		}
		current = next;
		next = current->next;
	}

	return (current);
}

/**
 * sort_prev - sort list from end to start
 * @last: last node
 * @list: The head of the list
 * @swapped: integer
 */

void sort_prev(listint_t *last, listint_t **list, int *swapped)
{
	listint_t *prev;

	prev = last->prev;
	while (prev)
	{
		if (last->n < prev->n)
		{
			swap(prev, last, list);
			*swapped = 1;
			print_list(*list);
		}
		last = prev;
		prev = last->prev;
	}
}
