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
	listint_t *node_connections[4];

	if (list == NULL || *list == NULL)
		return;

	for (node = (*list)->next; node; node = next_node)
	{
		next_node = node->next;
		for (in_node = node; IF_PREV_BIGGER(in_node);)
		{
			node_connections[0] = in_node->prev->next;
			node_connections[1] = in_node->prev->prev;
			node_connections[2] = in_node->next;
			node_connections[3] = in_node->prev;
			if (*list == node_connections[3])
			{
				*list = in_node;
			}	
			if (node_connections[3]->prev)
			{
				node_connections[3]->prev->next = node_connections[0];
			}
			if (in_node->next)
			{
				in_node->next->prev = node_connections[3];
			}
			node_connections[3]->next = node_connections[2];
			node_connections[3]->prev = node_connections[0];
			in_node->next = node_connections[3];
			in_node->prev = node_connections[1];
			print_list((const listint_t *)*list);
		}
	}
}
