#include "main.h"

/**
 * read_textfile - function that reads a file and prints to POSIX
 *
 * @filename: name of the file to be read
 * @letters: number of letters read and to be printed
 *
 * Return: the number of letters else 0 if file can't be opened
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_d;
	ssize_t bytes_r, bytes_w;
	char *buffer;

	if (filename == NULL)
	{
		return (0);
	}
	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
	{
		return (0);
	}
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file_d);
		return (0);
	}
	bytes_r = read(file_d, buffer, letters);
	if (bytes_r == -1)
	{
		free(buffer);
		close(file_d);
		return (0);
	}
	bytes_w = write(STDOUT_FILENO, buffer, bytes_r);
	if (bytes_w == -1 || bytes_w != bytes_r)
	{
		free(buffer);
		close(file_d);
		return (0);
	}

	free(buffer);
	close(file_d);
	return (bytes_w);
}
