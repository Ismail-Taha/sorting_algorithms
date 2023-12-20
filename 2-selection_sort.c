#include "sort.h"

/**
 * selection_sort - function sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: NULL.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_ptr, tmp;

	if (array == NULL || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_ptr = &array[i];

		for (j = i + 1; j < size; j++)
			min_ptr = (array[j] < *min_ptr) ? (&array[j]) : min_ptr;

		if ((array[i]) != *min_ptr)
		{
			tmp = array[i];
			array[i] = *min_ptr;
			*min_ptr = tmp;

			print_array(array, size);
		}
	}
}
