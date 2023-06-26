#include "sort.h"

/* helper function */
listint_t *swap_node(listint_t *node, listint_t **list);

/**
 * insertion_sort_list - sorts a doubly linked list
 * in acsending order using Insertion Sort algorithm
 * @list: The Doubly Linked List
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || *list == NULL)
		return;

	node = *list;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *current = node;
	current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;
	current->next = current->prev;
	current->prev = current->prev->prev;
	current->next->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
