#include "sort.h"

/**
 * max - returns the largest number in an array
 * @array: array to be sorted
 * @size: size of the array
 * Return: largest number
*/
int max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * counting_sort - sorts an array using counting sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
*/
void counting_sort(int *array, size_t size)
{
	int i, *count, *output, large;

	if (array == NULL || size < 2)
	{
		return;
	}
	large = max(array, size);

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		return;
	}
	count = malloc(sizeof(int) * (large + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}
	memset(count, 0, sizeof(int) * (large + 1));
	for (i = 0; i < (int)size; i++)
	{
		count[array[i]]++;
	}
	for (i = 1; i <= large; i++)
	{
		count[i] += count[i - 1];
	}
	print_array(count, large + 1);
	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = output[i];
	}
	free(count);
	free(output);
}
