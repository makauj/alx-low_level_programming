#include "main.h"
#include <stdlib.h>
/**
 * main - main function
 * @argc: number of command line arguements
 * @argv: An array containing the program command line arguments
 * Return: null
 */

int main(int argc, char *argv[])
{
	int i, j, add = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (1);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}
			add += atoi(argv[i]);
	}
	printf("%d\n", add);
	return (0);
}
