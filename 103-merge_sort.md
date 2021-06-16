# Merge sort
## Description
In computer science, merge sort (also commonly spelled as mergesort) is an efficient, general-purpose, and comparison-based sorting algorithm. Most implementations produce a stable sort, which means that the order of equal elements is the same in the input and output. Merge sort is a divide and conquer algorithm that was invented by John von Neumann in 1945. A detailed description and analysis of bottom-up merge sort appeared in a report by Goldstine and von Neumann as early as 1948. <sub><a  href="https://en.wikipedia.org/wiki/Merge_sort"  target="_blank">more</a></sub> 
## Time complexity
|Best Case|Average Case|Worst Case|
|:--:|:--:|:--:|
|O(n log n)|O(n log n)|O(n log n)|
## Merge sort function
```c
void merge_sort(int *array, size_t size)
```
* **Warning**
	This function makes changes to the array it receives
* **Description**
	  wrapper that validate array, alloc and free array storage and call merge sort algorithm.
* **Parameters**
	`array` array of numbers to sort with merge sort algorithm.
 	`size` size of the array to sort.
* **Return**
	Always void
## Implementation
```c
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

void merge_sort(int *array, size_t size)
{
	int *array_storage = NULL;

	if (array == NULL || size < 1)
		return;

	array_storage = malloc(sizeof(int) * size);
	merge_sort_recursive(array_storage, array, size);
	free(array_storage);
}

```
