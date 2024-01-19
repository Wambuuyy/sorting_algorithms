#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list in ascending order
 *	using Insertion sort
 * @list: pointer to a pointer to the head of the double linked list
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *key = (*list)->next;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;
	while (key)
	{
		temp = key->next;
		while (key->prev && key->n < key->prev->n)
		{
			/*swap the nodes*/
			if (key->next != NULL)
				key->next->prev = key->prev;
			key->prev->next = key->next;
			key->next = key->prev;
			key->prev = key->prev->prev;
			key->next->prev = key;
			if (key->prev != NULL)
				key->prev->next = key;
			else
				*list = key;
			print_list(*list);
		}
		key = temp;
	}
}
