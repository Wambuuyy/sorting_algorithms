#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merge a bitonic sequence in the given direction.
 * @array: The array to be sorted.
 * @low: The starting index of the sequence.
 * @count: The number of elements to be merged.
 * @up: The direction of the merge (1 for UP, 0 for DOWN).
 */
void bitonic_merge(int *array, size_t low, size_t count, int up)
{
    if (count > 1)
    {
        size_t k = count / 2;
        for (size_t i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == up)
            {
                // Swap elements if they are in the wrong order
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;

                // Print the array after swapping elements
                printf("Merging [%lu/%lu] (%s):\n", count, count * 2, (up) ? "UP" : "DOWN");
                print_array(array, count * 2);
            }
        }

        // Recursively merge both halves in the given direction
        bitonic_merge(array, low, k, up);
        bitonic_merge(array, low + k, k, up);
    }
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence.
 * @array: The array to be sorted.
 * @low: The starting index of the sequence.
 * @count: The number of elements in the sequence.
 * @up: The direction of the sort (1 for UP, 0 for DOWN).
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int up)
{
    if (count > 1)
    {
        size_t k = count / 2;

        // Sort the first half in ascending order
        bitonic_sort_recursive(array, low, k, 1);

        // Sort the second half in descending order
        bitonic_sort_recursive(array, low + k, k, 0);

        // Merge the sorted sequence
        bitonic_merge(array, low, count, up);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort.
 * @array: The array to be sorted.
 * @size: The size of the array (must be a power of 2).
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 1 || (size & (size - 1)) != 0)
        return; // Check if size is a power of 2

    // Initially, the entire sequence is in increasing order (UP)
    bitonic_sort_recursive(array, 0, size, 1);
}
