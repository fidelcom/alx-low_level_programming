#include "dog.h"
#include <stdio.h>

/**
 * print_dog - function that prints a struct dog
 * @d: use to identify a dog
 */

void print_dog(struct dog *d)
{
	if (!d)
	{
		return;
	}
	if (d->name == NULL)
	{
		printf("nil\n");
	}
	if (d->age < 0 || !d->age)
	{
		printf("nil\n");
	}
	if (d->owner == NULL)
	{
		printf("nill\n");
	}
	printf("Name: %s\nAge: %f\nOwner: %s\n", d->name, d->age, d->owner);
}

