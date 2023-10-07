#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * _realloc - function that reallocates a memory block using malloc and free
 * @ptr: pointer to previous memory allocated
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: size, in bytes of the new memory block
 * Return: return pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_p;
	unsigned char *old_ptr = (unsigned char *)ptr;
	unsigned char *new_ptr;
	unsigned int i;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == old_size)
		return (ptr);
	new_p = malloc(new_size);
	new_ptr = (unsigned char *)new_p;

	if (!new_size)
		return (NULL);
	if (old_size < new_size)
		for (i = 0; i < new_size; i++)
			new_ptr[i] = old_ptr[i];
	else
		for (i = 0; i < old_size; i++)
			new_ptr[i] = old_ptr[i];
	free(ptr);
	return (new_ptr);
}
