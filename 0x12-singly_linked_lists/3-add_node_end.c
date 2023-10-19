#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
* add_node_end - function that adds a new node at the end of a list_t list.
* @head: head of linked list
* @str: string
* Return:  address of the new element
*/

list_t *add_node_end(list_t **head, const char *str)
{
	unsigned int width;
	list_t *new_node;
	list_t *next_ptr;
	char *ptr;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	ptr = strdup(str);
	width = 0;

	while (str[width] != '\0')
		width += 1;

	new_node->str = ptr;
	new_node->len = width;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
		return (*head);
	}
	next_ptr = *head;

	while (next_ptr->next != NULL)
		next_ptr = next_ptr->next;

	next_ptr->next = new_node;
	return (*head);
}
