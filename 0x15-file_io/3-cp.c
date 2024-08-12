#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_exit - prints an error message and exits
 * @code: Exit code
 * @message: message to print
 * @arg: Additional arguments
 */

void error_exit(const char *message, int code, const char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

/**
 * main - check the code for Holberton School students.
 *
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		error_exit(97, "Usage: cp file_from file_to", NULL);
	}
	file_from = open_file(argv[1], O_RDONLY, 0);
	file_to = open_file(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	copy_file(file_from, file_to);

	close_file(file_from);
	close_file(file_to);

	return (0);
}

/**
 * open_file - Opens a file and handles errors.
 * @filename: The name of the file to open.
 * @flags: The flags to use when opening the file.
 * @mode: The mode to use if the file is created (for output file).
 *
 * Return: The file descriptor on success, or exits on failure.
 */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd;

	fd = open(filename, flags, mode);
	if (fd == -1)
	{
	if (flags & O_WRONLY)
		error_exit(99, "Error: Can't write to %s\n", filename);
	else
		error_exit(98, "Error: Can't read from file %s\n", filename);
	}
	return (fd);
}

/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to close.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		error_exit(100, "Error: Can't close fd %d\n", fd);
	}
}

/**
 * copy_file - Copies content from one file to another.
 * @file_from: The file descriptor of the source file.
 * @file_to: The file descriptor of the destination file.
 */
void copy_file(int file_from, int file_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close_file(file_from);
			close_file(file_to);
			error_exit(99, "Error: Can't write to file\n", NULL);
		}
	}

	if (bytes_read == -1)
	{
		close_file(file_from);
		close_file(file_to);
		error_exit(98, "Error: Can't read from file\n", NULL);
	}
}


