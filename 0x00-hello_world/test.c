#include <stdio.h>
/**
* main - Entry point
* printf - This is a description
* Return: Always 0 (Success)
*/
int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float e;

	printf("Size of a char: %1d byte(s)\n", sizeof(a));
	printf("Size of an int: %u byte(s)\n", sizeof(b));
	printf("Size of a long int: %1d byte(s)\n", sizeof(c));
	printf("Size of a long long int: %11d byte(s)\n", sizeof(d));
	printf("Size of a float: %1d byte(s)\n", sizeof(e));
	return (0);
}
