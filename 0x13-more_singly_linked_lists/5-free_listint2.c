#include "lists.h"

/**
 * free_listint2 - function that frees a linked list, and sets head to NULL
 * @head: linked list to free
 */

void free_listint2(listint_t **head)
{
	listint_t *ptr;

	if (!head)
		return;

	while (*head)
	{
		ptr = *head;
		*head = ptr->next;
		free(ptr);
	}

}
