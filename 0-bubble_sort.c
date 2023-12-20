#include "sort.h"

/**
 * switch_int - Switch two integers in an array.
 * @a: The first integer to switch.
 * @b: The second integer to switch.
 */
void switch_int(int *a, int *b)
{
	int cp;

	cp = *a;
	*a = *b;
	*b = cp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t pass, indx;

	if (array == NULL || !size)
		return;

	pass = 0;
	while (pass < size)
	{
		for (indx = 0; indx < size - 1; indx++)
		{
			if (array[indx] > array[indx + 1])
			{
				switch_int(array + indx, array + indx + 1);
				print_array(array, size);
			}
		}
		pass++;
	}
}
