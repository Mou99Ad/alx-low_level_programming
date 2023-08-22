#include "main.h"

/**
 * print_diagonal - prints a diagonal line of backslashes.
 * @n: The number of times the character '\' should be printed.
*/

void print_diagonal(int n)
{
	int spaces, i;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (spaces = 0; spaces < n; spaces++)
	{
		for (i = 0; i < spaces; i++)
		{
			_putchar(' ');
		}
		_putchar('\\');
		_putchar('\n');
	}
}
