#include "main.h"

/**
 * _strncpy - entry point
 * @dest: destination of copy
 * @src: source of the copy
 * @n: length of the copy
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
