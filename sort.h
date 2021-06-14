#ifndef SORT_H
#define SORT_H

/*------------------- LIBRARIES ---------------------- */
#include <stdio.h>
#include <stdlib.h>

/* -------------------- STRUCTURES ------------------- */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*----------------- MACROS VARIABLES ----------------- */
#define true (1)
#define false (!true)

/*----------------- MACROS FUNCTIONS ----------------- */
/**
 * SWAP - function is used to swap two va riables.
 * - Parameters
 * @VARIABLE_A: variable to swap
 * @VARIABLE_B: variable to swap
 * @TYPE: type of the variables
 * - Locals
 * #TMP_SWAP: temporal variable for to save value
 */
#define SWAP(VARIABLE_A, VARIABLE_B, TYPE) \
	do {                                   \
		TYPE TMP_SWAP = VARIABLE_A;        \
		VARIABLE_A = VARIABLE_B;           \
		VARIABLE_B = TMP_SWAP;             \
	} while (false)

#define IF_PREV_BIGGER(NODE) ((NODE)->prev && ((NODE)->prev->n > (NODE)->n))
#define LAST_POSITION(SIZE) ((int)(SIZE) - 1)
#define SWAP_DOUBLE_LIST(NODE, HEAD, TYPE)                        \
	do {                                                          \
		TYPE node_connections[4];                                 \
		node_connections[0] = (NODE)->prev->next;                 \
		node_connections[1] = (NODE)->prev->prev;                 \
		node_connections[2] = (NODE)->next;                       \
		node_connections[3] = (NODE)->prev;                       \
		if (*(HEAD) == node_connections[3])                       \
		{                                                         \
			*(HEAD) = (NODE);                                     \
		}                                                         \
		if (node_connections[3]->prev)                            \
		{                                                         \
			node_connections[3]->prev->next = node_connections[0];\
		}                                                         \
		if ((NODE)->next)                                         \
		{                                                         \
			(NODE)->next->prev = node_connections[3];             \
		}                                                         \
		node_connections[3]->next = node_connections[2];          \
		node_connections[3]->prev = node_connections[0];          \
		(NODE)->next = node_connections[3];                       \
		(NODE)->prev = node_connections[1];                       \
	} while (false)
/* -------------------- print.c ---------------------- */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* ---------------- 0-bubble_sort.c ------------------ */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

#endif /* SORTH_H */
