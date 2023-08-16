#include "main.h"
#include <stdio.h>

/**
 * print_times_table - Prints the n times table
 * @n: The value to determine the size of the times table
*/

void print_times_table(int n)
{
	int i;
	int j;
	int k;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				k = i * j;
				if (j > 0)
					printf(", ");

				printf("%3d", k);
			}
			printf("\n");
		}
	}
}
