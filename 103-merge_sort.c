#include "sort.h"

/**
 * merge - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @s_right: size of the array
 * @right: array to be sorted
 * @left: array to be sorted
 * @mid: the middle of the array
 */
void merge(int *left, size_t mid, int *right, size_t s_right, int *array)
{
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(right, s_right);

	while (i < mid && j < s_right)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		array[k] = left[i];
		i++;
		k++;
	}
	while (j < s_right)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(array, k);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i = 0;
	int *left = NULL;
	int *right = NULL;

	if (array == NULL || size < 2)
	{
		return;
	}
	mid = size / 2;
	left = malloc(mid * sizeof(int));
	right = malloc((size - mid) * sizeof(int));

	for (i = 0; i < mid; i++)
	{
		left[i] = array[i];
	}
	for (i = mid; i < size; i++)
	{
		right[i - mid] = array[i];
	}
	merge_sort(left, mid);
	merge_sort(right, size - mid);

	merge(left, mid, right, size - mid, array);

	free(left);
	free(right);
}
