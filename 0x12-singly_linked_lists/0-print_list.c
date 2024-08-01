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
	char buffer[16];
	int len = h->len;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			write(STDOUT_FILENO, "[0] (nil)")
		}
		else
		{
			itoa(h->len, buffer, 10);
			write(STDOUT_FILENO, "[", 1);
			write(STDOUT_FILENO, buffer, strlen(buffer));
			write(STDOUT_FILENO, "] ", 2);
			write(STDOUT_FILENO, h->str, h->len);
			write(STDOUT_FILENO, "\n", 1);
		}
		count++;
		h = h->next;
	}
	return (count);
}

/**
 * add_node - function to add new node to linked list
 * @head: pointer to pointer to head
 * @liat_t:
 *
 * Return: pointer to new node
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = (list_t *)malloc(sizeof(list_t));

	if (new_node == NULL)
	{
		write(STDERR_FILENO, "Failed to allocate memory for new node.\n");
		exit(1);
	}

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		write(STDERR_FILENO, "Failed to allocate memory for new node string.\n");
		exit(1);
	}

	new_node->len = strlen(str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
