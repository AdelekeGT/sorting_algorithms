#include "sort.h"

/**
 * Lomuto - partitions data
 * @array: array to be partitioned
 * @low_piv: lower pivot
 * @upp_piv: upper pivot
 * @size: size of array
 *
 * Return: int datatype
*/
int Lomuto(int *array, int low_piv, int upp_piv, size_t size)
{
	int i, j, temp, pivot;

	pivot = array[upp_piv];
	i = low_piv;

	for (j = low_piv; j < upp_piv; j++)
	{
		if (array[j] <= pivot)
		{
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (upp_piv != i)
	{
		array[upp_piv] = array[i];
		array[i] = pivot;
		print_array(array, size);
	}

	return (i);
}

/**
 * helper_quick_sort - helps in recursive quick sort call
 * @array: array to be sorted
 * @low_piv: lower pivot
 * @upp_piv: higher pivot
 * @size: size of array
*/
void helper_quick_sort(int *array, int low_piv, int upp_piv, size_t size)
{
	int par;

	if (low_piv < upp_piv)
	{
		par = Lomuto(array, low_piv, upp_piv, size);
		helper_quick_sort(array, low_piv, par - 1, size);
		helper_quick_sort(array, par + 1, upp_piv, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: pointer to the integer array
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	helper_quick_sort(array, 0, size - 1, size);
}
