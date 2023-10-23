#include "lists.h"

/**
 * sum_listint - function that return sum of all data in linked list
 * @head: pointer to pointer of linked list
 * Return: sum, or 0 if list is empty
 */

int sum_listint(listint_t *head)
{

	int result = 0;

	while (head)
	{
		result += head->n;
		head = head->next;
	}

	return (result);
}
