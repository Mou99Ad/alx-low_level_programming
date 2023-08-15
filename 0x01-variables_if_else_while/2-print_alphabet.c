#include <stdio.h>
/**
* main - Entry main point
* Description: This function prints alphabets in lowercase
* Return: Always 0 (Success)
*/

int main(void)
{
	char ch;

	for  (ch = 'a'; ch <= 'z'; ch++)
	{
	putchar(ch);
	}
	putchar('\n'); /** to print a new line */
	return (0);
}
