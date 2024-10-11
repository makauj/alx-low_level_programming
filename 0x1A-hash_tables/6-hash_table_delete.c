#include "hash_tables.h"

/**
 * hash_tables_delete - deletes a hash table
 * @ht: hash table
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp;
	int i = 0;

	if (!ht)
	{
		return;
	}

	while (i < ht->size)
	{
		temp = ht->array[i];
		while (temp)
		{
			temp = temp->next;
			free(temp->value);
			free(temp->key);
			free(temp);
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
