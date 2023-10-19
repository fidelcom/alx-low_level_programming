#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* list_len - function that returns the number of elements
* in a linked list_t list.
* @h: struct linked list
* Return: number of elemrnt
*/

size_t list_len(const list_t *h)
{
	size_t num;

	num = 0;
	while (h)
	{
		h = h->next;
		num += 1;
	}

	return (num);
}
