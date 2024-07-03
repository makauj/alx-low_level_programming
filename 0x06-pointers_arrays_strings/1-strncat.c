#include <string.h>
/**
 * _strncat - Concatenate two strings to a specified length
 * @dest: Destination
 * @src: Source
 * @n: length of the string
 * Return: null
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int len = 0;

	while (dest[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}
