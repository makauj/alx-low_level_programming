#include "main.h"

/**
 * _strcmp - compare 2 strings
 * @s1: string 1
 * @s2: string 2
 * Return: i
 */
int _strcmp(char *s1, char *s2)
{
	for ( ; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
	{
		if (*s1 != *s2)
		{
			return (*s1 != *s2);
		}
		else if (*s1 == '\0' || *s2 == '\0')
			break;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s2 - *s1);
}
