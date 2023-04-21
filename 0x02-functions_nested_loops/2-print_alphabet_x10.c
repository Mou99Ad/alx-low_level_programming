#include "main.h"
/**
* print_alphabet_x10 - a function that prints x10 the lowercase alphabet
*
* Return: Always 0 (Success)
*/

void print_alphabet_x10(void)
{
	char letter;
	int i;

	for (letter = 1; i <= 10; i++)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
		{
			_putchar(letter);
		}
		_putchar('\n');
	}
}
