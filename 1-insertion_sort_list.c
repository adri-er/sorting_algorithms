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
	listint_t *PREV = NULL;

	if (list == NULL || *list == NULL)
		return;

	for (node = *list; node; node = node->next)
	{
		for (in_node = node; IF_PREV_BIGGER(in_node); )
		{
			/* SWAP_LIST(list, in_node, listint_t *); */

			PREV = in_node->prev;
			if (in_node->prev->prev)
				in_node->prev->prev->next = in_node;
			else
				*list = in_node;
			in_node->prev->prev = in_node;
			in_node->prev->next = in_node->next;
			if (in_node->next)
				in_node->next->prev = in_node->prev;
			in_node->prev = PREV->prev;
			in_node->next = PREV;

			print_list((const listint_t *)*list);
		}
	}
}
