#include "lists.h"

/**
 * print_list - function that prints all the elements of a list
 * @h: pointer to the head
 *
 * Return: number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;
	const char *nil_str = "(nil)";
	unsigned int i;

	while (h != NULL)
	{
		putchar('[');
		print_number(h->len);
		putchar(']');
		putchar(' ');

		if (h->str == NULL)
		{
			for (i = 0; nil_str[i] != '\0'; i++)
			{
				putchar(nil_str[i]);
			}
		}
		else
		{
			for (i = 0; i < h->len; i++)
			{
				putchar(h->str[i]);
			}
		}
		putchar('\n');
		count++;
		h = h->next;
	}
	return (count);
}

/**
 * print_number - function to print an unsigned integer
 * @n: the number to be printed
 */
void print_number(unsigned int n)
{
	if (n / 10)
	{
		print_number(n / 10);
	}
	putchar((n % 10) + '0');
}

/**
 * add_node - function to add a new node to a linked list
 * @head: pointer to a pointer to the head of the list
 * @str: string to be added to the list
 *
 * Return: pointer to the new node
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *error_msg1 = "Failed to allocate memory for new node.\n";
	char *error_msg2 = "Failed to allocate memory for new node string.\n";
	int i;

	new_node = (list_t *)malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		for (i = 0; error_msg1[i] != '\0'; i++)
		{
			putchar(error_msg1[i]);
		}
		exit(1);
	}

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		for (i = 0; error_msg2[i] != '\0'; i++)
		{
			putchar(error_msg2[i]);
		}
		exit(1);
	}

	new_node->len = strlen(str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

