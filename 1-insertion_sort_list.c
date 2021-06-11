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
	listint_t *in_node = NULL;

	if (list == NULL || *list == NULL)
		return;

	/*TODO precaution when change the node head */
	for (node = *list; node ; node = node->next)
	{
		for (in_node = node; IF_PREV_BIGGER(in_node); in_node = in_node->prev)
		{
			SWAP_LIST(in_node, listint_t);
		}

	}
}

