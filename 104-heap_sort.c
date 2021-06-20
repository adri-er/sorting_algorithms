#include "sort.h"
/**
 * sift_down - sort from top sub tree to down
 *
 * @array: array to sort
 * @index: head of the current tree
 * @size: size of the array to sort
 * @size_print: size of the array to print
 *
 */
void sift_down(int *array, size_t index, size_t size, size_t size_print)
{
	size_t index_maximum = 0;

	if (RIGHT_INDEX(index) < size
		&& array[RIGHT_INDEX(index)] > array[LEFT_INDEX(index)])
	{
		index_maximum = RIGHT_INDEX(index);
	}
	else if (LEFT_INDEX(index) < size)
	{
		index_maximum = LEFT_INDEX(index);
	}
	else
	{
		index_maximum = index;
	}

	if (array[index] >= array[index_maximum])
	{
		index_maximum = index;
	}

	if (index_maximum != index)
	{
		SWAP(array[index_maximum], array[index], int);
		print_array(array, size_print);
		sift_down(array, index_maximum, size, size_print);
	}
}

/**
 * heap_sort - sort from top to down
 *
 * @array: array to sort
 * @size: size of the array to sort
 *
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
	{
		return;
	}

	BUILD_HEAD_STUCTURE(array, size);

	for (i = (int)size - 1; i > 0; i--)
	{
		SWAP(array[0], array[i], int);
		print_array(array, size);
		sift_down(array, 0, i, size);
	}
}

