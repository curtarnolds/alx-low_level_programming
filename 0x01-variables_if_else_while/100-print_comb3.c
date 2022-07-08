#include <stdio.h>

/**
 * main - Entry
 * Return: Returns 0 upon success
 */

int main(void)
{
int num;
for (num = 0; num < 10; num++)
{
putchar(num + '0');
if (num == 9)
{
continue;
}
putchar(',');
putchar(' ');
}
putchar('\n');
return (0);
}
