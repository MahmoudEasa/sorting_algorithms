#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort - sorts an array of integers
 *	in ascending order using the Merge sort algorithm
 * @array: Array of integers
 * @size: The size
 */

void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t mid, i, j;
	(void)mid;
	(void)i;
	(void)j;

	if (size < 2)
		return;

	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		exit(1);

	copy_array(array, copy, size);
	split_merge(array, copy, 0, size);

	free(copy);
}

/**
 * copy_array - copy array to array
 * @array: first array
 * @copy: second array
 * @size: size of array
 */

void copy_array(int *array, int *copy, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		copy[i] = array[i];
}

/**
 * split_merge - sort array from copy to array
 * @array: first array
 * @copy: second array
 * @start: the start index
 * @end: the end index
 */

void split_merge(int *array, int *copy, size_t start, size_t end)
{
	size_t mid = 0;

	if ((end - start) <= 1)
		return;

	mid = (end + start) / 2;

	split_merge(array, copy, start, mid);
	split_merge(array, copy, mid, end);

	merge(array, copy, start, mid, end);
	for (mid = start; mid < end; mid++)
		copy[mid] = array[mid];
}

/**
 * merge - merge array from copy to array
 * @array: first array
 * @copy: second array
 * @start: the start index
 * @mid: the middle index
 * @end: the end index
 */

void merge(int *array, int *copy, size_t start, size_t mid, size_t end)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(copy + start, mid - start);
	printf("[right]: ");
	print_array(copy + mid, end - mid);
	i = start;
	j = mid;

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || copy[i] <= copy[j]))
		{
			array[k] = copy[i];
			i++;
		}
		else
		{
			array[k] = copy[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(array + start, end - start);
}

