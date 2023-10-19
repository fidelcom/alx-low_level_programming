#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* add_node -  function that adds a new node at the beginning of a list_t list.
* @head: linked list
* @str: string
* Return: linked list
*/

list_t *add_node(list_t **head, const char *str)
{
	char *ptr;
	list_t *list;
	unsigned int i;

	list = malloc(sizeof(list_t));
	if (list == NULL)
		return (NULL);
	ptr = strdup(str);
	for (i = 0; str[i] != '\0';)
		i += 1;

	list->str = ptr;
	list->next = *head;
	list->len = i;
	*head = list;
	return (*head);
}
