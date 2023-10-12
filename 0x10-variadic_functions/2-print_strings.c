#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - function that prints strings, followed by a new line.
 * @separator: string to be printed between the strings
 * @n: number of strings passed to the function
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list list;
	unsigned int i;
	char *s;

	if (n > 0)
	{
		va_start(list, n);
		for (i = 1; i <= n; i++)
		{
			s = va_arg(list, char *);
			if (s == NULL)
				printf("(nil)");
			else
				printf("%s", s);

			if (i != n && separator != NULL)
				printf("%s", separator);
		}
		va_end(list);
	}
	printf("\n");
}
