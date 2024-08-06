#include "lists.h"

/**
 * create_node - creates a new listint_t node
 * @n: integer value for the new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */

listint_t *create_node(int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
    {
        return NULL;
    }
    new_node->n = n;
    new_node->next = NULL;
    return new_node;
}

