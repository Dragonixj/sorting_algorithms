#include "sort.h"
/**
 * selection_sort - sorts and array of integers in ascending order
 * @array: the pointer to the first element of the array
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
    size_t i, j;
    size_t min_index;
    int tmp;

    for (i = 0; i < size -1; i++)
    {
        min_index = i;

        /* Find the index of the min element in the unsorted portion
         * of array*/
        for (j = i + 1; j < size; j++)
        {
            if (array[j] > array[min_index])
                min_index = j;
        }

        /* swap the min element with the first element */
        if (min_index != i)
        {
            tmp = array[i];
            array[i] = array[min_index];
            array[min_index] = tmp;
            print_array(array, size); /* printing the array after each swap*/

        }
    }
}
