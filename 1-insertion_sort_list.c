#include "sort.h"

/**
 * insertion_sort_list - this func uses the insertion sort to sort the list
 * @list: the list to sort
 * Return: 0 if successful, 1 otherwise
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *next_node, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current_node = (*list)->next;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		prev_node = current_node->prev;

		while (prev_node != NULL && current_node->n < prev_node->n)
		{
			if (prev_node->prev != NULL)
			{
				prev_node->prev->next = current_node;
			}
			else
			{
				*list = current_node;
			}
			if (current_node->next != NULL)
			{
				current_node->next->prev = prev_node;
			}
			prev_node->next = current_node->next;
			current_node->prev = prev_node->prev;
			prev_node->prev = current_node;
			current_node->next = prev_node;

			print_list(*list);

			prev_node = current_node->prev;
		}
		current_node = next_node;
	}
}
