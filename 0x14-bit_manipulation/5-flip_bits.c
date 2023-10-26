#include "main.h"

/**
 * flip_bits -  function that returns the number of bits you would
 * need to flip to get from one number to another.
 * @n: number
 * @m: number2
 * Return: number of bits that differ
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int diff = 0;
	unsigned long int differ;

	differ = n ^ m;

	do {
		diff += (differ & 1);
		differ >>= 1;
	} while
		(differ > 0);

	return (diff);
}
