#include "lists.h"

/**
* free_listint_safe - function that frees a linked list.
* @h: pointer to a pointer of a linked list
* Return: size of the list that was free’d
*/

size_t free_listint_safe(listint_t **h)
{
	listint_t *first, *second, *freed;
	size_t size;

	size = 0;

	if (!h || !*h)
		return (0);
	second = (*h)->next;
	first = *h;

	while (second && second < first)
	{
		freed = first;
		second = second->next;
		first = first->next;
		size += 1;

		free(freed);
	}
	size += 1;
	free(first);
	*h = NULL;
	return (size);
}
