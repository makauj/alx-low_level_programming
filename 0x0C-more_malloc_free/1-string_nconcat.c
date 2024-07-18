#include "main.h"

/**
 * string_nconcat - function concatenates 2 strings
 * @s1: 1st string
 * @s2: 2nd string
 * @n: length of s2
 *
 * Return: concatenated string else NULL
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j;
	unsigned int len1 = strlen(s1);
	unsigned int len2 = strlen(s2);
	char *conStr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (n >= len2)
		n = len2;
	if (len1 + n + 1 < len1)
		return (NULL)
	conStr = malloc(len1 + n + 1);
	if (conStr == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		conStr[i] = s1[i];
	for (j = 0; j < n; j++)
		conStr[len1 + j] = s2[j];
	conStr[len1 + n] = '\0';
	return (conStr);
}
