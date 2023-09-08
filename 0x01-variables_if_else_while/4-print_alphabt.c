#include <stdio.h>

/**
 *main - print lowercase alphabets a-z without 'q' and 'e'
 *Return: Always 0
 */

int main(void)
{
	char i = 'a';

	while (i <= 'z')
	{
		if ((i != 'q') && (i != 'e'))
		{
			putchar(i);
		}
		i++;
	}
	putchar('\n');

	return (0);
}
