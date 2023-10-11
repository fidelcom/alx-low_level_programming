#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name -  function that prints a name.
 * @name: name to be printed
 * @f:pointer to function that print name
 *
 */

void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
	{
		f(name);
	}
}
