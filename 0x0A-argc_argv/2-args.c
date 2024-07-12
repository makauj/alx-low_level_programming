#include "main.h"
/**
 * main - main function
 * @argc: number of command line arguements
 * @argv: An array containing the program command line arguments
 * Return: null
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
