#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers
 *	in ascending order using the Counting sort algorithm
 * @array: The array of integers
 * @size: The size
 */

void counting_sort(int *array, size_t size)
{
	int k, j, *count, c = 0, temp;
	size_t i;

	if (size < 2)
		return;

	k = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > k)
			k = array[i];

	count = (int *)malloc(sizeof(int) * k + 1);
	if (!count)
		exit(1);

	for (i = 0; (int)i <= k; i++)
		count[i] = 0;

	for (j = 0; j <= k; j++)
		for (i = 0; i < size; i++)
		{
			if (j == array[i])
				c++;
			count[j] = c;
		}

	print_array(count, k + 1);

	for (i = 0; i < size; i++)
		if ((int)i != count[array[i] - 1])
		{
			temp = array[count[array[i] - 1]];
			array[count[array[i] - 1]] = array[i];
			array[i] = temp;
		}
}

