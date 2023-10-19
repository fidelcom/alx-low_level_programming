#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* free_list - function that frees a list_t list.
* @head: head of a linked list
*/

void free_list(list_t *head)
{
	list_t *ptr;

	while (head)
	{
		ptr = head;
		head = head->next;
		free(ptr->str);
		free(ptr);
	}

}
