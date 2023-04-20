#include <stdio.h>
/**
* main - Entry point
*
* Description : This function prints alphabets in lowercase, then in uppercase
*
* Return: Always 0 (Success)
*/

int main(void)
{
	char ch;

	for  (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
	}
