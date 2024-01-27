#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * getMax - Get the maximum value from an array.
 * @array: The array to find the maximum value from.
 * @size: The size of the array.
 * Return: The maximum value.
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    size_t i;
    
    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * countingSort - Perform counting sort on an array based on the digit.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current digit to consider.
 */
void countingSort(int *array, size_t size, int exp)
{
    const int radix = 10; // The base of the number system
    int *output = malloc(size * sizeof(int)), count, i;
    size_t i;
    
    if (output == NULL)
        return;

    count[radix] = {0};

    // Count the occurrences of each digit at the current place value
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % radix]++;

    // Accumulate the counts to get the correct position of each element
    for (i = 1; i < radix; i++)
        count[i] += count[i - 1];

    // Build the output array using the counting array and update counts
    for (i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % radix] - 1] = array[i];
        count[(array[i] / exp) % radix]--;
    }

    // Copy the sorted elements back to the original array
    for (i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;
    
    if (array == NULL || size < 2)
        return;

    max = getMax(array, size);

    // Perform counting sort for every digit, starting from the least significant
    for (exp = 1; max / exp > 0; exp *= 10)
        countingSort(array, size, exp);
}
