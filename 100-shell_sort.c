#include "sort.h"

/**
 * shell_sort - a function that sorts an array of integers in ascending order
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: nothing
*/
void shell_sort(int *array, size_t size)
{
	int i = 0, j = 0, gap = 1, temp = 0;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (gap < (int) size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		i = gap;

		while (i < (int) size)
		{
			temp = array[i];
			j = i;

			while (j > gap - 1 && array[j - gap] >= temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = temp;
			i++;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
