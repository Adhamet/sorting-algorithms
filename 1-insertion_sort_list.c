#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * in acsending order using Insertion Sort algorithm
 * @list: The Doubly Linked List
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *tmp;

	if (list == NULL || *list == NULL)
		return;

	current_node = *list;
	while (current_node)
	{
		tmp = current_node;
		while ((tmp->prev) && (tmp->prev->n > tmp->n))
		{
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*list = tmp;
			print_list(*list);
		}
		current_node = current_node->next;
	}
}
