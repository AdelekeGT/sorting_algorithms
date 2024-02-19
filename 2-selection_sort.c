#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: pointer to the array to be sorted
 * @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	size_t it_a, it_b, min_index, temp;

	if (size < 2)
		return;

	for (it_a = 0; it_a < size - 1; it_a++)
	{
		min_index = it_a;

		for (it_b = it_a + 1; it_b < size; it_b++)
		{
			if (array[it_b] < array[min_index])
				min_index = it_b;
		}

		if (min_index != it_a)
		{
			temp = array[it_a];
			array[it_a] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}

