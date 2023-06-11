#include "hash_tables.h"


/**
 * hash_table_print - Print a hash table
 * @ht: a hash table
*/
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	int type_comma;

	if (ht == NULL)
		return;

	type_comma = False;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		if (node && type_comma == True)
			printf(", \n");
		while (node)
		{
			printf("  '%s': '%s'", node->key, node->value);
			if (node->next)
				printf(", ");
			node = node->next;
			type_comma = True;
		}
	}
	printf("}\n");
}
