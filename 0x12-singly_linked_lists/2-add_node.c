#include "lists.h"

/**
 * add_node - add a new node to a linked list
 * @head: pointer to a pointer to the head
 * @str: string to be added to linked list
 *
 * Return: pointer to the new node else NULL
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *new_str;

	new_node = (list_t *)malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_str = strdup(str);

	if (new_str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->str = new_str;
	new_node->len = strlen(str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
