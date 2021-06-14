#include "sort.h"
#include <stdio.h>

/**
 * insertion_array - insertion algorithm applied to an array.
 *
 * @array: array to sort with the algorithm.
 * @size: size of the array to sort.
 *
 * Return: Always void.
 */
void insertion_array(int *array, size_t size)
{
	int i, j, k;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		k = i;
		for (j = k - 1; j >= 0 && array[j] >= array[k];)
		{
			SWAP(array[j], array[k], int);
			j--;
			k--;
		}
	}
}

/**
 * insertion_array - insertion algorithm applied to an array.
 *
 * @array: array to sort with the algorithm.
 * @size: size of the array to sort.
 *
 * Return: Always void.
 */
void insertion_array_gap(int *array, size_t size, int gap)
{
	int i;

	if (gap > 1)
	{
		i = size - 1;
		while (i - gap >= 0)
		{
			if (array[i] < array[i - gap])
			{
				SWAP(array[i], array[i - gap], int);
			}
			i--;
		}
		print_array((const int *)array, size);
		gap = (gap - 1) / 3;
		insertion_array_gap(array, size, gap);
	}
	else if (gap == 1)
	{
		insertion_array(array, size);
		print_array((const int *)array, size);
	}
}

/**
 * shell_sort - sort an array using shell algorithm.
 *
 * @array: array of integers to sort.
 * @size: size of the array to sort.
 *
 * Return: Always void.
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1;

	while (gap < ((int)size - 1) / 3)
	{
		gap = gap * 3 + 1;
	}
	insertion_array_gap(array, size, gap);
}
