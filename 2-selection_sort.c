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
	size_t i, j;
	int swap = 0, less_index = -1, temp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swap = 0;
		less_index = -1;
		for (j = i + 1 ; j < size; j++)
			if (array[i] > array[j])
			{
				if (less_index == -1 || array[j] < temp)
				{
					temp = array[j];
					less_index = j;
				}
				swap = 1;
			}
		if (swap)
		{
			temp = array[less_index];
			array[less_index] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}

