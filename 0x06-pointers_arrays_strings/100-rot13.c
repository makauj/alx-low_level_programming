#include "main.h"

/**
 * rot13 - encodde a string using rot13
 * @str: string to be encoded
 * Return: null
 */
char *rot13(char *str)
{
	int i, j;
	char la[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char lb[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; la[j] != '\0'; j++)
		{
			if (str[i] == la[j])
			{
				str[i] = lb[j];
				break;
			}
		}
	}
	return (str);
}
