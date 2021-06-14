#include "sort.h"


/**
 * bubble_sort - sorts an array using the bubble sort.
 * algorithm in ascending order.
 * @array: array of numbers to sort.
 * @size: size of the array to sort.
 *
 * Return: None.
 */
void bubble_sort(int *array, size_t size)
{
	int i, j;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		for (j = 0; j < (int)size; j++)
		{
			if (j + 1 != (int)size && array[j] > array[j + 1])
			{
				SWAP(array[j], array[j + 1], int);
				print_array((const int *)array, size);
			}
		}
	}
}
