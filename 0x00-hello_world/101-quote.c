#include <stdio.h>
#include <unistd.h>

/**
 * main - Code goes here
 *
 * Return = 1
 *
 * File descriptor number associated with sterr = 2
 * 2 is used to identify the stream when a program writes to stderr
 *
 * Add length of the string as the final arguement
 */
int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);
}
