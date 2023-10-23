#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a listint_t linked
 * list, and returns the head node’s data (n).
 * @head: linked list
 * Return: deleted head node's data
 */

int pop_listint(listint_t **head)
{
	int d;
	listint_t *temp;

	if (!*head)
		return (0);

	temp = *head;

	d = temp->n;

	*head = temp->next;
	free(temp);

	return (d);

}
