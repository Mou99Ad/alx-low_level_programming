#include "main.h"
#include <stdio.h>

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The value for which the times table should be printed.
*/

void print_times_table(int n)
{
	if (n < 0 || n > 15)
		return;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			int result = i * j;

			if (j != 0)
				printf(", ");

			if (result < 10)
				printf("   %d", result);
			else if (result < 100)
				printf("  %d", result);
			else
				printf(" %d", result);
		}
		printf("\n");
	}
}
