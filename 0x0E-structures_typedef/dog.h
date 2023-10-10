#ifndef DOG_H
#define DOG_H

/**
 * struct dog - new data type struck
 * @name: dog name
 * @age: dog age
 * @owner: dog owner name
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - new data type of struct
 */

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
/**dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
*/

#endif
