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
	size_t len;

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
		text_content = "";
	}
	len = _strlen(text_content);
	f_write = write(fd, text_content, len);
	if (f_write == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}

/**
 * _strlen - function to return the length of a string
 * @s: pointer to the string
 *
 * Return: length of the string s
 */

int _strlen(const char *s)
{
	int len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
