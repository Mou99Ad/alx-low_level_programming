#include <stdio.h>

/**
* main - Entry point
* Description: prints all possible different combinations of 2 digits
* Return: Always 0 (Success)
*/

int main(void)
{
	int num1, num2;

	/** Iterate through the first digit */
	for (num1 = 0; num1 < 9; num1++)
	{
		/** Iterate through the second digit (different from the first) */
		for (num2 = num1 + 1; num2 <= 9; num2++)
		{
			/** Print the 2 digits */
			putchar(num1 + '0');
			putchar(num2 + '0');

			/** Print comma and space if not the last combination */
			if (num1 != 8 || num2 != 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}
