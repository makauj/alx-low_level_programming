#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * init_dog - initializes a struct dog
 * @d: pointer to the struct dog to be initialized
 * @name: pointer to the name string
 * @age: the age of the dog
 * @owner: pointer to the owner's name string
 *
 * Description: This function initializes the members of the struct dog
 *              with the provided name, age, and owner.
 */
void init_dog(dog_t *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
/**
 * new_dog - main function
 * @name: pointer to the name of the dog
 * @age: age of the dog
 * @owner: pointer to the name of the dog's owner
 *
 * Description: This funcion creates a new dog
 * Return: Pointer to new struct, NULL if it fails
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d = malloc(sizeof(dog_t));

	if (d == NULL)
		return (NULL);

	d->name = malloc(strlen(name) + 1);

	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	strcpy(d->name, name);

	d->owner = malloc(strlen(owner) + 1);

	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	strcpy(d->owner, owner);

	d->age = age;

	return (d);
}
