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
#define IF_PREV_BIGGER(NODE) ((NODE)->prev && ((NODE)->prev->n > (NODE)->n))
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
	int i;

	while (gap < ((int)size - 1) / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 1)
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
	}
	if (gap == 1)
	{
		insertion_array(array, size);
		print_array((const int *)array, size);
	}
}
