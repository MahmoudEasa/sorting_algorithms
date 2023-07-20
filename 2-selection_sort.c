#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 *	in ascending order using the Selection sort algorithm
 * @array: Array of integers
 * @size: The size
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, temp;
	int swap = 0;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swap = 0;
		for (j = i; j < size; j++)
			if (array[i] > array[j])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				swap = 1;
			}
		if (swap)
			print_array(array, size);
	}
}

