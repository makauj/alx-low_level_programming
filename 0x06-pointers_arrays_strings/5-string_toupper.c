#include "main.h"

/**
 * string_toupper - Changes all lowercase letters to uppercase in a string
 * @str: string
 * Return: null
 */
char *string_toupper(char *str)
{
	int c;

	for (c = 0; str[c] != '\0' ; c++)
		if (str[c] >= 'a' && str[c] <= 'z')
			str[c] = str[c] - 32;
	return (str);
}
