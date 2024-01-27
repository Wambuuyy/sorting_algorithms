#include <stdio.h>
#include "sort.h"

/**
 * quick_sort_hoare_recursive - Sorts a partition of an array using Quick Sort.
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 */
void quick_sort_hoare_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        ssize_t pivot = hoare_partition(array, low, high, size);

        // Sort the two halves
        quick_sort_hoare_recursive(array, low, pivot, size);
        quick_sort_hoare_recursive(array, pivot + 1, high, size);
    }
}

/**
 * hoare_partition - Partitions the array using the Hoare partition scheme.
 * @array: The array to be partitioned.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 * Return: The pivot index.
 */
ssize_t hoare_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[low];
    ssize_t i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        // Swap array[i] and array[j]
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        // Print the array after each swap
        printf("Swap elements: ");
        print_array(array, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_hoare_recursive(array, 0, size - 1, size);
}
