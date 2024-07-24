#include "3-clac.h"

/**
 * get_op_func - function that selects the correct function
 * to perform the operation the user wants
 * @s: operator passed as arguement to program
 *
 * Return: nothing
 */

int (*get_op_func(char *s))(int, int)
{
	typedef int (*op_func)(int, int);

	int i = 0;
	op_func op_arr[] = {op_add, op_sub, op_mul, op_div, op_mod};
	char *op_str[] = {"+", "-", "*", "/", "%"};

	while (op_str[i] != NULL)
	{
		if (strcmp(s, op_str[i]))
		{
			return (op_arr[i]);
		}
		i++;
	}
	return (NULL);
}
