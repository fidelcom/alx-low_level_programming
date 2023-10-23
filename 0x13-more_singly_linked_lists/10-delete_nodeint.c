#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at positio
 * index of a linked list.
 * @head: pointer to pointer of linked list
 * @index:  index of the node that should be deleted
 * Return: 1 if succeeded, or -1 if failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{

	unsigned int i = 0;
	listint_t *temp, *temp2;

	if (!*head)
		return (-1);

	temp = *head;

	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}

	while (i < (index - 1) && temp)
	{
		temp = temp->next;
		i++;
	}

	if (i != (index - 1) || !temp->next)
		return (-1);

	temp2 = temp->next;
	temp->next = (temp->next)->next;
	free(temp2);

	return (1);
}
