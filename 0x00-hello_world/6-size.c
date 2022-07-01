#include <stdio.h>
/**
  * main - Entry point
  * Return: Always return 0 (success)
  */
int main(void)
{
int integer;
long int long_int;
long long int longLong_int;
float _float;
char _char;

printf("Size of a char: %lu byte(s)\n", sizeof(_char));
printf("Size of a int: %lu byte(s)\n", sizeof(_int));
printf("Size of a long int: %lu byte(s)\n", sizeof(long_int));
printf("Size of a long long int: %lu byte(s)\n", sizeof(longLong_int));
printf("Size of a float: %lu byte(s)\n", sizeof(_float));
return (0);
