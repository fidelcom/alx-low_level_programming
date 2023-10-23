#include "lists.h"

/**
 * add_nodeint_end - function that adds a new node at
 * the end of a listint_t list
 * @head: pointer to pointer of linked list
 * @n: item to add to new node
 * Return: address of new element, or NULL if failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{

	listint_t *node, *temp;

	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (!*head)
		*head = node;
	else
	{
		temp = *head;

		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}

	return (node);
}
