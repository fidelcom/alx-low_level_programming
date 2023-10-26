#include "main.h"
#include <stdio.h>
/**
 * print_binary - function that prints the binary representation of a number.
 * @n: unsigned int
 * Return: binary
 */
void print_binary(unsigned long int n)
{

	unsigned long int num = n, shift = 1;
	int len = 0;

	while (num > 0)
	{
		len++;
		num >>= 1;
	}
	len -= 1;

	if (len > 0)
		shift = shift << len;

	while (shift > 0)
	{
		if (n & shift)
			_putchar('1');
		else
			_putchar('0');

		shift >>= 1;
	}
}
