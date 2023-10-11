#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * len - get length of string
 * @s: string
 * Return: length
 */
int len(char *s)
{
	int i;

	for (i = 0; *(s + i); i++)
		;
	return (i);
}
/**
 * _strcpy - function that copy string including (\0)
 * @dest: input string
 * @src: copied string
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i <= len(src); i++)
		dest[i] = src[i];
	return (dest);
}
/**
 * new_dog - function that creates a new dog.
 * @name:new  dog name
 * @age: new dog age
 * @owner: new dog owner
 * Return: new dog copy from struct dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *new_of_name;
	char *new_of_owner;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	new_dog->age = age;

	if (name != NULL)
	{
		new_of_name = malloc(len(name) + 1);
		if (new_of_name == NULL)
		{
			free(new_dog);
			return (NULL);
		}
		new_dog->name = _strcpy(new_of_name, name);
	}
	else
		new_dog->name = NULL;

	if (owner != NULL)
	{
		new_of_owner = malloc(len(owner) + 1);
		if (new_of_owner == NULL)
		{
			free(new_of_name);
			free(new_dog);
			return (NULL);
		}
		new_dog->owner = _strcpy(new_of_owner, owner);
	}
	else
		new_dog->owner = NULL;

	return (new_dog);
}
