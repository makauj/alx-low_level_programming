#include "main.h"
/**
 * malloc_checked - function allocates memory using malloc
 * @b: integer
 *
 * Return: pointer to allocated memory, else 98
 */
void *malloc_checked(unsigned int b)
{
	int *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);
	return (ptr);
}
