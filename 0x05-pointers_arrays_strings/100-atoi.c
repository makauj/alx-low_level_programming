#include "main.h"
/**
 * _atoi - entry point
 * Description: converts a string to an integer
 * @s: string to be converted
 * Return: null
 */
int _atoi(char *s)
{
	int r = 0;
	int sign = 1;
	int fn = 0;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s == '+')
		{

		}
		else if (*s >= '0' && *s <= '9')
		{
			fn = 1;
			r = r * 10 + (*s - '0');
		}
		else if (fn)
		{
			break;
		}
		s++;
	}
	return (sign * r);
}
