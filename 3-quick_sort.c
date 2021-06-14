#include "sort.h"
#include <unistd.h>

/**
 * quick_sort_print - the implementation of the algorithm quick sort.
 *
 * @array: array of the number list to sort with quick sort algorithm.
 * @size: size of the array to sort.
 * @array_p: array of the number list to sort with quick sort algorithm.
 * @size_p: size of the array to sort.
 *
 * Return: Always void.
 */
void quick_sort_print(int *array_p, size_t size_p, int *array, size_t size)
{
	int pivot = size - 1, change = 0, moving = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (array[moving] < array[pivot])
	{
		moving++;
	}
	change = moving;
	for (; moving <= pivot; moving++)
	{
		if (array[moving] <=  array[pivot])
		{
			if (array[change] !=  array[pivot])
			{
				SWAP(array[moving], array[change], int);
				print_array(array_p, size_p);
			}
			change++;
		}
	}
	pivot = change - 1;
	quick_sort_print(array_p, size_p, array, pivot);
	quick_sort_print(array_p, size_p, array + pivot + 1, size - pivot - 1);
}

/**
 * quick_sort - the implementation of the algorithm quick sort.
 *
 * @array: array of the number list to sort with quick sort algorithm.
 * @size: size of the array to sort.
 *
 * Return: Always void.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_print(array, size, array, size);
}
