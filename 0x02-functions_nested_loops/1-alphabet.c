#include <main.h>
/**
* main - Entry point
*
* Description : This function prints alphabets in lowercase, then in uppercase
*
* Return: Always 0 (Success)
*/

void print_alphabet(void);
{
	char ch;

	for  (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
	}
