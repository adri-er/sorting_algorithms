#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array using the counting sort algorithm.
 * @array: array to sort.
 * @size: size of the array to sort.
 *
 * Return: Always none.
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL, copy_array[500];
	unsigned int i, max = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)max)
		max = array[i];
		copy_array[i] = array[i];
	}
	max++;
	count = malloc(sizeof(int) * max);
	if (!count)
		return;
	for (i = 0; i < max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] = count[array[i]] + 1;
	for (i = 0; i < max; i++)
	{
		if (i != 0)
		count[i] = count[i] + count[i - 1];
	}
	print_array((const int *)count, max);
	for (i = 0; i < size; i++)
	{
		array[count[copy_array[i]] - 1] = copy_array[i];
		count[copy_array[i]]--;
	}
	free(count);
}
