#include <stdio.h>

/**
 *main - print 00 to 99 with no duplicate digits or combos
 *
 *Return: Always 0
 */

int main(void)
{
	int i;
	int j;

	for (j = '0'; j <= '9'; j++) /*increment j*/
	{
		for (i = (j + 1); i <= '9'; i++) /*i gotten by adding 1 to j value j+1*/
		{
			putchar(j);
			putchar(i);

			if (j != '8' || i != '9') /*print commas*/
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
