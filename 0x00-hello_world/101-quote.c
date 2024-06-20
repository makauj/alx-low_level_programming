#include <stdio.h>
#include <unistd.h>

/**
 * main - Will print last part of quote in case of error
 *
 * Return = 1 if success
 */
int main(void)/* Return value of 'main' */
{
	/**
	 * write requires three arguements
	 * 1. File descriptor number associated with stderr = 2
	 * 2. String inside ""
	 * 3. Total number of characters in the string (59 in this case)
	 */
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);
}
