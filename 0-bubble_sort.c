#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 * @array - The array the data will be stored
 * @size - The size of the array
 */

void bubble_sort(int *array, size_t size)
{
    bool is_swapped; /* to check if any swaps have occured */
    int tmp;
    size_t i, j;
    
    for (i = 0; i < size - 1; i++){
        is_swapped = false; /* initializing the swap to false */
        for (j = 0; j < size - 1; j++){

            /* Swap if the element greater than the next element */
            if(array[j] > array[j + 1]){
                /* swap the elements */
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;

                /* Print the array after swapping */ 
                print_array(array, size);

                is_swapped = true; /* marked that  swap has occured */
            }
        }

        if (!is_swapped){
            break;
        }
    }
}
