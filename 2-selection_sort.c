#include "sort.h"

/**
 * selection_sort - Sorts an array with selection algorithm.
 *
 * @array: array to sort.
 * @size: size of the array to sort.
 *
 * Return: Always void.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int position_small = 0;
	size_t i = 0, j = 0;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (; i < size; i++)
	{
		position_small = size - 1;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[position_small])
			{
				position_small = j;
			}
		}
		if (array[i] != array[position_small])
		{
			SWAP(array[i], array[position_small], int);
			print_array((const int *)array, size);
		}
	}
}
