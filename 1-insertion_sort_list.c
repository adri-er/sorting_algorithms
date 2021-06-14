#include "sort.h"


/**
 * insertion_sort_list - sort double linked list with insertion algorithm
 *
 * @list: pointer to the head of the list
 *
 * Return: Always void
 */
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
