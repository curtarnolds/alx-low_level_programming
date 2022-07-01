#include <stdio.h>
/**
  * main - Entry point
  * Return: Always return 0 (success)
  */
int main(void)
{
int i;
long int ll;
long long int lll;
float f;
char c;

printf("Size of a char: %lu byte(s)\n", sizeof(c));
printf("Size of a int: %lu byte(s)\n", sizeof(i));
printf("Size of a long int: %lu byte(s)\n", sizeof(ll));
printf("Size of a long long int: %lu byte(s)\n", sizeof(lll));
printf("Size of a float: %lu byte(s)\n", sizeof(f));
return (0);
