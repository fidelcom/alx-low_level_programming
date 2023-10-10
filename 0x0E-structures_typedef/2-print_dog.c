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

	printf("Name: %s\n", (d->name == NULL) ? (nil) : d->name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", (!d->owner) ? (nil) : d->owner);
}

