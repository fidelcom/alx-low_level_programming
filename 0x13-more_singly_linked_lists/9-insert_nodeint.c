#include "lists.h"

/**
 * insert_nodeint_at_index -  function that inserts a new
 * node at a given position
 * @head: pointer to pointer of linked list
 * @idx:  index of the list where the new node should be added
 * @n: new node's data
 * Return: address of new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{

	unsigned int i = 0;
	listint_t *node, *temp;

	if (!head)
		return (NULL);

	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);
	node->n = n;

	if (idx == 0)
	{
		node->next = *head;
		*head = node;
		return (node);
	}

	temp = *head;
	while (i < (idx - 1))
	{
		temp = temp->next;
		i++;

		if (!temp)
		{
			free(node);
			return (NULL);
		}
	}

	node->next = temp->next;
	temp->next = node;
	return (node);
}
