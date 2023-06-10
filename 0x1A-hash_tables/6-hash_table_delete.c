#include "hash_tables.h"


/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to be deleted
*/
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;

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
			hash_node_delete(node);
			free(node);
		}
	}
	free(ht->array);
	free(ht);
}



/**
 * hash_node_delete - Deletes a hash node
 * @node: The hash node to be deleted
*/
void hash_node_delete(hash_node_t *node)
{
	hash_node_t *current_node;

	current_node = node;
	if (current_node->next)
	{
		hash_node_delete(current_node->next);
		free(current_node->next);
	}
	free(current_node->key);
	free(current_node->value);
}
