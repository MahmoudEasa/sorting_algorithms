#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *	in ascending order using the Insertion sort algorithm
 * @list: The head of the linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (list && *list)
	{
		if (!(*list)->next)
			print_list(*list);
		else
		{
			current = *list;
			next = current->next;

			while (next)
			{
				if (current->n > next->n)
				{
					swap(current, next, list);
					print_list(*list);

					current = current->prev;
					prev = current->prev;
					while (prev && current && current->n < prev->n)
					{
						swap(prev, current, list);
						print_list(*list);

						prev = current->prev;
					}
				}
				current = next;
				next = current->next;
			}
		}
	}
}

/**
 * swap - swap tow nodes
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

