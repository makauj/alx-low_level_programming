#include "dog.h"
#include <stdlib.h>
/**
 * free_dog - function that frees memory
 * @d: integer
 *
 * Return: 0 else NULL
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
