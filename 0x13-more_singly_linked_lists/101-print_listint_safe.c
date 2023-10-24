#include "lists.h"

/**
* print_listint_safe -  function that prints a linked list
* @head: pointer to pointer of a linked list
* Return: the number of nodes in the list
*/

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *prev, *ptr;
	size_t size;

	size = 0;

	if (!head)
		return (0);

	ptr = head;
	prev = head->next;

	while (prev != NULL && prev < ptr)
	{
		size += 1;
	printf("[%p] %i\n", (void *)ptr, ptr->n);
		ptr = ptr->next;
		prev = prev->next;
	}
	printf("[%p] %i\n", (void *)ptr, ptr->n);
	size += 1;
	if (prev)
		printf("-> [%p] %i\n", (void *)prev, prev->n);

	return (size);
}
