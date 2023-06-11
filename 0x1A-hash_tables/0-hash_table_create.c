#include "hash_tables.h"


/**
 * hash_table_create - Creates a hash table
 * @size: The size of the hash table
 * Return: Pointer to the newly created hash table
 *
 * If something went wrong, the function will return NULL
*/
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *new_table;

	new_table = (hash_table_t *) malloc(sizeof(hash_table_t));
	if (new_table == NULL)
		return (NULL);

	new_table->size = size;

	new_table->array = (hash_node_t **) calloc(
		new_table->size, sizeof(hash_node_t *));
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	for (i = 0; i < new_table->size; i++)
		new_table->array[i] = NULL;

	return (new_table);
}
