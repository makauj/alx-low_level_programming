#include "main.h"
/**
 * _strspn - get length of a prefix
 * @s: segment to be checked
 * @accept: segment used to check
 * Return: null
 */
unsigned int _strspn(char *s, char *accept)
{
	int i;
	int n;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (n = 0; s[i] != accept[n]; n++)
			if (accept[n] == '\0')
				return (i);
	}
	return (0);
}
