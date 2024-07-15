#include "main.h"
#include <stdlib.h>
/**
 * create_array - Creates an array of chars, and initializes it
 * with a specific char
 * @size: unsigned int
 * @c: char to initialize array of chars
 * Return: NULL if size 0 or fails else pointer to array
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *s;

	if (size == 0)
	{
		return (NULL);
	}
	s = malloc(sizeof(char) * size);

	if (s == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		s[i] = c;
	}
	return (s);
}
