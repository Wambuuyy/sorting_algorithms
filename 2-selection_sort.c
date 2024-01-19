#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using selection sort algorithm
 * @array: pointer to an array of integers
 * @size: size of the array to be sorted
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t min_index, i, j;
	int temp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = (i + 1); j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
