# Shell sort
## Description
Also known as Shell sort or Shell's method, is an in-place comparison sort. It can be seen as either a generalization of sorting by exchange (bubble sort) or sorting by insertion (insertion sort).
The method starts by sorting pairs of elements far apart from each other, then progressively reducing the gap between elements to be compared. By starting with far apart elements, it can move some out-of-place elements into position faster than a simple nearest neighbor exchange.
Donald Shell published the first version of this sort in 1959. The running time of Shellsort is heavily dependent on the gap sequence it uses. For many practical variants, determining their time complexity remains an open problem.
## Time complexity
|Best Case|Average Case|Worst Case|
|:--:|:--:|:--:|
|O(nlogn)|O(n<sup>4/3</sup>)|O(n<sup>3/2</sup>)|
## Selection sort function
```c
void shell_sort(int *array, size_t size)
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
```
