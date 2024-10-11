#include "hash_tables.h"

/**
 * add_node - function that adds a new node
 * @key: key
 * @value: value
 *
 * Return: new node if successful else NULL
 */

hash_node_t *add_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	return (new_node);
}

/**
 * hash_table_set - Adds elements to a hash table
 * @ht: hash table you want to add the value to
 * @key: key
 * @value: value associated with the key
 *
 * Return: 1 on success else 0
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_table_t *arr, *tmp;
	unsigned long int idx;
	hash_node_t *node;

	if (key == NULL || key[0] == '\n')
		return (0);
	if (!ht || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	arr = ht->array;

	tmp = arr[idx];
	while (tmp != NULL)
	{
		if (strcmp(key, tmp->key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}

	/* Create a new node */
	node = add_node(key, value);
	if (!node)
	{
		return (0);
	}
	if (arr[idx])
	{
		node->next = arr[idx];
		arr[idx] = node;
	}

	return (1);
}
