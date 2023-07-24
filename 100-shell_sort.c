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
	int temp, *knuth, sorted = 0;
	size_t i, j, k;
	(void)knuth;

	if (size <= 2)
		return;
	/*knuth = (int *)malloc(sizeof(int) * (size + 1));*/
	/*if (!knuth)*/
		/*exit(1);*/

	/*knuth[0] = 1;*/
	/*for (i = 1; i <= size; i++)*/
		/*knuth[i] = (knuth[i - 1] * 3) + 1;*/

	k = size / 2;
	while (!sorted)
	{
		sorted = 1;
		j = k;
		for (i = 0; i < size && k > 0; i++)
		{
			j = k + i;
			while (j < size)
			{
				if (array[i] > array[j])
				{
					temp = array[j];
					array[j] = array[i];
					array[i] = temp;
					sorted = 0;
					print_array(array, size);
				}
				j += k;
			}
		}
		if (k % 2 != 0)
			k--;
		k = k / 2;
	}
}

