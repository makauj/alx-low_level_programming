#include "main.h"
/**
 * _strpbrk - search a string for any of a set of bytes
 * @s: String
 * @accept: String
 * Return: null
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		const char *a = accept;

		while (*a != '\0')
		{
			if (*s == *a)
			{
				return (s);
			}
			a++;
		}
		s++;
	}
	return (NULL);
}
