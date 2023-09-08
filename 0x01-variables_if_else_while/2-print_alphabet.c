#include <stdio.h>

/**
 *main - print alphabet lowercase a-z
 *Return: Always 0
 */

int main(void)
{
	char alpha = 'a';

	while (alpha <= 'z')
	{
		putchar(alpha);
		alpha++;
	}
	putchar('\n');

	return (0);
}
