#include "main.h"

/**
 * leet - A fuction that encodes a string
 * @str: string to be encoded
 * Return: null
 */

char *leet(char *str)
{
	int i, j;
	char llet[] = "aeotl";
	char lnum[] = "43071i";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; llet[j] != '\0'; j++)
		{
			if (str[i] == llet[j] || str[i] == llet[j] - 32)
			{
				str[i] = lnum[j];
				break;
			}
		}
	}
	return (str);

}
