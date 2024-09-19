#include "lists.h"

/**
 * print_dlistint - function to find the length of a list
 * @h: pointer to header
 *
 * Return: count
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t count = 0;
	int len;
	char buffer[20];

	if (h == NULL)
	{
		return (0);
	}

	while (current)
	{
		len = int_to_str(current->n, buffer);
		current = current->next;
		count++;
		write(STDOUT_FILENO, buffer, len);
	}

	return (count);
}

/**
 * int_to_str - function to convert an integer to a string
 * @num: number
 * @buffer: pointer to memory
 *
 * Return: the converted string
 */

int int_to_str(int num, char *buffer)
{
	int len = 0, is_negative = 0, i;
	char temp;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	do{
		buffer[len++] = (num % 10) + '0';
		num /= 10;
	}while (num > 0);

	if (is_negative)
	{
		buffer[len++] = '-';
	}

	for (i = 0; i < len / 2; i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[len - 1 - i];
		buffer[len - 1 - i] = temp;
	}

	buffer[len] = '\n';

	return (len + 1);
}
