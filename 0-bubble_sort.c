#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 *	in ascending order using the Bubble sort algorithm
 * @array: Array of integers
 * @size: The size
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int sorted = 0, temp;

	if (array)
	{
		if (size < 2)
			return;
		else
		{
			while (!sorted)
			{
				sorted = 1;
				for (i = 0; i < size - 1; i++)
				{
					if (array[i] > array[i + 1])
					{
						temp = array[i];
						array[i] = array[i + 1];
						array[i + 1] = temp;
						sorted = 0;
						print_array(array, size);
					}
				}
			}
		}
	}
}

