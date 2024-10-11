#include "hash_tables.h"

/**
 * hash_table_print - prints hash table
 * @ht: hash table
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int flag = 1;
	hash_node_t *temp;

	if (!ht)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		if (!ht->array[i])
		{
			if (flag == 1)
			{
				printf(", ");
			}
			temp = ht->array[i];
			while (!temp)
			{
				printf("'%s': '%s'", temp->key, temp->value);
				temp = temp->next;
				if (temp)
				{
					printf(", ");
				}
			}
			flag = 1;
		}
	}
	printf("}\n");
}
