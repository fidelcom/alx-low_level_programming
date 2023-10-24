#include "lists.h"

/**
 * count_nodes - count nodes to know unique nodes to print
 * @head: pointer to pointer of linked list
 * Return: number of unique nodes
 */
int count_nodes(const listint_t *head)
{
	int count = 0;
	const listint_t *turtle, *hare;

	turtle = hare = head;

	while (turtle && hare)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		count++;

		if (turtle == hare)
		{
			turtle = head;
			while (turtle != hare)
			{
				turtle = turtle->next;
				hare = hare->next;
				count++;
			}
			return (count);
		}
	}
	return (0);
}

/**
 * check_for_loop - check for a loop in linked list
 * @head: pointer to pointer of linked list
 * Return: 0 if no loop, 1 if loop
 */
int check_for_loop(const listint_t *head)
{
	const listint_t *turtle, *hare;

	turtle = hare = head;

	while (turtle && hare)
	{
		turtle = turtle->next;
		hare = hare->next->next;

		if (turtle == hare)
			return (1);
	}
	return (0);
}

/**
 * print_listint_safe - function that prints a linked list.
 * @head: pointer to head pointer of linked list
 * Return: number of nodes in list, exit(98) if failed
 */
size_t print_listint_safe(const listint_t *head)
{
	int count = 0;
	int present;
	size_t total_nodes = 0;
	const listint_t *temp;

	if (!head)
		exit(98);

	present = check_for_loop(head);

	if (present == 1)
	{
		count = count_nodes(head);
		for (present = 0; present < count; present++)
		{
			printf("[%p] %d\n", (void *)temp, temp->n);
			total_nodes += 1;
			temp = temp->next;
		}
	}
	else if (present == 0)
	{
		temp = head;
		while (temp)
		{
			printf("[%p] %d\n", (void *)temp, temp->n);
			total_nodes += 1;
			temp = temp->next;
		}
	}

	return (total_nodes);
}
