#ifndef SORT_H
#define SORT_H
/*---------------------------------------------------- */
/*-------------------- LIBRARIES --------------------- */
/*---------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------------- */
/* -------------------- STRUCTURES ------------------- */
/*---------------------------------------------------- */
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

typedef unsigned char bool;

/*---------------------------------------------------- */
/*----------------- MACROS VARIABLES ----------------- */
/*---------------------------------------------------- */
#define true (1)
#define false (!true)

/*---------------------------------------------------- */
/*----------------- MACROS FUNCTIONS ----------------- */
/*---------------------------------------------------- */

#include "macro_functions.h"

/*---------------------------------------------------- */
/* ------------------- PROTOTYPES -------------------- */
/*---------------------------------------------------- */
/* --> print.c */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);

#endif /* SORTH_H */
