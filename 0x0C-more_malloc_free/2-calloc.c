#include "main.h"
#include <stdlib.h>

/**
 * _calloc - function that allocates memory for an array, using malloc
 * @nmemb: size
 * @size: size of data type
 * Return: returns a pointer to the allocated memory.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;
	unsigned int total_size, i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	total_size = nmemb * size;
	p = malloc(total_size);

	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < total_size; i++)
	{
		*((char *)p + 1) = 0;
	}

	return (p);
}
