#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to the integer array
 * @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t iterator_a, iterator_b;
	int temp;


	if (size < 2)
		return;

	for (iterator_a = 0; iterator_a < size - 1; iterator_a++)
	{
		for (iterator_b = 0; iterator_b < size - 1; iterator_b++)
		{
			if (array[iterator_b] > array[iterator_b + 1])
			{
				temp = array[iterator_b];
				array[iterator_b] = array[iterator_b + 1];
				array[iterator_b + 1] = temp;
				print_array(array, size);

			}
		}


	}
}
