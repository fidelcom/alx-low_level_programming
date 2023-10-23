#include "lists.h"

/**
 * add_nodeint - function that adds a new node at the
 * beginning of a listint_t list
 * @head: pointer to a pointer of linked list
 * @n: item to add to new node
 * Return: address of new element, or NULL if failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{

	listint_t *node;

	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);

	node->n = n;

	node->next = *head;
	*head = node;

	return (node);
}
