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
	printf("Debug: ht created\n");
    shash_table_set(ht, "y", "0");
	printf("Debug: set 1\n");
    shash_table_print(ht);
	printf("Debug: print 1\n");
    shash_table_set(ht, "j", "1");
	printf("Debug: set 2\n");
    shash_table_print(ht);
	printf("Debug: print 2");
    shash_table_set(ht, "c", "2");
	printf("Debug");
    shash_table_print(ht);
	printf("Debug");
    shash_table_set(ht, "b", "3");
	printf("Debug");
    shash_table_print(ht);
	printf("Debug");
    shash_table_set(ht, "z", "4");
	printf("Debug");
    shash_table_print(ht);
	printf("Debug");
    shash_table_set(ht, "n", "5");
	printf("Debug");
    shash_table_print(ht);
	printf("Debug");
    shash_table_set(ht, "a", "6");
	printf("Debug");
    shash_table_print(ht);
	printf("Debug");


    return (EXIT_SUCCESS);
}
