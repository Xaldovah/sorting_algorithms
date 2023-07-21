#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers in ascending order
 * @array: the array to be sorted
 * @size: the size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - performs  the recursive quick sort
 * @array: the array to be sorted
 * @low: the lower index of the array
 * @high: the higher index of the array
 * @size: the size of array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - partitions an array
 * @array: the array to be sorted
 * @low: the lower index of the array
 * @high: the higher index of the array
 * @size: size of array
 * Return: the partitioned array
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i = 0, j = 0, pivot = 0, temp = 0;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (temp != array[i])
				print_array(array, size);

			i++;
		}
	}

	temp = array[i];
	array[i] = array[high];
	array[high] = temp;

	if (temp != array[i])
		print_array(array, size);

	return (i);
}
