#include <stdio.h>
#include <unistd.h>
/**
 * main - Prints out the last part of a quote in stderr
 *
 * Return: 1 (success)
 */
int main(void)
{
	/**
	 * write function calls three arguements
	 * 1. the file descriptor for stderr (2)
	 * 2. the string in quotes
	 * 3. length of the string (59 in this case)
	 * Remember to exit special characters
	 * add \n to add new line
	 */
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);
}
