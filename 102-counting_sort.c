#include "sort.h"
/**
 * counting_sort - Sorts an array of integers using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
    int *int_count;
    size_t k = 0, i;
    int *count, *output;

    if (!array || size < 2)
        return;

    for (i = 0; i < size; i++)
        if ((size_t)array[i] > k)
            k = (size_t)array[i];

    count = malloc(sizeof(int) * (k + 1));
    output = malloc(sizeof(int) * size);
    if (!count || !output)
    {
        free(count);
        free(output);
        return;
    }

    for (i = 0; i <= k; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[(size_t)array[i]] += 1;

    /* Copy counts to a temporary integer array for printing */
    int_count = malloc(sizeof(int) * (k + 1));
    if (!int_count)
    {
        free(count);
        free(output);
        return;
    }

    for (i = 0; i <= k; i++)
        int_count[i] = (int)count[i];

    print_array(int_count, k + 1);

    for (i = 1; i <= k; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < size; i--)
    {
        output[count[(size_t)array[i]] - 1] = array[i];
        count[(size_t)array[i]] -= 1;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(count);
    free(output);
    free(int_count);
}
