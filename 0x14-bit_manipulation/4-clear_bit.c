#include "main.h"

/**
 * clear_bit - function that sets the value of a bit to 0 at a given index.
 * @n: number
 * @index: index
 * Return: 1 if success, or -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int max;
	unsigned long int bin = 1;

	max = (sizeof(unsigned long int) * 8);
	if (index > max)
		return (-1);

	bin = ~(bin << index);
	*n = (*n & bin);

	return (1);
}
