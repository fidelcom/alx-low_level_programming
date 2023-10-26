#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int
 * @b: pointing to a string of 0 and 1 chars
 * Return: converted number, or 0
 */

unsigned int binary_to_uint(const char *b)
{

	int len = 0, pow = 1;

	unsigned int sum = 0, error = 0;

	if (!b)
		return (error);

	while (b[len] != '\0')
		len++;
	len -= 1;

	while (len >= 0)
	{
		if ((b[len] != '0') && (b[len] != '1'))
			return (error);

		if (b[len] == '1')
			sum += pow;

		pow *= 2;
		len--;
	}

	return (sum);
}
