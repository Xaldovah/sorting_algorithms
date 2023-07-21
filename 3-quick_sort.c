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
	quick_sort_recursive(array, 0, size - 1);
}

/**
 * quick_sort_recursive - performs  the recursive quick sort
 * @array: the array to be sorted
 * @low: the lower index of the array
 * @high: the higher index of the array
*/
void quick_sort_recursive(int *array, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high);
		quick_sort_recursive(array, low, pivot - 1);
		quick_sort_recursive(array, pivot + 1, high);
	}
}

/**
 * lomuto_partition - partitions an array
 * @array: the array to be sorted
 * @low: the lower index of the array
 * @high: the higher index of the array
 * Return: the partitioned array
*/
int lomuto_partition(int *array, int low, int high)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, high + 1);
			}
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, high + 1);

	return (i + 1);
}
