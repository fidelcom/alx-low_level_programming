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
		len = len + 1;
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
	unsigned int i, j;

	if (n < string_length(s2))
		p = malloc(sizeof(char) * (string_length(s1) + n + 1));
	else
		p = malloc(sizeof(char) * (string_length(s1) + string_length(s2) + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i < string_length(s1); i++)
		p[i] = s1[i];
	for (j = 0; n < string_length(s2) && i < (string_length(s1) + n); j++)
		p[i++] = s2[j];
	p[i] = '\0';
	return (p);
}
