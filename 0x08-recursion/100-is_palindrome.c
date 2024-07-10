#include "main.h"

/**
 * is_palindrome_helper - recursively checks if s is a palindrome
 * @s: string
 * @start: start char
 * @end: end char
 * Return: palindrome
 */
int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
	{
		/**
		 * if the pointers have met or crossed,
		 * the string is a palindrome
		 */
		return (1);
	}
	if (s[start] != s[end])
	{
		/**
		 * if characters at start and end don't match,
		 * string is not a palindrome
		 */
		return (0);
	}
	/* move the pointers inward and recurse */
	return (is_palindrome_helper(s, start + 1, end - 1));
}
/**
 * _strlen_recursion - returns the length of a string
 * @s: string to calculate the length of
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	return (0);
	return (1 + _strlen_recursion(s + 1));
}
/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to reverse
 *
 * Return: 1 if it is, 0 it's not
 */

int is_palindrome(char *s)
{
	int l = _strlen_recursion(s);

	if (l == 0)
	{
		return (1);
	}
	return (is_palindrome_helper(s, 0, l - 1));
}
