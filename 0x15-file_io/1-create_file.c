#include "main.h"

/**
 * create_file - function that creates a file
 *
 * @filename: name of the file to be created
 * @text_content: text to be written to the created file
 *
 * Return: 1 on success else -1
 */

int create_file(const char *filename, char *text_content)
{
	int fd, i = 0;
	int f_write;

	if (filename == NULL)
	{
		return (-1);
	}

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (text_content == NULL)
	{
		text_content = "";
	}

	if (fd == -1)
	{
		return (-1);
	}
	while (text_content[i] != '\0')
	{
		f_write = write(fd, text_content, i);
		if (f_write == -1)
		{
			close(fd);
			return (-1);
		}
		i++
	}

	close(fd);
	return (1);
}
