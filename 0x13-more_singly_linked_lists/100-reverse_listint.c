#include "lists.h"

/**
 * reverse_listint - function that reverses a linked list.
 * @head: pointer to pointer of linked list
 * Return: pointer to first node of reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *back, *next;

	if (!head || !*head)
		return (NULL);

	back = NULL;
	while (*head)
	{
		next = (*head)->next;
		(*head)->next = back;
		back = *head;
		*head = next;
	}
	(*head) = back;

	return (*head);
}
