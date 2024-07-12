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
	int mul = 0;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	mul = atoi(argv[1]) * atoi(argv[2]);
	printf("%d\n", mul);
	return (0);
}
