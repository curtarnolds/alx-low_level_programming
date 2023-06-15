#include "hash_tables.h"


/**
 * shash_table_create - Creates a sorted hash table
 * @size: Size of the sorted hash table
 * Return: Pointer to a sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *new_table;

	new_table = (shash_table_t *) malloc(sizeof(shash_table_t *));

	new_table->size = size;
	if (new_table == NULL)
		return (NULL);

	new_table->array = (shash_node_t **) calloc(new_table->size, sizeof(shash_node_t *));
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	for (i = 0; i < new_table->size; i++)
		new_table->array[i] = NULL;

	new_table->shead = NULL;
	new_table->stail = NULL;

	return (new_table);
}


/**
 * shash_table_set - Adds an element to the hash table
 * @ht: The sorted hash table to update
 * @key: The key. (cannot be an empty string)
 * @value: The value associated with the key.
 * Return: 1 on success. 0 otherwise
 *
 * In case of collision, a new node is added at the beginning of the list
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	char *value_copy, *key_copy;
	shash_node_t *node, *new_node, *snode, *stmp;
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *) key, ht->size);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	node = ht->array[index];

	if (node)
	{
		while (node)
		{
			if (strcmp(key, node->key) == 0)
			{
				free(node->value);
				node->value = value_copy;
			}
			node = node->next;
		}
	}
	else
	{
		key_copy = strdup(key);
		if (key_copy == NULL)
		{
			free(value_copy);
			return (0);
		}

		new_node = (shash_node_t *) malloc(sizeof(shash_node_t));
		if (new_node == NULL)
		{
			free(key_copy);
			free(value_copy);
			return (0);
		}

		new_node->key = key_copy;
		new_node->value = value_copy;
		new_node->next = ht->array[index];
		ht->array[index] = new_node;
	}

	if (ht->shead)
	{
		if (strcmp(new_node->key, ht->shead->key) < 0)
		{
			ht->shead->sprev = new_node;
			new_node->snext = ht->shead;
			new_node->sprev =  NULL;
			ht->shead = new_node;
		}
		else
		{
			snode = ht->shead;
			while (snode)
			{
				if (strcmp(new_node->key, snode->key) < 0)
				{
					snode->sprev = new_node;
					new_node->snext = snode;
					new_node->sprev =  snode->sprev;
					snode->sprev->snext = new_node;

					break;
				}
				stmp = snode;
				snode = snode->snext;
			}
			if (snode == NULL)
			{
				new_node->snext = NULL;
				new_node->sprev =  stmp;
				stmp->snext = new_node;
				ht->stail = new_node;
			}
		}
	}
	else
	{
		new_node->snext = NULL;
		new_node->sprev = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	return (1);
}


/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key you are looking for
 * Return: The value associated with the element or NULL
 * if key couldn't be found
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL ||  key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *) key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->array[index];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}


/**
 * shash_table_print - Print a hash table
 * @ht: a hash table
*/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->shead;
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->snext)
			printf(", ");
		node = node->snext;
	}
	printf("}\n");
}



void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->stail;
	while (node)
	{
		printf("  '%s': '%s'", node->key, node->value);
		if (node->sprev)
			printf(", ");
		node = node->sprev;
	}
	printf("}\n");
}

void shash_table_delete(shash_table_t *ht);
