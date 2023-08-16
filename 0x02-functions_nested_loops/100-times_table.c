#include "main.h"
#include <stdio.h>

/**
 * print_times_table - Prints the n times table
 * @n: The value to determine the size of the times table
*/

void print_times_table(int n)
{
	if (n < 0 || n > 15)
		return;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j > 0)
				printf(", ");

			printf("%3d", i * j);
		}
		printf("\n");
	}
}
