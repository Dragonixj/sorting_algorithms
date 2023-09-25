#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order
 * @list: The pointer to a pointer to the head of a list
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *current;
    listint_t *tmp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;

    while(current)
    {
        tmp = current;
        current = current->next;

        /* Find the correct position to insert the current node */
        while(tmp->prev && tmp->prev->n > tmp->n)
        {
            /* Swap the tmp with its previous node */
            tmp->prev->next = tmp->next;
            if(tmp->next)
                tmp->next->prev = tmp->prev;

            tmp->next = tmp->prev;
            tmp->prev = tmp->prev->prev;
            tmp->next->prev = tmp;

            /* if tmp becomes the new head of the list update *list */
            if(!tmp->prev)
                *list = tmp;
            else
                tmp->prev->next = tmp;
            print_list(*list);
        }
    }
}
