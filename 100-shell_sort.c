#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 *	using the Shell sort algorithm, using the Knuth sequence
 * @array: Array of integers
 * @size: The size
 */

void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, h = 1;

	if (!array || size < 2)
		return;

	while ((h < size / 3) && (size > 4))
		h = (h * 3) + 1;

	while (h > 0)
	{
		for (i = 0; i < size; i++)
		{
			j = h + i;
			while (j < size)
			{
				if (array[i] > array[j])
				{
					temp = array[j];
					array[j] = array[i];
					array[i] = temp;
				}
				j += h;
			}
		}
		print_array(array, size);

		h = h / 3;
	}
}

