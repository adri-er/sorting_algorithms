#include "sort.h"

/**
 * merge_sort_recursive - sorting an array using the merge sort algorithm.
 *
 * @array: array of numbers to sort with merge sort algorithm.
 * @array_storage: array to save temporaly the numbers.
 * @size: size of the array to sort.
 *
 * Return: aways void
 *
 */
void merge_sort_recursive(int *array_storage, int *array, size_t size)
{
	int min_l = 0, min_r = 0, i = 0, middle = size / 2, remainder = size % 2;

	if (size < 2)
		return;

	merge_sort_recursive(array_storage, array, middle);
	merge_sort_recursive(
		array_storage + middle,
		array + middle,
		middle + remainder
	);

	printf("Merging...\n");
	min_r = middle, min_l = 0;

	for (i = 0; i < (int)size; i++)
		array_storage[i] = array[i];

	printf("[left]: "), print_array(array, middle);
	printf("[right]: "), print_array(array + middle, middle + remainder);
	for (i = 0; i < (int)size; i++)
	{
		if (min_l == middle)
		{
			break;
		}
		else if (min_r == (int)size)
		{
			COPY_FROM_UNTIL(array_storage, min_l, array, i, (int)size);
		}
		else if (array_storage[min_l] < array_storage[min_r])
		{
			array[i] = array_storage[min_l], min_l += 1;
		}
		else
		{
			array[i] = array_storage[min_r], min_r += 1;
		}
	}
	printf("[Done]: "), print_array(array, size);
}

/**
 * merge_sort - wrapper that validate array, alloc and free array storage
 *              and call merge sort algorithm.
 *
 * @array: array of numbers to sort with merge sort algorithm.
 * @size: size of the array to sort.
 *
 * Return: aways void
 *
 */
void merge_sort(int *array, size_t size)
{
	int *array_storage = NULL;

	if (array == NULL || size < 1)
		return;

	array_storage = malloc(sizeof(int) * size);
	merge_sort_recursive(array_storage, array, size);
	free(array_storage);
}
