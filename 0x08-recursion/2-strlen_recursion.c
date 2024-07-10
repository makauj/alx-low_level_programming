#include "main.h"
/**
 * _strlen_recursion - return the length of a string
 * @s: String
 * Return: null
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);/*base case: end of string */
	/* Add 1 to current char & call recursively with next char */
	return (1 + _strlen_recursion(s + 1));
}
