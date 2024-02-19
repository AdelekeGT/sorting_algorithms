#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * @list: double pointer pointing to head node
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *node_current, *a_node, *b_node;

	if (list == NULL || *(list) == NULL)
		return;

	node_current = (*list)->next;

	while (node_current)
	{
		a_node = node_current;
		node_current = node_current->next;

		while (a_node->prev != NULL && a_node->n < a_node->prev->n)
		{
			b_node = a_node->prev;

			if (a_node->next != NULL)
				a_node->next->prev = a_node->prev;
			a_node->prev->next = a_node->next;
			a_node->prev = b_node->prev;
			a_node->next = b_node;

			if (b_node->prev != NULL)
				b_node->prev->next = a_node;
			else
				*list = a_node;

			b_node->prev = a_node;
			print_list(*list);
		}
	}
}
