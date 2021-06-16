# Bubble sort
## Description
Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list to be sorted, compares each pair of adjacent items and swaps them if they are in the wrong order. The pass through the list is repeated until no swaps are needed, which indicates that the list is sorted. The algorithm, which is a comparison sort, is named for the way smaller or larger elements "bubble" to the top of the list. Although the algorithm is simple, it is too slow and impractical for most problems even when compared to insertion sort. Bubble sort can be practical if the input is in mostly sorted order with some out-of-order elements nearly in position. <sub><a  href="https://en.wikipedia.org/wiki/Bubble_sort"  target="_blank">more</a></sub>
## Time complexity
|Best Case|Average Case|Worst Case|
|:--:|:--:|:--:|
|O(n)|O(n<sup>2</sup>)|O(n<sup>2</sup>)|
## Bubble sort function
```c
void bubble_sort(int *array, size_t size)
```
* **Warning**
	This function makes changes to the array it receives
* **Description**
	Sorts an array using the bubble sort
* **Parameters**
	`array` array of numbers to sort
	`size` size of the array to sort
* **Return**
	Always void
## Implementation
```c
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
```
