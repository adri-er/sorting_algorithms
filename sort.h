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
 * @TMP_SWAP: temporal variable for to save value
 */
#define SWAP(VARIABLE_A, VARIABLE_B, TYPE) \
    do                                     \
    {                                      \
        TYPE TMP_SWAP = VARIABLE_A;        \
        VARIABLE_A = VARIABLE_B;           \
        VARIABLE_B = TMP_SWAP;             \
    } while (false)

#define IF_PREV_BIGGER(NODE) ((NODE)->prev && ((NODE)->prev->n > (NODE)->n))

#define SWAP_LIST(HEAD, NODE, TYPE)            \
    do                                         \
    {                                          \
        TYPE PREV = (NODE)->prev;              \
        if ((NODE)->prev->prev)                \
            (NODE)->prev->prev->next = (NODE); \
        else                                   \
            *HEAD = (NODE);                    \
        (NODE)->prev->prev = (NODE);           \
        (NODE)->prev->next = (NODE)->next;     \
        if ((NODE)->next)                      \
            (NODE)->next->prev = (NODE)->prev; \
        (NODE)->prev = PREV->prev;             \
        (NODE)->next = PREV;                   \
    } while (false)

/* -------------------- print.c ---------------------- */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* ---------------- 0-bubble_sort.c ------------------ */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif /* SORTH_H */
