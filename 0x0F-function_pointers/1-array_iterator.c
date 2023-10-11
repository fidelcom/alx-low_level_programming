#include <stddef.h>

/**
 * array_iterator - function that executes a function given as a parameter
 * on each element of an array.
 * @array: array
 * @size: array size
 * @action: pointer to function
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array && action)
	{
		for (i = 0; i < size; i++)
		{
			action(*(array + i));
		}
	}
}
