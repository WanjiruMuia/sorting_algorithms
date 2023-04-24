#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm
 * @list: pointer to head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *start = NULL, *end = NULL, *curr = NULL;
    int swapped = 0;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        for (curr = start = (*list); curr->next != end; curr = curr->next)
        {
            if (curr->n > curr->next->n)
            {
                swap_nodes(list, &curr, &curr->next);
                print_list(*list);
                swapped = 1;
            }
        }
        end = curr;

        if (swapped == 0)
            break;

        swapped = 0;
        for (curr = end = end->prev; curr->prev != start->prev; curr = curr->prev)
        {
            if (curr->n < curr->prev->n)
            {
                swap_nodes(list, &curr->prev, &curr);
                print_list(*list);
                swapped = 1;
            }
        }
        start = curr;
    } while (swapped);
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to head of the doubly linked list
 * @node1: pointer to first node to swap
 * @node2: pointer to second node to swap
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
    listint_t *temp = NULL;

    if (*node1 == *node2)
        return;

    if ((*node1)->prev == NULL)
    {
        *list = *node2;
        (*node2)->prev = NULL;
    }
    else if ((*node2)->prev == NULL)
    {
        *list = *node1;
        (*node1)->prev = NULL;
    }

    if ((*node1)->next == *node2)
    {
        (*node1)->next = (*node2)->next;
        (*node2)->prev = (*node1)->prev;
        (*node1)->prev = *node2;
        (*node2)->next = *node1;
        if ((*node1)->next != NULL)
            (*node1)->next->prev = *node1;
        if ((*node2)->prev != NULL)
            (*node2)->prev->next = *node2;
    }
    else
    {
        temp = (*node1)->next;
        (*node1)->next = (*node2)->next;
        (*node2)->next = temp;
        temp = (*node1)->prev;
        (*node1)->prev = (*node2)->prev;
        (*node2)->prev = temp;
        if ((*node1)->next != NULL)
            (*node1)->next->prev = *node1;
        if ((*node2)->next != NULL)
            (*node2)->next->prev = *node2;
        if ((*node1)->prev != NULL)
            (*node1)->prev->next = *node1;
        if ((*node2)->prev != NULL)
            (*node2)->prev->next = *node2;
    }
}

