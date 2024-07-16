#include "main.h"

/**
 * str_concat - concatenate two strings
 * @s1: String 1
 * @s2: Sreing 2
 * Return: concantenated string else NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	unsigned int i;
	unsigned int l1 = 0;
	unsigned int l2 = 0;
	char *concat_str;

	/* Treat NULL strings as empty strings */
	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	/* Calculate the length of the strings */
	while (s1[l1] != '\0')
	{
		l1++;
	}
	while (s2[l2] != '\0')
	{
		l2++;
	}
	concat_str = malloc((l1 + l2 + 1) * sizeof(char));/*Memmory allocation*/
	if (concat_str == NULL)
	{
		return (NULL); /* Return NULL if memory allocation fails */
	}
	/* Copy s1 and s2 to the concatenated string */
	for (i = 0; i < l1; i++)
	{
		concat_str[i] = s1[i];
	}
	for (i = 0; i < l2; i++)
	{
		concat_str[l1 + i] = s2[i];
	}
	concat_str[l1 + l2] = '\0';
	return (concat_str);
}
