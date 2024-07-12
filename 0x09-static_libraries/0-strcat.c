#include "main.h"
#include <string.h>

/**
 * _strcat - a function that concatenates 2 strings
 * @dest: destination of the string
 * @src: source
 * Return: null
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j = strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i + j] = src[i];
	}
	dest[i + j] = '\0';
	return (dest);
}
