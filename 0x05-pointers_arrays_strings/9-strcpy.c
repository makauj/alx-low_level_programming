#include "main.h"

/**
 * _strcpy - copy string pointed to by src
 * @dest: return pointer value to here
 * @src: point to string
 * Return: dest pointer
 */

char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}

