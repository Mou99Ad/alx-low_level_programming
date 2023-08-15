#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints all possible combinations of two two-digit numbers.
 *              Numbers are separated by a comma and space.
 * Return: Always 0 (Success)
*/

int main(void)
{
	int num1, num2;

	/** Iterate through the first two-digit number */
	for (num1 = 0; num1 <= 99; num1++)
	{
		/** Iterate through the second two-digit number (greater than the first) */
		for (num2 = num1 + 1; num2 <= 99; num2++)
		{
			/** Print the first two-digit number */
			putchar((num1 / 10) + '0');
			putchar((num1 % 10) + '0');
			putchar(' ');

			/** Print the second two-digit number */
			putchar((num2 / 10) + '0');
			putchar((num2 % 10) + '0');

			/** Print comma and space if not the last combination */
			if (num1 != 98 || num2 != 99)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}

	/** Print a new line character to separate output */
	putchar('\n');

	return (0);
}
