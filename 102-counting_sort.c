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
	int k, j, *count, temp, swap = 0;
	size_t i;

	if (!array || size < 2)
		return;

	k = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > k)
			k = array[i];

	count = (int *)malloc(sizeof(int) * (k + 1));
	if (!count)
		exit(1);

	for (j = 0; j <= k; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (j = 0; j <= k; j++)
		count[j + 1] += count[j];

	print_array(count, k + 1);
	while (!swap)
	{
		swap = 1;
		for (i = 0; i < size; i++)
		{
			j = count[array[i]] - 1;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				swap = 0;
			}
		}
	}
	free(count);
}

