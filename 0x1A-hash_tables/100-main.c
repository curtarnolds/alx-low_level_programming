#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 *     shash_table_delete(ht);
 */
int main(void)
{
    shash_table_t *ht;

    ht = shash_table_create(1024);
    shash_table_set(ht, "y", "0");
    shash_table_print(ht);
	printf("char: y \t ascii: %d \t index: %lu\n", "y", key_index((const unsigned char *) "y", ht->size));
    shash_table_set(ht, "j", "1");
    shash_table_print(ht);
	printf("char: j \t ascii: %d \t index: %lu\n","j", key_index((const unsigned char *) "j", ht->size));
    shash_table_set(ht, "c", "2");
    shash_table_print(ht);
	printf("char: c \t ascii: %d \t index: %lu\n", "c", key_index((const unsigned char *) "c", ht->size));
    shash_table_set(ht, "b", "3");
    shash_table_print(ht);
	printf("char: b \t ascii: %d \t index: %lu\n","b", key_index((const unsigned char *) "b", ht->size));
    shash_table_set(ht, "z", "4");
    shash_table_print(ht);
	printf("char: z \t ascii: %d \t index: %lu\n","z", key_index((const unsigned char *) "z", ht->size));
    shash_table_set(ht, "n", "5");
    shash_table_print(ht);
	printf("char: n \t ascii: %d \t index: %lu\n","n", key_index((const unsigned char *) "n", ht->size));
    shash_table_set(ht, "a", "6");
    shash_table_print(ht);
	printf("char: a \t ascii: %d \t index: %lu\n","a", key_index((const unsigned char *) "a", ht->size));
    shash_table_set(ht, "m", "7");
    shash_table_print(ht);
	printf("char: m \t ascii: %d \t index: %lu\n","m", key_index((const unsigned char *) "m", ht->size));


    return (EXIT_SUCCESS);
}
