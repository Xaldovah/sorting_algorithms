#include "sort.h"

/**
 * swap - swaps two integers
 * @array: the array to swap
 * @size: size of the array
 * @xp: pointer to the first integer
 * @yp: pointer to the second integer
 */
void swap(int *array, size_t size, int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
	if (*xp != *yp)
	{
		print_array(array, size);
	}
}

/**
 * heapify - sorts an array of integers in ascending order
 * @arr: array to be sorted
 * @n: size of the array
 * @i: starting index
 * @size: size of array
 */
void heapify(int arr[], int n, int i, size_t size)
{
	int max = 0, left = 0, right = 0;

	max = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < n && arr[left] > arr[max])
	{
		max = left;
	}
	if (right < n && arr[right] > arr[max])
	{
		max = right;
	}
	if (max != i)
	{
		swap(arr, size, &arr[i], &arr[max]);
		heapify(arr, n, max, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}
	for (i = size - 1; i >= 0; i--)
	{
		swap(array, size, &array[0], &array[i]);
		heapify(array, i, 0, size);
	}
}
