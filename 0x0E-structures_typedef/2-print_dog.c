#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

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
/**
 * print_dog - function that prints struct dog
 * @d: pointer to struct dog
 *
 * Description: this function prints the struct dog
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	if (d->name == 0)
		printf("Name: (nil)\n");

	else
		printf("Name: %s\n", d->name);

	printf("Age: %.6f\n", d->age);

	if (d->owner == 0)
		printf("Owner: (nil)\n");

	else
		printf("Owner: %s\n", d->owner);
}
