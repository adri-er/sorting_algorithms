# Insertion sort
## Description
**Insertion sort** is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, insertion sort provides several advantages:  <sub><a  href="https://en.wikipedia.org/wiki/Insertion_sort"  target="_blank">more</a></sub> 
## Time complexity
|Best Case|Average Case|Worst Case|
|:--:|:--:|:--:|
|O(n)|O(n<sup>2</sup>)|O(n<sup>2</sup>)|
## Insertion sort function
```c
void insertion_sort_list(listint_t **list)
```
* **Warning**
	This function makes changes to the list it receives
* **Description**
	  sort double linked list with insertion algorithm.
* **Parameters**
	`list` pointer to the head of the list 
* **Return**
	Always void
## Implementation
```c
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL;
	listint_t *next_node = NULL;
	listint_t *in_node = NULL;

	if (list == NULL || *list == NULL)
		return;

	for (node = (*list)->next; node; node = next_node)
	{
		next_node = node->next;
		for (in_node = node; IF_PREV_BIGGER(in_node);)
		{
			SWAP_DOUBLE_LIST(in_node, list, listint_t *);
			print_list((const listint_t *)*list);
		}
	}
}

```
