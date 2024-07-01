#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * main - entry point
 * Description: generate random string that can be used as a password
 * Return: null
 */

int main(void)
{
	int n;
	int l;
	int k;
	time_t t;

	srand((unsigned int) time(&t));
	while (n < 2772)
	{
		l = rand() % 128;
		if ((n + l) > 2772)
			break;
		n += l;
		k++;
		printf("%c", l);
	}
	printf("%c\n", (2772 - n));
	return (0);
}
