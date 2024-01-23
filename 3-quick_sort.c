#include "sort.h"
#include <stdio.h>

/**
 * swap: a function that swaps elements
 * @a: pointer to first integer
 * @b: pointer to second integer
 * Return: nothing
 */
void swap(int *a, int *b)
{
        int temp;
	
	temp = *a;
        *a = *b;
        *b = temp;
}

/**
 * lomuto_partition - function implementing the lomuto partitioning
 * @array: array to be partitioned
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array to be partitioned
 *
 * Description: takes last element of array/partition as pivot and rearranges
 * the elements in the partition: elements less than or equal to the pivot are
 * moved to the left and those greater to the right.
 *
 * Return: The index of the pivot's final position
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
        int pivot, i, j;

        pivot = array[high];
        i = low - 1;

        for (j = low; j <= high - 1; j++)
        {
                if (array[j] <= pivot)
                {
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
        }
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
	{
		print_array(array, size);
	}
        return (i + 1);
}
/**
 * quick_sort_recursive - a quick sort helper function that handles recursion
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: nothing
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

        if (low < high)
        {
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort- Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;
        quick_sort_recursive(array, 0, size - 1, size);
}
