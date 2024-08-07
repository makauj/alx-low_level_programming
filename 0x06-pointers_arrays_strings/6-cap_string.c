#include "main.h"
#include <string.h>

/**
 * cap_string - Entry point
 * Description: This is a program that capitalizes all words of a string
 * @str: string
 * Return: null
 */

char *cap_string(char *str)
{
	int i = 1;

	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] = str[0] - 32;
	}
	while (str[i] != '\0')
	{
		if ((str[i - 1] == ' ' || str[i - 1] == '\t'
		     || str[i - 1] == '\n' || str[i - 1] == ',' || str[i - 1] == ';'
		     || str[i - 1] == '.' || str[i - 1] == '!' || str[i - 1] == '?'
		     || str[i - 1] == '"' || str[i - 1] == '(' || str[i - 1] == ')'
		     || str[i - 1] == '{' || str[i - 1] == '}')
		     && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
