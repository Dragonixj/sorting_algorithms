#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order
 * @list: The pointer to a pointer to the head of a list
 */
void insertion_sort_list(listint_t **list)
{

    listint_t *current;
    current = (*list)->next;

    listint_t *prev_node;
    listint_t *next_node;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (current != NULL){

        prev_node = current->prev;
        next_node = current->next;

        /* Find the correct position to insert the current node */
        while (prev_node != NULL && prev_node->n > current->n)
        {
            prev_node = prev_node->prev;
        }
        /* If current node in correct position, move to next node */
        if(prev_node == current->next)
        {
            current = next_node;
            continue;
        }
        /* Remove the current node from its position */
        if(current->next != NULL)
        {
            current->next->prev = current->prev;
        }
        if(current->prev != NULL)
        {
            current->prev->next = current->next;
        }
        else
        {
            *list = current->next;
        }

        /* Insert the current node into its correct position */
        if(prev_node != NULL)
        {
            prev_node->next = current;
        }
        else
        {
            *list = current;
        }

        current->prev = prev_node;
        current->next = prev_node != NULL ? prev_node->next : NULL;

        if (prev_node != NULL)
        {
            prev_node->next = current;
        }

        if (current->next != NULL)
        {
            current->next->prev = current;
        }
        
        /* Move to the next unsorted node */
        current = next_node;

        /* Print the list after each swap action */
    }
}
