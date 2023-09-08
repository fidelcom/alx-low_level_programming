#include <stdio.h>

/**
 *main - prints hexadecimal (base 16) 0123456789abcdef, using putchar
 *Return: Always 0
 */

int main(void)
{
	int i = '0';
	int alpha = 'a';

	while (i <= '9') /*print 0-9*/
	{
		putchar(i);
		i++;
	}

	while (alpha <= 'f') /*print a-f to finish hexbase*/
	{
		putchar(alpha);
		alpha++;
	}

	putchar('\n');

	return (0);
}
