#include "hash_tables.h"

/**
 * hash_table_get - retrieves  avalue associated with a key
 * @ht: hash table you want to look into
 * @key: key
 *
 * Return: value associated with the element or NULL if key is NULL
 */.

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_table_t *array, *tmp;
	unsigned long int index;

	if (!key || !ht)
	{
		return (NULL);
	}

	index = key_index((const unsigned char *)key, table->size);
	array = table->array;

	tmp = array[index];
	while (tmp)
	{
		if (strcmp(key, tmp->key) == 0)
		{
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
