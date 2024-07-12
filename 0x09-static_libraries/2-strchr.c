#include "main.h"
/**
 * _strchr - locate character in a string
 * @s: the string
 * @c: character to be located
 * Return: first occurence of character c else Null
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}
