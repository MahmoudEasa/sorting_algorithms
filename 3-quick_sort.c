#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

/**
 * quick_sort - sorts an array of integers
 *	in ascending order using the Quick sort algorithm
 * @array: Array of integers
 * @size: The size
 */

void quick_sort(int *array, size_t size)
{
	size_t first = 0, last = size - 1;

	if (size < 2)
		return;

	sort_help(array, first, last, size);
}

/**
 * swap_in_arr - swap to elements in array
 * @array: The array
 * @i: first element to swap
 * @j: second element to swap
 */

void swap_in_arr(int *array, size_t i, size_t j)
{
	size_t temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}

/**
 * sort_help - sort the array
 * @array: The array
 * @first: first index
 * @last: last index
 * @size: size of array
 */

void sort_help(int *array, size_t first, size_t last, size_t size)
{
	size_t p;
	int hi = (int)last;

	if (first >= last || hi < 0)
		return;

	p = partition(array, first, last, size);

	sort_help(array, first, p - 1, size);
	sort_help(array, p + 1, last, size);
}

/**
 * partition - Divides array into two partitions
 * @array: The array
 * @first: first index
 * @last: last index
 * @size: size of array
 *
 * Return: the index of divided
 */

size_t partition(int *array, size_t first, size_t last, size_t size)
{
	int pivot = array[last];
	size_t i, j;

	i = first - 1;

	for (j = first; j < last; j++)
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
				swap_in_arr(array, i, j);
		}
	i++;
	swap_in_arr(array, i, last);
	print_array(array, size);
	return (i);
}

