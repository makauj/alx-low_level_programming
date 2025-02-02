#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp, *next_node;
	unsigned long int i = 0;

	if (!ht)
		return;

	while (i < ht->size)
	{
		temp = ht->array[i];
		while (temp)
		{
			next_node = temp->next;
			free(temp->value);
			free(temp->key);
			free(temp);
			temp = next_node;
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
