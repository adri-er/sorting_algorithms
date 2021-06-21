#include "sort.h"

/**
 * cocktail_sort_list - sort list using the cocktail algorithm.
 *
 * @list: head of a double linked list.
 *
 * Return: Always void.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *next_node = NULL, *in_node = NULL;
	int changes;

	if (list == NULL || *list == NULL)
		return;
	node = *list;
	for (node = *list; node; node = next_node)
	{
		changes = 0;
		next_node = node->next;
		for (in_node = *list; in_node;)
		{
			if (in_node->next && in_node->next->n < in_node->n)
			{	changes++;
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
