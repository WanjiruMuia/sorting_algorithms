#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *left, *right, *curr;
    int swapped;

    if (!list || !*list || !(*list)->next)
        return;

    do {
        swapped = 0;
        for (left = *list; left->next != NULL; left = left->next)
        {
            if (left->n > left->next->n)
            {
                right = left->next;
                if (right->next != NULL)
                    right->next->prev = left;
                left->next = right->next;
                right->prev = left->prev;
                left->prev = right;
                right->next = left;
                if (right->prev == NULL)
                    *list = right;
                else
                    right->prev->next = right;
                swapped = 1;
                print_list(*list);
            }
        }
        if (swapped == 0)
            break;
        swapped = 0;
        for (right = left->prev; right != NULL; right = right->prev)
        {
            if (right->prev != NULL && right->n < right->prev->n)
            {
                left = right->prev;
                if (left->prev != NULL)
                    left->prev->next = right;
                right->prev = left->prev;
                left->next = right->next;
                right->next = left;
                left->prev = right;
                if (right->prev == NULL)
                    *list = right;
                else
                    right->prev->next = right;
                swapped = 1;
                print_list(*list);
            }
        }
    } while (swapped == 1);
}
