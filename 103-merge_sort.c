#include "sort.h"

/**
 * merge - Merges two sub-arrays of the array.
 * @array: The array to be sorted
 * @left: Start index of the left sub-array
 * @mid: Middle index
 * @right: End index of the right sub-array
 */
void merge(int *array, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;

	int *left_array = malloc(n1 * sizeof(int));
	int *right_array = malloc(n2 * sizeof(int));

	if (left_array == NULL || right_array == NULL)
	{
		free(left_array);
		free(right_array);
		return;
	}

	/* Copy data to temporary arrays left_array[] and right_array[] */
	for (i = 0; i < n1; i++)
		left_array[i] = array[left + i];
	for (j = 0; j < n2; j++)
		right_array[j] = array[mid + 1 + j];

	/* Merge the temporary arrays back into array[left..right] */
	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (left_array[i] <= right_array[j])
		{
			array[k] = left_array[i];
			i++;
		}
		else
		{
			array[k] = right_array[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of left_array[], if there are any */
	while (i < n1)
	{
		array[k] = left_array[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of right_array[], if there are any */
	while (j < n2)
	{
		array[k] = right_array[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	print_array(array + left, right - left + 1);

	/* Free the temporary arrays */
	free(left_array);
	free(right_array);
}

/**
 * merge_sort_recursive - Recursively divides the array into sub-arrays.
 * @array: The array to be sorted
 * @left: Start index of the sub-array
 * @right: End index of the sub-array
 */
void merge_sort_recursive(int *array, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		/* Same as (left + right) / 2, but avoids overflow for large left and right */
		mid = left + (right - left) / 2;

		printf("Merging...\n[left]: ");
		print_array(array + left, mid - left + 1);
		printf("[right]: ");
		print_array(array + mid + 1, right - mid);

		/* Recursively sort the first and second halves */
		merge_sort_recursive(array, left, mid);
		merge_sort_recursive(array, mid + 1, right);

		/* Merge the sorted halves */
		merge(array, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1);
}
