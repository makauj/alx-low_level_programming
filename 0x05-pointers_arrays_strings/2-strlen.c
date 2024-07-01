#include "main.h"

/**
 * _strlen - function returning the length of a string
 * @s: char
 * Return: lenth of the string
 */
int _strlen(char *s)
{
	int len;
	int count = 0;

	for (len = 0; s[len] != '\0'; len++)
		count++;
	return (count);
}
