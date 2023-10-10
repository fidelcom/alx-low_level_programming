#ifndef DOG_H
#define DOG_H


/**
 * dog_t - data type dog_t made with typedef
 */
typedef struct dog dog_t;

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

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
/**dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
*/

#endif
