# Cocktail sort
## Description
Also known as bidirectional bubble sort, cocktail sort, shaker sort (which can also refer to a variant of selection sort), ripple sort, shuffle sort, or shuttle sort, is an extension of bubble sort. The algorithm extends bubble sort by operating in two directions. While it improves on bubble sort by more quickly moving items to the beginning of the list, it provides only marginal performance improvements.
Like most variants of bubble sort, cocktail shaker sort is used primarily as an educational tool. More performant algorithms such as timsort, or merge sort are used by the sorting libraries built into popular programming languages such as Python and Java. <sub><a  href="https://en.wikipedia.org/wiki/Cocktail_shaker_sort"  target="_blank">more</a></sub> 
## Time complexity
|Best Case|Average Case|Worst Case|
|:--:|:--:|:--:|
|O(n)|O(n<sup>2</sup>)|O(n<sup>2</sup>)|
## Cocktail sort function
```c
void cocktail_sort_list(listint_t **list)
```
* **Warning**
	This function makes changes to the doubly linked list it receives
* **Description**
	Sorts a linked list using the selection sort algorithm
* **Parameters**
	`list` double linked list of numbers
* **Return**
	Always void
## Implementation
```c
void cocktail_sort_list(listint_t **list)
{
	listint_t *node = *list, *next_node = NULL, *in_node = NULL;
	int changes = 0;

	if (list == NULL || *list == NULL)
		return;

	for (node = *list; node; node = next_node)
	{
		next_node = node->next;
		for (in_node = *list; in_node;)
		{
			if (in_node->next && in_node->next->n < in_node->n)
			{
				changes++;
				SWAP_DOUBLE_LIST_NEXT(in_node, list, listint_t *);
				print_list((const listint_t *)*list);
				continue;
			}
			if (in_node->next)
				in_node = in_node->next;
			else
			{
				if (changes != 0)
					break;
				in_node = in_node->next;
			}
		}
		for (; in_node;)
		{
			if (in_node->prev && in_node->n < in_node->prev->n)
			{
				SWAP_DOUBLE_LIST(in_node, list, listint_t *);
				print_list((const listint_t *)*list);
				continue;
			}
			if (in_node->prev == NULL)
				break;
			in_node = in_node->prev;
		}
	}
}
```
