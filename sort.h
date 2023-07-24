#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* prototypes */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
listint_t *create_listint(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *left, size_t mid, int *right, size_t s_right, int *array);
void sift_down(int *array, size_t start, size_t end);
void heap_sort(int *array, size_t size);
void heapify(int arr[], int n, int i, size_t size);
void swap(int *array, size_t size, int *xp, int *yp);

#endif /* SORT_H_ */
