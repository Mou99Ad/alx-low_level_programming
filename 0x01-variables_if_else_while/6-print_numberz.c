#include <stdio.h>
/**
* main - Entry point
* Description: Prints single-digit numbers from 0 to 9 using putchar
* Return: Always 0 (Success)
*/

int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(i + '0'); /** Convert the integer value of 'i' to its ASCII character representation and print */
	}
	putchar('\n');
	return (0);
	}
