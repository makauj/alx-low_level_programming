#include "dog.h"

/**
 * init_dog - function to initialize struct dog
 * @d: pointer to the struct to be initialized
 * @name: pointer to the name of the dog
 * @age: age of the dog
 * @owner: pointer to the name of the dog's owner
 *
 * Description: This funcion initializes struct dog stored in dog.h
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != 0)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
