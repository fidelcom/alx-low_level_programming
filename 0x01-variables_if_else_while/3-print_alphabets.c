#include <stdio.h>

/**
 *main - print lowercase and uppercase alphabets a-zA-Z using putchar
 *Return: Always 0
 */

int main(void)
{
	char lower_case = 'a';
	char upper_case = 'A';

	while (lower_case <= 'z') /*print lowercases a-z*/
	{
		putchar(lower_case);
		lower_case++;
	}

	while (upper_case <= 'Z') /*print uppercase A-Z*/
	{
		putchar(upper_case);
		upper_case++;
	}

	putchar('\n');

	return (0);
}
