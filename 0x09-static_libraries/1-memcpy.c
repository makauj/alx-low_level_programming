#include "main.h"
/**
 * _memcpy - copy memory area
 * @dest: copy to this area
 * @src: copy from this area
 * @n: bytes to be copied
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);

}
