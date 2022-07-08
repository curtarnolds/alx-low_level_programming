#include <stdio.h>

/**
 * main - Entry point of the program
 * Return: returns 0 upon success
 */

int main(void)
{
int x, y;
for (x = 0; x < 9; x++)
{
for (y = 1; y <= 9; y++)
{
if (y > x)
{
putchar(x + '0');
putchar(y + '0');
if (y == 9 && x == 8)
{
break;
}
putchar(',');
putchar(' ');
}
}
}
putchar('\n');
return (0);
}
