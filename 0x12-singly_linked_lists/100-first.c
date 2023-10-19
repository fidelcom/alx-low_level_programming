#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
void first_print(void) __attribute__((constructor));
/**
* first_print - function that prints before main is exectuted
*/

void first_print(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
