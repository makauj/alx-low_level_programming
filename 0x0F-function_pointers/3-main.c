#include "3-calc.h"

/**
 * main - main function
 * @argc: number of arguements
 * @argv: arguement variables passed
 * Return: null
 */

int main(int argc, char *argv[])
{
	int a, b, res;
	int (*op)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}
	if (argv[2][1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	op = get_op_func(argv[2]);

	if (op == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	res = op(a, b);
	printf("%d\n", res);
	return (0);
}
