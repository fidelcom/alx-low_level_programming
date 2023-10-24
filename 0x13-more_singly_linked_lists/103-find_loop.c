#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list.
 * @head: pointer to pointer of a linked list
 * Return:  address of the node where the loop starts, or
 * NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *node, *ptr;

	node = ptr = head;

	while (node && ptr)
	{
		node = node->next;
		ptr = ptr->next->next;

		if (node == ptr)
		{
			node = head;
			while (node != ptr)
			{
				node = node->next;
				ptr = ptr->next;
			}
			return (node);
		}
	}

	return (NULL);
}
