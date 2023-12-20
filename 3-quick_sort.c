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
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The Final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, left_p, right_p;

	pivot = array + right;
	for (left_p = right_p = left; right_p < right; right_p++)
	{
		if (array[right_p] < *pivot)
		{
			if (left_p < right_p)
			{
				switch_int(array + right_p, array + left_p);
				print_array(array, size);
			}
			left_p++;
		}
	}

	if (array[left_p] > *pivot)
	{
		switch_int(array + left_p, pivot);
		print_array(array, size);
	}

	return (left_p);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Return: Void.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int pivot_indx;

	if (right - left > 0)
	{
		pivot_indx = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, pivot_indx - 1);
		lomuto_sort(array, size, pivot_indx + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Void.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || !size)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
