#include <stdio.h>
/**
* main - Entry main point
* Description: Prints lowercase alphabet excluding the letters 'q' and 'e'
* Return: Always 0 (Success)
*/

int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		if (ch != 'q' && ch != 'e')
		{
		putchar(ch);
		}
	}
	putchar('\n');
	return (0);
}
