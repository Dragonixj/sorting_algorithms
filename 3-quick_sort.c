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
