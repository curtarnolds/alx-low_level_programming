#include "hash_tables.h"


/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to be deleted
*/
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node, *tmp;
	unsigned long int i;

	if (ht == NULL)
		return;

	if (ht->array == NULL || ht->size == 0)
	{
		free(ht);
		return;
	}

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		if (node)
		{
			while (node)
			{
				tmp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tmp;
			}
		}
	}
	free(ht->array);
	free(ht);
}
