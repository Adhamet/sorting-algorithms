#include "sort.h"

/* helper function */
listint_t *swap_node(listint_t *node, listint_t **list);

/**
 * cocktail_sort_list: sorts a doubly linked list of integers in 
 * ascending order using the Cocktail shaker sort algorithm
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int flag = 1;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	node = *list;
	while (flag)
	{
		flag = 0;

		while (node->next)
		{
			if ((node->n) > (node->next->n))
			{
				node = swap_node(node->next, list);
				flag = 1;
				print_list(*list);
			}
			node = node->next;
		}

		if (flag == 0)
			break;
		flag = 0;

		while (node->prev)
		{
			if ((node->prev->n) > (node->n))
			{
				node = swap_node(node, list);
				flag = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}

/**
 * swap_node - swaps between current node
 * and its previous in a list
 * @node: the current node
 * @list: the list
 * Return: pointer to list
 */
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
