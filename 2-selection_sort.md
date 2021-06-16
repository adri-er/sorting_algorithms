# Selection sort
## Description
Selection sort is an in-place comparison sort. It has O(n2) complexity, making it inefficient on large lists, and generally performs worse than the similar insertion sort. Selection sort is noted for its simplicity, and also has performance advantages over more complicated algorithms in certain situations.
The algorithm finds the minimum value, swaps it with the value in the first position, and repeats these steps for the remainder of the list. It does no more than n swaps, and thus is useful where swapping is very expensive. <sub><a  href="https://en.wikipedia.org/wiki/Selection_sort"  target="_blank">more</a></sub> 
## Time complexity
|Best Case|Average Case|Worst Case|
|:--:|:--:|:--:|
|O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(n<sup>2</sup>)|
## Selection sort function
```c
void selection_sort(int *array, size_t size)
```
* **Warning**
	This function makes changes to the array it receives
* **Description**
	Sorts an array using the selection sort algorithm
* **Parameters**
	`array` array of numbers to sort
	`size` size of the array to sort
* **Return**
	Always void
## Implementation
```c
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
```
