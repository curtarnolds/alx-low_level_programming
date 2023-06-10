#include "hash_tables.h"


/**
 * hash_table_print - Print a hash table
 * @ht: a hash table
*/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;

	printf("{");
	if (ht == NULL)
		;
	else
	{
		for (i = 0; i < ht->size; i++)
		{
			node = ht->array[i];
			if (node == NULL)
				continue;

			while (node)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
			}
		}
	}
	printf("}\n");

}
