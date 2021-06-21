# Counting sort
## Description
An algorithm for sorting a collection of objects according to keys that are small integers; that is, it is an integer sorting algorithm. It operates by counting the number of objects that have each distinct key value, and using arithmetic on those counts to determine the positions of each key value in the output sequence. Its running time is linear in the number of items and the difference between the maximum and minimum key values, so it is only suitable for direct use in situations where the variation in keys is not significantly greater than the number of items. However, it is often used as a subroutine in another sorting algorithm, radix sort, that can handle larger keys more efficiently. <sub><a  href="https://en.wikipedia.org/wiki/Counting_sort"  target="_blank">more</a></sub> 
## Time complexity
|Best Case|Average Case|Worst Case|
|:--:|:--:|:--:|
|O(n + k)|O(n + k)|O(n + k)|
Where _k_ is the maximum value in the array.
## Counting sort function
```c
void counting_sort(int *array, size_t size)
```
* **Warning**
	This function makes changes to an array it receives
* **Description**
	Sorts an array using the counting sort algorithm
* **Parameters**
	`array` pointer to an array of numbers
	`size` size of the array to sort
* **Return**
	Always void
## Implementation
```c
void counting_sort(int *array, size_t size)
{
	int *count = NULL, copy_array[500];
	unsigned int i, max = 0;

	// Valid parameters verification.
	if (array == NULL || size < 2)
		return;
	
	// Get the size of the counting array.
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
	
	// Initialize counting array in zero.
	for (i = 0; i < max; i++)
		count[i] = 0;

	// Count the amount of each numbers in array to sort.
	for (i = 0; i < size; i++)
		count[array[i]] = count[array[i]] + 1;

	// Add positions to give new index of each position.
	for (i = 0; i < max; i++)
	{
		if (i != 0)
		count[i] = count[i] + count[i - 1];
	}
	print_array((const int *)count, max);

	// Re-arrange the array to get sorted.
	for (i = 0; i < size; i++)
	{
		array[count[copy_array[i]] - 1] = copy_array[i];
		count[copy_array[i]]--;
	}
	free(count);
}
```
