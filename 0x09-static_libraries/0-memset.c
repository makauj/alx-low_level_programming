#include "main.h"
/**
 * _memset - fills memory with a constant byte
 * @s: Points to the buffer to be set
 * @b: Is the value to be set
 * @n: Is the number of bytes to be set
 * Return: to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
