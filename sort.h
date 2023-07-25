#ifndef SORT_H
#define SORT_H

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void swap(listint_t *node1, listint_t *node2, listint_t **list);
void sort_help(int *array, size_t first, size_t last, size_t size);
void swap_in_arr(int *array, size_t i, size_t j);
size_t partition(int *array, size_t first, size_t last, size_t size);
listint_t *sort_next(listint_t **list, int *swapped);
void sort_prev(listint_t *last, listint_t **list, int *swapped);
void copy_array(int *array, int *copy, size_t size);
void split_merge(int *array, int *copy, size_t start, size_t end);
void merge(int *array, int *copy, size_t start, size_t mid, size_t end);

#endif /* SORT_H */

