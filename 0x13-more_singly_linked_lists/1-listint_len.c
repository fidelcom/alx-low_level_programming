#include "lists.h"

/**
 * listint_len - function tha returns the number of elements
 * in a linked listint_t list
 * @h: input list
 * Return: number of nodes in list
 */

size_t listint_len(const listint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes += 1;
		h = h->next;
	}

	return (nodes);
}
