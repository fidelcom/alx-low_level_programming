#include <stdio.h>

/**
 * main - print first 50 Fibonacci numbers
 * Return: 0
 */

int main(void)
{
	int count;
	unsigned long x, y, z;

	x = 0;
	y = 1;

	for (count = 1; count <= 49; count++)
	{
		z = x + y;
		x = y;
		y = z;
		printf("%lu, ", z);
	}

	printf("%lu\n", z + x);
	return (0);
}
