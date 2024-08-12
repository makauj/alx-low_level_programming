#include "main.h"

/**
 * append_text_to_file - adds test to the end of a file
 * @filename: Name of the file
 * @text_content: string to be added to the file
 *
 * Return: 1 on success, else -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t f_write;

	if (!filename)
	{
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		return (-1);
	}
	if (!text_content)
	{
		close(fd);
		return (1);
	}

	f_write = write(fd, text_content, _strlen(text_content));
	if (f_write == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
