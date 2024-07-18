#include "main.h"

/**
 * _calloc - function that allocates memory for an array
 * @nmemb: no. of elements in array ptr[]
 * @size: size of element nmemb
 *
 * Return: pointer to allocated memory else NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *arr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	arr = calloc(nmemb, size);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
