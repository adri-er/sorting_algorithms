#include "sort.h"

/**
 * bubble_sort - sorts an array using the bubble sort
 * algorithm in ascending order.
 * @array: array of numbers to sort.
 * @size: size of the array to sort.
 *
 * Return: None.
 */
void bubble_sort(int *array, size_t size)
{
	int i = (int)size - 1;
	int j = i - 1;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (; i >= 0; i--)
	{
		for (j = (int)size - 2; j >= ((int)size - i - 1); j--)
		{
			if (array[j] > array[j + 1])
			{
				SWAP(array[j], array[j + 1], int);
				print_array((const int *)array, size);
			}
		}
	}
}
