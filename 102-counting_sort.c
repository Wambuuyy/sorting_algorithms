#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max, *count_array;
	size_t i, idx;
	if (array == NULL || size < 2)
		return;
	/* Find the maximum value in the array */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	/* Create a counting array with size (max + 1) */
	count_array = malloc((max + 1) * sizeof(int));
	if (count_array == NULL)
		return;
	/* Populate the counting array with the frequency of each element */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	/* Print the counting array */
	for (i = 0; i <= max; i++)
		printf("%d%s", count_array[i], (i == max) ? "\n" : ", ");
	/* Update the original array with sorted values */
	idx = 0;
	for (i = 0; i <= max; i++)
	{
		while (count_array[i] > 0)
		{
			array[idx] = i;
			idx++;
			count_array[i]--;
		}
	}

	/* Free the counting array */
	free(count_array);
}
