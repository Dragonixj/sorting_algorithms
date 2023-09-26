#include "sort.h"
/**
 * lomuto_part - Lomuto partition scheme for quick sort
 * @array: The array to be sorted
 * @l_idx: The low index of the partition
 * @h_idx: The high index of the partition
 * @size: the size of the array
 *
 * Return: The position of the pivot element
 */
int lomuto_part(int *array, int l_idx, int h_idx, size_t size)
{
    int pivot = array[h_idx];
    int i = l_idx - 1;
    int j, tmp;

    for (j = l_idx; j <= h_idx - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    tmp = array[i + 1];
    array[i + 1] = array[h_idx];
    array[h_idx] = tmp;

    return (i + 1);
}


/**
 * quick_sort_rc - Recursive function for quick_sort
 * @array: the array to be sorted
 * @l_idx: the low index of the partition
 * @h_idx: the high index of the partition
 * @size: the size of the array
 */
void quick_sort_rc(int *array, int l_idx, int h_idx, size_t size)
{
    int pivot_idx;

    if(l_idx < h_idx)
    {
        pivot_idx = lomuto_part(array, l_idx, h_idx, size);
        print_array(array, size);

        quick_sort_rc(array, l_idx, pivot_idx - 1, size);
        quick_sort_rc(array, pivot_idx + 1, h_idx, size);
    }
}


/**
 * quick_sort - Sorts an array of integers in ascending order using quick sort
 *              algorithm(Lomuto partition scheme)
  * @array: the array to be sorted
  * @size: the size of the array
  */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_rc(array, 0, size - 1,size);
}
