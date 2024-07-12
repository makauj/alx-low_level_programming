#include <stdio.h>
#include <stdlib.h>
/**
 * main - main function
 * @argc: number of command line arguements
 * @argv: An array containing the program command line arguments
 * Return: null
 */

int main(int argc, char *argv[])
{
	if (argc > 0)
	{
		char *i = argv[0];

		while (*i != '\0')
		{
			_putchar(*i);
			i++;
		}
		_putchar('\n');
	}
	return (0);
}
