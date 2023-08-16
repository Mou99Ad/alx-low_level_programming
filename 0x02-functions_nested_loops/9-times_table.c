#include "main.h"
#include <stdio.h>

/**
 * times_table - Prints the 9 times table
 * Return: empty output
*/

void times_table(void)
{
	int row, column;

	for (row = 0; row <= 9; row++)
	{
		for (column = 0; column <= 9; column++)
		{
			int result = row * column;
			printf("%2d", result);

			if (column != 9)
				printf(", ");
			else
				printf("\n");
		}
	}
}
