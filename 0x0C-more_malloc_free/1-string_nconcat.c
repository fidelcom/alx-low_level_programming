#include "main.h"
#include <stdlib.h>

/**
 * string_length - function that get the lent of a string
 * @s: string litral
 * Return: string length
 */

unsigned int string_length(char *s)
{
	int i, len = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}
	return (len);
}

/**
 * string_nconcat - function that concatenates two strings.
 * @n: determine the if s2 should be concatinanted
 * @s1: firt string litral
 * @s2: second string litral
 * Return: returned pointer shall point to a newly allocated space in memory
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	unsigned int i, j = 0, l1, l2;

	l1 = string_length(s1);
	l2 = string_length(s2);

	if (n < l2)
		p = malloc(sizeof(char) * (l1 + n + 1));
	else
		p = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!p)
		return (NULL);
	for (i = 0; i < l1; i++)
		p[i] = s1[i];
	while (n < l2 && i < (l1 + n))
		p[i++] = s2[j++];
	while (n >= l2 && i < (l1 + l2))
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}
