#include "hash_tables.h"

/**
 * hash_table_get - retrieves  avalue associated with a key
 * @ht: hash table you want to look into
 * @key: key
 *
 * Return: value associated with the element or NULL if key is NULL
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *temp;
	unsigned long int index;

	if (!key || !ht)
	{
		return (NULL);
	}

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(key, temp->key) == 0)
		{
			return (temp->value);
		}
		temp = temp->next;
	}
	return (NULL);
}
