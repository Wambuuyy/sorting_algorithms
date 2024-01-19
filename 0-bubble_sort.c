#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *	using Bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (!array && size < 2)
		return;
	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				/*swap the elements*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
