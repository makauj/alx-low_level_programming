#include "main.h"

/**
 * _strdup -  function that returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string given as a parameter
 * @str: string
 * Return: pointer to duplicated string, else NULL
 */

char *_strdup(char *str)
{
	unsigned int l = 0;
	unsigned int i = 0;
	char *strDup;

	if (str == NULL)
		return (NULL);

	while (str[l] != '\0')
		l++;

	strDup = malloc((l + 1) * sizeof(char));

	if (strDup == NULL)
		return (NULL);

	for (i = 0; i <= l; i++)
		strDup[i] = str[i];

	return (strDup);
}
