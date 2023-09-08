#include <stdio.h>

/**
 *main - print 0123456789 using putchar
 *Return: Always 0
 */

int main(void)
{
	int n;

	for (n = '0'; n <= '9'; n++)
	{
		putchar(n);
	}
	putchar('\n');
	return (0);
}
